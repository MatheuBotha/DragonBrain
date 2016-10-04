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

    FIPS(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i,int size,double w);

    virtual void updateVelocity(Particle *particle,Snapshot * snappy);

    virtual void iterate() override;

    double getConstrictionCoefficient() const;

    void setConstrictionCoefficient(double constrictionCoefficient);

    int getNSize() const;

    void setNSize(int nSize);
    double distanceFunction(double * a,double * b);
};


#endif //SIMPLEOPT_FIPS_H
