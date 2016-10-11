//
// Created by lemmus on 2016/09/09.
//

#include "Manager.h"
#include "OPT/GenOPT/src/FIPS.h"
#include "OPT/GenOPT/src/GCPSO.h"

Manager::Manager() {
    setPkg = new SettingsPackage();
    snapMan = nullptr;
    optimizer = nullptr;
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

    setPkg->getProblemDomainSettingsPackage()->getBoundaries(bounds);
    if(bounds[0] == bounds[1] && bounds[1] == bounds[2] && bounds[2] == bounds[3])
    {
        objective->getBounds(bounds);
        graphicsProcessor->setBounds(bounds);
        setPkg->getProblemDomainSettingsPackage()->setBoundaries(bounds);
    }

    snapMan = new SnapshotManager(setPkg->getOptimizerSettingsPackage()->getMaxIterations(),
                                    setPkg->getSwarmSize(), setPkg->getProblemDomainSettingsPackage()->getDimensions(),
                                  bounds);
}

SnapshotManager *Manager::getSnapshotManager() {
    return snapMan;
}

SettingsPackage *Manager::getSettingsPackage() {
    return setPkg;
}

void Manager::initializeOptimizer() {
    std::string objFun = setPkg->getProblemDomainSettingsPackage()->getObjectiveFunction();
    double* trans = new double[4];
    setPkg->getProblemDomainSettingsPackage()->getTransformations(trans);
    if(objFun == "Sin")
        objective = new SinObjective(trans[0], trans[1], trans[2], trans[3]);
    else if(objFun == "Saddle")
        objective = new SaddleObjective(trans[0], trans[1], trans[2], trans[3]);
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


    graphicsProcessor = new GraphicsProcessor(*setPkg->getProblemDomainSettingsPackage());
    graphicsProcessor->setObjective(objective);

    std::string optAlg = setPkg->getOptimizerSettingsPackage()->getAlgorithm();
    if(optAlg == "Hill Climbing") {
        optimizer = new HillClimber(objective, snapMan, false, bounds);
    }
    else if(optAlg == "Particle Swarm Optimization")
        optimizer = new PSO(objective, snapMan, false, bounds);
    else if(optAlg == "Conical PSO")
        optimizer = new CPSO(objective, snapMan, false, setPkg->getOptimizerSettingsPackage()->getConstrictionCoefficient(), setPkg->getOptimizerSettingsPackage()->getMaxVelocity(), bounds);
    else if(optAlg == "Fully Informed PSO")
        optimizer = new FIPS(objective, snapMan, false,
                             setPkg->getOptimizerSettingsPackage()->getNeighbourhoodSize(), setPkg->getOptimizerSettingsPackage()->getConstrictionCoefficient(), bounds);
    else if(optAlg == "Guaranteed Convergence PSO")
        optimizer = new GCPSO(objective, snapMan, false, bounds, setPkg->getOptimizerSettingsPackage()->getSuccessCount(),
                setPkg->getOptimizerSettingsPackage()->getFailCount(), setPkg->getOptimizerSettingsPackage()->getConstrictionCoefficient());


    delete [] trans;
}

void Manager::optimize() {
    if(!optimizer) return;

    for(int i = 0; i < setPkg->getOptimizerSettingsPackage()->getMaxIterations(); ++i)
    {
        optimizer->iterate();
    }
    Particle* best = optimizer->getBestSolution();
    double bestPos[2];
    double current[2];
    best->getPersonalBestPosition(bestPos);
    best->getPositionArray(current);

    std::cout << "Best located solution is from particle at coords (" << current[0] <<","
              << current[1] << ") and has current fitness of: " << best->getFitnessValue() << "\n"
              << "Particle's best position was (" << bestPos[0] << ","
              << bestPos[1] << ") with fitness of: " << best->getPersonalBest() << std::endl;
}

GraphicsProcessor* Manager::getGraphicsProcessor()
{
    return graphicsProcessor;
}

