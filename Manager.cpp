//
// Created by lemmus on 2016/09/09.
//

#include "Manager.h"

Manager::Manager() {
    setPkg = new SettingsPackage();
    snapMan = nullptr;
    optimizer = nullptr;
    objective = nullptr;
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
    snapMan = new SnapshotManager(setPkg->getOptimizerSettingsPackage()->getMaxIterations(),
                                    setPkg->getSwarmSize(), setPkg->getProblemDomainSettingsPackage()->getDimensions());
}

SnapshotManager *Manager::getSnapshotManager() {
    return snapMan;
}

SettingsPackage *Manager::getSettingsPackage() {
    return setPkg;
}

void Manager::initializeOptimizer() {
    std::string objFun = setPkg->getProblemDomainSettingsPackage()->getObjectiveFunction();
    double* trans = new double[3];
    setPkg->getProblemDomainSettingsPackage()->getTransformations(trans);
    if(objFun == "Sin")
        objective = new SinObjective(trans[0], trans[1], trans[2]);
    else if(objFun == "Saddle")
        objective = new SaddleObjective(trans[0], trans[1], trans[2]);

    std::string optAlg = setPkg->getOptimizerSettingsPackage()->getAlgorithm();
    if(optAlg == "Hill Climbing")
        optimizer = new HillClimber(objective, snapMan, false);
    else if(optAlg == "Particle Swarm Optimization")
        optimizer = new PSO(objective, snapMan, false);
    else if(optAlg == "Conical PSO")
        optimizer = new CPSO(objective, snapMan, false, 5, 100); //what are these values? Have I specified them in GUI?
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
