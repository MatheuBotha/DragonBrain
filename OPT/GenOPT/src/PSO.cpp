//
// Created by Warmaster on 7/1/2016.
//

#include "PSO.h"

double *PSO::updatePosition(Particle particleToUpdate) {
    double tmpVel=particleToUpdate.getVelocity();

    double * tmpPosition=new double[2];

    for (int i=0;i<2;i++)
    {
        tmpPosition[i]=particleToUpdate.getPositionArray()[i];
    }
    for (int i=0;i<2;i++)
    {
        tmpPosition[i]+=tmpVel;
    }

    return tmpPosition;
}

double PSO::updateVelocity(Particle particleToUpdates) {

   double tmp=0;

    tmp=particleToUpdates.getVelocity()+((cogComp*genRandomNumber())*(particleToUpdates.getPersonalBest()-particleToUpdates.getFitnessValue()))
        +((socialComp*genRandomNumber())*(particleToUpdates.getNeighbourhoodBest()-particleToUpdates.getFitnessValue()));

    return tmp;
}


double PSO::genRandomNumber() {
    return ((double) rand() / (RAND_MAX));
}
