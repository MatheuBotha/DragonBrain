/**
 * @class GCPSO
 *
 * This is one form of the PSO solving strategy that is used in optimisation problem
 * solving. This particular version is the  Guaranteed Convergence PSO optimization variant
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

#ifndef OPT_GCPSO_H
#define OPT_GCPSO_H

#include "PSO.h"
class GCPSO: public PSO{

public:
    ///The override method for solve
    virtual void solve() override;

    virtual ~GCPSO() { }

    ///Creates a new GCPSO
    GCPSO() { }

    virtual double *updatePosition(Particle particleToUpdate) override;

    virtual double updateVelocity(Particle particleToUpdates) override;
};


#endif //OPT_GCPSO_H
