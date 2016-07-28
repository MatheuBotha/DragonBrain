/**
 * @class HillClimber
 *
 * The SwarmVis system must be able to perform other optimisation strategies beyond the PSO mechanism.
 * Hill Climbing is one such process that can be performed using a swarm as part of the hill climbing strategy.
 * The HillClimber class therefore is used to encapsulate the search process.
 *
 * @note Still in Progress
 *
 * @author Emilio Singh u14006512
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

class HillClimber:public OPT_Process {

public:


    virtual double *updatePosition(Particle particleToUpdate) override;

    virtual double updateVelocity(Particle particleToUpdates) override;

///The override method for solve
    virtual void solve() override;

    HillClimber() { }

    virtual ~HillClimber() { }
};


#endif //OPT_HILLCLIMBER_H
