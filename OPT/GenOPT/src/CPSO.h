//
// Created by E.Singh on 9/11/2016.
//

#ifndef SIMPLEOPT_CPSO_H
#define SIMPLEOPT_CPSO_H

#include "PSO.h"
class CPSO: public PSO{
private:
    /*Citation
     * Ioan Cristian Trelea.
    The particle swarm optimization algorithm: convergence analysis and parameter selection.
    Inf. Process. Lett., 85(6):317-325, 2003.
     * */
    double vMax;
    double constrictionCoefficient;
public:
    CPSO();

    CPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i,  double wVal, double velMax,double boundArr[4],double s,double c);

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

    double calculateConstrictionCoefficient();
};


#endif //SIMPLEOPT_CPSO_H
