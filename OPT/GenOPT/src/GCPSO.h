//
// Created by E.Singh on 9/11/2016.
//

#ifndef SIMPLEOPT_GCPSO_H
#define SIMPLEOPT_GCPSO_H

#include "PSO.h"
class GCPSO: public PSO {

private:
    double constrictionCoefficient;
    int numSucccses=15;
    int numFailures=5;
    int sc;
    int fc;
    double pastVelocity=0;
    double calculatePt(Particle ** swarm, int swarmSize);
    double getDistance(double a,double b);
    double getDistanceArray(double* a,double *b);
public:


    GCPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i, double boundArr[4], int a,int b,double w,double s,double c);
    void calculateSearchParticleVelocity(double bestVelocity,double pt);
    bool guaranteeConvergence(Particle ** swarm, int swarmSize);

    virtual void iterate() override;

    double getConstrictionCoefficient() const;

    int getNumSucccses() const;

    int getNumFailures() const;

    int getSc() const;

    int getFc() const;

    double getPastVelocity() const;

    void setConstrictionCoefficient(double constrictionCoefficient);

    void setNumSucccses(int numSucccses);

    void setNumFailures(int numFailures);

    void setSc(int sc);

    void setFc(int fc);

    void setPastVelocity(double pastVelocity);
};


#endif //SIMPLEOPT_GCPSO_H
