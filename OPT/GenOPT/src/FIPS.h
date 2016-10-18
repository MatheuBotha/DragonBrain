//
// Created by E.Singh on 9/11/2016.
//

#ifndef SIMPLEOPT_FIPS_H
#define SIMPLEOPT_FIPS_H

#include "PSO.h"
class FIPS: public PSO {

private:
    int nSize;
    double constrictionCoefficient;
public:
    FIPS();

    FIPS(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i,int size,double w,double bounds[4],double s,double c);

    virtual void updateVelocity(Particle *particle,Particle ** swarm,int ss,int index);

    virtual void iterate() override;

    double getConstrictionCoefficient() const;

    void setConstrictionCoefficient(double constrictionCoefficient);

    int getNSize() const;

    void setNSize(int nSize);
    long double distanceFunction(double * a,double * b);
};


#endif //SIMPLEOPT_FIPS_H
