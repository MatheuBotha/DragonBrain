//
// Created by lemmus on 2016/09/09.
//

#include "Manager.h"

Manager::Manager() {
    setPkg = new SettingsPackage();
}

Manager::~Manager() {
    delete setPkg;
    if(snapMan)
        delete snapMan;
}

void Manager::startGUI() {
    GUI_Thread = new std::thread(GUI_EXE::runGUI, std::ref(setPkg));
}

void Manager::endGUI() {
    if(GUI_Thread->joinable())
        GUI_Thread->join();
}

void Manager::generateSnapshotManager() {
    snapMan = new SnapshotManager(setPkg->getOptimizerSettingsPackage()->getMaxIterations(),
                                    setPkg->getSwarmSize());
}

SnapshotManager *Manager::getSnapshotManager() {
    return snapMan;
}

SettingsPackage *Manager::getSettingsPackage() {
    return setPkg;
}

void Manager::initializeOptimizer() {
    std::string objFun = setPkg->getProblemDomainSettingsPackage()->getObjectiveFunction();
    if(objFun == "Sin")
        objective = new SinObjective();
    else if(objFun == "Saddle")
        objective = new SaddleObjective();

    std::string optAlg = setPkg->getOptimizerSettingsPackage()->getAlgorithm();
    if(optAlg == "Hill Climbing")
        optimizer = new HillClimber(objective, snapMan,
                                    false);

}

void Manager::optimize() {
    if(!optimizer) return;
    for(int i = 0; i < setPkg->getOptimizerSettingsPackage()->getMaxIterations(); ++i)
    {
        optimizer->iterate();
    }
    Particle* best = optimizer->getBestSolution();
    std::cout << "Best located solution is from particle at coords (" << best->getPositionArray()[0] <<","
              << best->getPositionArray()[1] << ") and has current fitness of: " << best->getFitnessValue() << "\n"
              << "Particle's best position was (" << best->getPersonalBestPosition()[0] << ","
              << best->getPersonalBestPosition()[1] << " with fitness of: " << best->getPersonalBest() << std::endl;
}
