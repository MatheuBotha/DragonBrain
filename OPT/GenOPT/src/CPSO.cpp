//
// Created by E.Singh on 9/11/2016.
//

#include "CPSO.h"

CPSO::CPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i, double wVal, double velMax,double boundArr[4],double s,double c) :
        PSO(pFunction, pManager, i, boundArr,s,c) {
    vMax=velMax;
    w=wVal;
}

void CPSO::updateVelocity(Particle *particle) {
    double cogComp,socComp,inertiaComp;

    double r1,r2;
    r1=getRandomNumberMT();
    r2=getRandomNumberMT();
    inertiaComp=particle->getVelocity();
    cogComp=(r1*cog)*(particle->getPersonalBest()-particle->getFitnessValue());
    socComp=(r2*soc)*(ideal->getPersonalBest() - particle->getFitnessValue());

    double tmpV=(w*inertiaComp)+cogComp+soc;

    if (tmpV>vMax) tmpV=vMax;
    if (tmpV<-vMax) tmpV=-vMax;

    particle->setVelocity(tmpV);
}
