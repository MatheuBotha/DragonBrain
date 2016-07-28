/**
 * @class CPSO
 *
 * This is one form of the PSO solving strategy that is used in optimisation problem
 * solving. This particular version is the  Conical Particle Swarm optimization variant
 * of the traditional PSO.
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

#ifndef OPT_CPSO_H
#define OPT_CPSO_H

#include "PSO.h"

class CPSO: public PSO {

public:

    ///The override method for solve
    virtual void solve() override;

    ///Creates a new CPSO
    CPSO() { }


    virtual ~CPSO() { }

    virtual double *updatePosition(Particle particleToUpdate) override;

    virtual double updateVelocity(Particle particleToUpdates) override;

private:
};
#endif //OPT_CPSO_H
