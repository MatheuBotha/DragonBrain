//
// Created by lemmus on 2016/09/09.
//

#include "Manager.h"
#include "OPT/GenOPT/src/FIPS.h"
#include "OPT/GenOPT/src/GCPSO.h"
#include "OPT/GenOPT/src/ElitistHillClimber.h"
#include "OPT/GenOPT/src/GeneticAlgorithm.h"
#include "OPT/GenOPT/src/RandomSearch.h"

Manager::Manager() {
    setPkg = new SettingsPackage();
    snapMan = new SnapshotManager*[4];
    optimizer = new OPT_Process*[4];
    objective = nullptr;
    bounds = new double[4];
}

Manager::~Manager() {
    delete setPkg;
    if(snapMan != nullptr)
        delete snapMan;
    if(optimizer != nullptr)
        delete optimizer;
    if(objective != nullptr)
        delete objective;
}

void Manager::startGUI() {
    GUI_Thread = new std::thread(GUI_EXE::runGUI, std::ref(setPkg));


/* used for testing without GUI
 * setPkg->lock(false);
    OptimizerSettingsPackage* optPkg = setPkg->getOptimizerSettingsPackage();
    optPkg->setAlgorithm("Hill Climbing");
    optPkg->setMaxIterations(100);
    ProblemDomainSettingsPackage* probPkg = setPkg->getProblemDomainSettingsPackage();
    probPkg->setDimensions(2);
    probPkg->setObjectiveFunction("Saddle");
    setPkg->setSwarmSize(100);
    double trans[3] = {1,0,0};
    probPkg->setTransformations(trans);
*/
}

void Manager::endGUI() {
    if(GUI_Thread->joinable())
        GUI_Thread->join();
    delete GUI_Thread;
}

void Manager::generateSnapshotManager() {

    std::string objFun = setPkg->getProblemDomainSettingsPackage()->getObjectiveFunction();
    double* trans = new double[4];
    setPkg->getProblemDomainSettingsPackage()->getTransformations(trans);
    if(objFun == "Sin")
        objective = new SinObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Saddle")
        objective = new SaddleObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Ackley")
        objective = new AckleyObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Alpine")
        objective = new AlpineObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Beale")
        objective = new BealeObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Bohachevsky")
        objective = new BohachevskyObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "EggHolder")
        objective = new EggHolderObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "GoldSteinPrice")
        objective = new GoldSteinPriceObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Griewank")
        objective = new GriewankObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Levy13")
        objective = new Levy13Objective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Michalewicz")
        objective = new MichalewiczObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Pathological")
        objective = new PathologicalObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Quadric")
        objective = new QuadricObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Quartic")
        objective = new QuarticObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Rana")
        objective = new RanaObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Rastrigin")
        objective = new RastriginObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Rosenbrock")
        objective = new RosenbrockObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Salomon")
        objective = new SalomonObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Schwefel22")
        objective = new Schwefel22Objective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Schwefel26")
        objective = new Schwefel26Objective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "SixHumpCamelBack")
        objective = new SixHumpCamelBackObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "SkewRastrigin")
        objective = new SkewRastriginObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Spherical")
        objective = new SphericalObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Step")
        objective = new StepObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Weierstrass")
        objective = new WeierstrassObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Zakharov")
        objective = new ZakharovObjective(trans[0], trans[1], trans[2], trans[3]);
    delete [] trans;

    //graphicsProcessor = new GraphicsProcessor(*setPkg->getProblemDomainSettingsPackage());
   // graphicsProcessor->setObjective(objective);

    setPkg->getProblemDomainSettingsPackage()->getBoundaries(bounds);
    if(bounds[0] == bounds[1] && bounds[1] == bounds[2] && bounds[2] == bounds[3])
    {
        objective->getBounds(bounds);
//        graphicsProcessor->setBounds(bounds);
        setPkg->getProblemDomainSettingsPackage()->setBoundaries(bounds);
    }

    for(int i = 0; i < setPkg->getNumInstances(); ++i) {
        snapMan[i] = new SnapshotManager(setPkg->getOptimizerSettingsPackage()->getMaxIterations(),
                                         setPkg->getSwarmSize(),
                                         setPkg->getProblemDomainSettingsPackage()->getDimensions(),
                                         bounds);
    }
    for(int i = 1; i < setPkg->getNumInstances(); ++i)
    {
        snapMan[i]->enqueue( new Snapshot(snapMan[0]->getLast()) );
    }
}

SnapshotManager *Manager::getSnapshotManager() {
    return snapMan[0];
}

SettingsPackage *Manager::getSettingsPackage() {
    return setPkg;
}

void Manager::initializeOptimizer() {

    for(int i = 0; i < setPkg->getNumInstances(); ++i) {
        //+1 because getAlgorithm refers to algorithms labeled 1 to 4 (I've clearly used too many funny languages
        //recently, to actually start something at 1)
        std::string optAlg = setPkg->getOptimizerSettingsPackage()->getAlgorithm(i+1);
        if (optAlg == "Hill Climbing") {
            optimizer[i] = new HillClimber(objective, snapMan[i], false, bounds);
        } else if (optAlg == "Particle Swarm Optimization")
            optimizer[i] = new PSO(objective, snapMan[i], false, bounds,
                                   setPkg->getOptimizerSettingsPackage()->getSocialCoefficient(),
                                   setPkg->getOptimizerSettingsPackage()->getCognitiveCoefficient());
        else if (optAlg == "Conical PSO")
            optimizer[i] = new CPSO(objective, snapMan[i], false,
                                    setPkg->getOptimizerSettingsPackage()->getConstrictionCoefficient(),
                                    setPkg->getOptimizerSettingsPackage()->getMaxVelocity(),
                                    bounds, setPkg->getOptimizerSettingsPackage()->getSocialCoefficient(),
                                    setPkg->getOptimizerSettingsPackage()->getCognitiveCoefficient());
        else if (optAlg == "Fully Informed PSO")
            optimizer[i] = new FIPS(objective, snapMan[i], false,
                                    setPkg->getOptimizerSettingsPackage()->getNeighbourhoodSize(),
                                    setPkg->getOptimizerSettingsPackage()->getConstrictionCoefficient(),
                                    bounds, setPkg->getOptimizerSettingsPackage()->getSocialCoefficient(),
                                    setPkg->getOptimizerSettingsPackage()->getCognitiveCoefficient());
        else if (optAlg == "Guaranteed Convergence PSO")
            optimizer[i] = new GCPSO(objective, snapMan[i], false, bounds,
                                     setPkg->getOptimizerSettingsPackage()->getSuccessCount(),
                                     setPkg->getOptimizerSettingsPackage()->getFailCount(),
                                     setPkg->getOptimizerSettingsPackage()->getConstrictionCoefficient(),
                                     setPkg->getOptimizerSettingsPackage()->getSocialCoefficient(),
                                     setPkg->getOptimizerSettingsPackage()->getCognitiveCoefficient());
        else if (optAlg == "Elitist Hill Climbing")
            optimizer[i] = new ElitistHillClimber(objective, snapMan[i], false, bounds);
        else if (optAlg == "Genetic Algorithm")
            optimizer[i] = new GeneticAlgorithm(objective, snapMan[i], false, bounds);
//        else if (optAlg == "Random Search")
//            optimizer[i] = new RandomSearch(objective, snapMan[i], false, bounds);
    }
}

void Manager::optimize() {
    optThreads = new std::thread*[4];

    for(int i = 0; i < setPkg->getNumInstances(); i++)
    {
        optThreads[i] = new std::thread(&Manager::optimizeInstance, this, i);
    }

}


void Manager::waitForOpts() {
    for(int i = 0; i < setPkg->getNumInstances(); i++)
    {
        optThreads[i]->join();
    }
}
void Manager::optimizeInstance(void *instance, int i)
{
    Manager* mng = static_cast<Manager*>(instance);
    if(!mng->optimizer[i]) return;

    for(int j = 0; j < mng->setPkg->getOptimizerSettingsPackage()->getMaxIterations(); ++j)
    {
        mng->optimizer[i]->iterate();
    }
    Particle* best = mng->optimizer[i]->getBestSolution();
    double bestPos[2];
    double current[2];
    best->getPersonalBestPosition(bestPos);
    best->getPositionArray(current);

    //There's some small chance this output will get muddled with the other threads ofc. This is only for
    //testing anyway, it should be visualized in the end
    std::cout << "===============OPTIMIZER " << i << "===========================================\n";
    std::cout << "Best located solution is from particle at coords (" << current[0] <<","
              << current[1] << ") and has current fitness of: " << best->getFitnessValue() << "\n";

}

void Manager::initializeGraphicsProcessor()
{
    graphicsProcessor = new GraphicsProcessor(
            *setPkg->getProblemDomainSettingsPackage(),
            snapMan,
            setPkg->getGraphicsSettingsPackage()->getResolutionW(),
            setPkg->getGraphicsSettingsPackage()->getResolutionH(),
            60,//Animation Speed
            setPkg->getNumInstances()
    );
    graphicsProcessor->setObjective(objective);
}

void Manager::visualize() {
    graphicsProcessor->run();
    delete graphicsProcessor;
}

void Manager::cleanMemory() {
    for(int i = 0; i < setPkg->getNumInstances(); ++i)
    {
        delete optimizer[i];
        delete snapMan[i];
    }
}
