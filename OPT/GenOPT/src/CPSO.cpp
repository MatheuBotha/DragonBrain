//
// Created by E.Singh on 9/11/2016.
//

#include "CPSO.h"

CPSO::CPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i, double wVal, double velMax,double boundArr[4],double s,double c) :
        PSO(pFunction, pManager, i, boundArr, wVal, s,c) {
    vMax=velMax;
    calculateConstrictionCoefficient();
}
double CPSO::calculateConstrictionCoefficient()
{
    double tmp;
    double epsilon=cog+soc;

    if ((pow(epsilon,2)-(4*epsilon))<0)
    {
      constrictionCoefficient=1;
    } else {
        tmp = 2.0 / abs(2 - (epsilon) - sqrt(sqrt(pow(epsilon, 2) - (4 * epsilon))));
    }
    constrictionCoefficient=tmp;

    /**Convergence will happen at epislon>4.0
     *
     * */
}
void CPSO::updateVelocity(Particle *particle) {
    double cogComp,socComp,inertiaComp;
    double r1,r2;
    double bestPos[2], currentPos[2], gbestPos[2];
    double tmpV;
    particle->getPersonalBestPosition(bestPos);
    particle->getPositionArray(currentPos);
    ideal->getPersonalBestPosition(gbestPos);

    for(int i = 0; i < 2; ++i) {
        r1 = getRandomNumberMT();
        r2 = getRandomNumberMT();
        inertiaComp = particle->getVelocity(i);

        cogComp = (r1 * cog) * (bestPos[i] - currentPos[i]);
        socComp = (r2 * soc) * (gbestPos[i] - currentPos[i]);
        decayInertiaWeight(w);
        tmpV =constrictionCoefficient*((w*inertiaComp)+cogComp+socComp);

        if (tmpV>vMax) tmpV=vMax;
        if (tmpV<-vMax) tmpV=-vMax;
        particle->setVelocity(tmpV, i);
    }
}

void CPSO::decayInertiaWeight(double oldInertia)
{
    double tmp=oldInertia;
    double percentageComplete=0.0;

    percentageComplete=(currentIteration)/(1.0*snapshotManager->getBound())*100.0;

    if ((100.0-percentageComplete)<=20.0)
    {
    tmp=oldInertia*0.75;

    }else

    if ((100.0-percentageComplete)<=10.0)
    {
        tmp=oldInertia*0.25;
    }
    else
        {
            tmp=oldInertia;
        }

    setW(tmp);
}