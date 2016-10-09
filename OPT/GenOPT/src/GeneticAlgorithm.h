//
// Created by gerard on 2016/10/09.
//

#ifndef SWARMVIZ_GENETICALGORITHM_H
#define SWARMVIZ_GENETICALGORITHM_H

#include "OPT_Process.h"
#include "ObjectiveFunction.h"
#include "../../../SnapshotManager/SnapshotManager.h"
#include "../../../SnapshotManager/snapshot.h"
#include "Particle.h"
#include <cstdlib>

class GeneticAlgorithm : public OPT_Process {

public:

    double mutationRate = 0.1;
    int tournamentSize = 4;
    
    virtual void iterate() override;

    GeneticAlgorithm(ObjectiveFunction *myObjectiveFunction, SnapshotManager *mySnapshotManager, bool output,double boundsA[4]) : OPT_Process(output,boundsA)
    {
        objectiveFunction = myObjectiveFunction;
        snapshotManager = mySnapshotManager;
        srand((unsigned)time(NULL));
    }

    void crossover(Particle * parent1, Particle * parent2, Particle * child);

    void mutate(Particle *particle);

    virtual ~GeneticAlgorithm() { }
};

#endif //SWARMVIZ_GENETICALGORITHM_H
