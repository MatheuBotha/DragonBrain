/**
 * @class HillClimber
 *
 * The SwarmVis system must be able to perform other optimisation strategies beyond the PSO mechanism.
 * Hill Climbing is one such process that can be performed using a swarm as part of the hill climbing strategy.
 * The HillClimber class therefore is used to encapsulate thi search process.
 *
 * @note Still in Progress
 *
 * @authors
 * Emilio Singh u14006512
 * Gerard van wyk u14101263
 *
 * @version 0.1
 *
 * @date: 2016/07/01 12:16
 *
 * Contact: u14006512@tuks.co.za
 *
 * */

#ifndef OPT_HILLCLIMBER_H
#define OPT_HILLCLIMBER_H
#include "OPT_Process.h"
#include "ObjectiveFunction.h"
#include "../../../SnapshotManager/SnapshotManager.h"
#include "../../../SnapshotManager/snapshot.h"
#include "Particle.h"
#include <cstdlib>

class HillClimber : public OPT_Process {

public:

    double mutationRate = 0.1;



///The override method for solve
    virtual void iterate() override;

    HillClimber(ObjectiveFunction *myObjectiveFunction, SnapshotManager *mySnapshotManager, bool output,double boundsA[4]) : OPT_Process(output,boundsA)
    {

        objectiveFunction = myObjectiveFunction;
        snapshotManager = mySnapshotManager;
        srand((unsigned)time(NULL));
        for(int i=0;i<4;i++)
        {
            bounds[i]=boundsA[i];
        }
    }

    void mutate(Particle *particle);

    virtual ~HillClimber() { }
};


#endif //OPT_HILLCLIMBER_H
