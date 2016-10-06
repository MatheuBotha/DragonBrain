//
// Created by E.Singh on 9/11/2016.
//

#ifndef SIMPLEOPT_CPSO_H
#define SIMPLEOPT_CPSO_H

#include "PSO.h"
class CPSO: public PSO{
private:
    double w;
    double vMax;
public:
    CPSO();

    CPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i,  double wVal, double velMax,double boundArr[4]);

    double getW()
    {
        return w;
    }

    void setW(double a)
    {
        w=a;
    }

    double getMaxV()
    {
        return vMax;
    }

    void setMaxV(double a)
    {
        vMax=a;
    }

    virtual void updateVelocity(Particle *particle) override;
};


#endif //SIMPLEOPT_CPSO_H
