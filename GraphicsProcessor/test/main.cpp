//
// Created by matheu on 2016/10/04.
//

#include "../GraphicsProcessor.h"
#include "../../OPT/GenOPT/src/SinObjective.h"
#include "../../OPT/GenOPT/src/SaddleObjective.h"
#include "../../OPT/GenOPT/src/AckleyObjective.h"
#include "../../OPT/GenOPT/src/WeierstrassObjective.h"
#include "../../OPT/GenOPT/src/QuadricObjective.h"
#include "../../SettingsPackage/src/problemdomainsettingspackage.h"
#include "../../SnapshotManager/SnapshotManager.h"
#include "../../OPT/GenOPT/src/HillClimber.h"
#include "../../OPT/GenOPT/src/ElitistHillClimber.h"

int main()
{
    //Create Problem Domain Settings Package
    ProblemDomainSettingsPackage pdsp;

    //set Objective Function
    std::string objective_function_name = "temp";
    pdsp.setObjectiveFunction(objective_function_name);

    //set dim
    pdsp.setDimensions(2);

    //set boundaries
    double* boundaries = new double[4];
    boundaries[0] = -1.0;
    boundaries[1] = 1.0;
    boundaries[2] = -1.0;
    boundaries[3] = 1.0;
    pdsp.setBoundaries(boundaries);


    ObjectiveFunction* objective = new SinObjective(1, 0, 0, 0);
    //GGGGGGGG
    int maxIteration = 200;
    int swarmSize = 200;
    int dimension = 2;
    int numInstances = 2;
    SnapshotManager* masterSnapshot = new SnapshotManager(maxIteration, swarmSize, dimension, boundaries);
    SnapshotManager **snapshotManagers = new SnapshotManager*[numInstances];

    for(int i=0; i<numInstances; ++i)
    {
        snapshotManagers[i] = masterSnapshot;
    }

    //******************************************************************************************************************
    //  Here Please
    //******************************************************************************************************************
//    double* minPosition = new double[2];
//    double minValue;
//    Snapshot *minSnapshot = new Snapshot(swarmSize,dimension,boundaries);
//    minPosition[0]=0.0;
//    minPosition[1]=0.0;
//    minValue = objective->functionInput(minPosition);
//    minSnapshot->getSwarm()[0]->setParticlePosition(minPosition);
//    minSnapshot->getSwarm()[0]->setFitnessValue(minValue);
//    snapshotManager->enqueue(minSnapshot);
//
//
//    double* halfPosition = new double[2];
//    double halfValue;
//    Snapshot *halfSnapshot = new Snapshot(swarmSize,dimension,boundaries);
//    halfPosition[0]=boundaries[0];
//    halfPosition[1]=boundaries[2];
//    halfValue = objective->functionInput(halfPosition);
//    halfSnapshot->getSwarm()[0]->setParticlePosition(halfPosition);
//    halfSnapshot->getSwarm()[0]->setFitnessValue(halfValue);
//    snapshotManager->enqueue(halfSnapshot);
//
//    double* thirdPosition = new double[2];
//    double thirdValue;
//    Snapshot *thirdSnapshot = new Snapshot(swarmSize,dimension,boundaries);
//    thirdPosition[0]=boundaries[1];
//    thirdPosition[1]=boundaries[2];
//    thirdValue = objective->functionInput(thirdPosition);
//    thirdSnapshot->getSwarm()[0]->setParticlePosition(thirdPosition);
//    thirdSnapshot->getSwarm()[0]->setFitnessValue(thirdValue);
//    snapshotManager->enqueue(thirdSnapshot);
//
//
//    double* maxPosition = new double[2];
//    double maxValue;
//    Snapshot *maxSnapshot = new Snapshot(swarmSize,dimension,boundaries);
//    maxPosition[0]=boundaries[1];
//    maxPosition[1]=boundaries[3];
//    maxValue = objective->functionInput(maxPosition);
//    maxSnapshot->getSwarm()[0]->setParticlePosition(maxPosition);
//    maxSnapshot->getSwarm()[0]->setFitnessValue(maxValue);
//    snapshotManager->enqueue(maxSnapshot);
    //******************************************************************************************************************
    //  End: Here Please
    //******************************************************************************************************************

    OPT_Process *opt1 = new HillClimber(objective, masterSnapshot, false, boundaries);

    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
    }

    //GGGGGGGG
    GraphicsProcessor gp(pdsp, snapshotManagers, 1280, 720, 50, numInstances);
    gp.setObjective(objective);
    gp.run();

    delete masterSnapshot;
    delete snapshotManagers;
}
