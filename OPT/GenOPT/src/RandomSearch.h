//
// Created by gerard on 2016/10/09.
//

#ifndef SWARMVIZ_RANDOMSEARCH_H
#define SWARMVIZ_RANDOMSEARCH_H
#include "OPT_Process.h"
#include "ObjectiveFunction.h"
#include "../../../SnapshotManager/SnapshotManager.h"
#include "../../../SnapshotManager/snapshot.h"
#include "Particle.h"
#include <cstdlib>

class RandomSearch : public OPT_Process {

public:

    double mutationRate = 0.1;



///The override method for solve
    virtual void iterate() override;

    RandomSearch(ObjectiveFunction *myObjectiveFunction, SnapshotManager *mySnapshotManager, bool output,double boundsA[4]) : OPT_Process(output,boundsA)
    {

        objectiveFunction = myObjectiveFunction;
        snapshotManager = mySnapshotManager;
        srand((unsigned)time(NULL));
        /*for(int i=0;i<4;i++) //Already done in abstract constructor.
        {
            bounds[i]=boundsA[i];
        }*/
    }

    void mutate(Particle *particle);

    virtual ~RandomSearch() { }
};


#endif //SWARMVIZ_RANDOMSEARCH_H
