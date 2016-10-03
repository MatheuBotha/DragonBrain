//
// Created by E.Singh on 9/11/2016.
//

#include "GCPSO.h"

GCPSO::GCPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i,int scVal, int fcVal,double f) : PSO(pFunction, pManager, i) {
    fc=fcVal;
    sc=scVal;
    constrictionCoefficient=f;
}

double GCPSO::calculatePt(Particle ** swarm, int swarmSize) {
    double maxDistance=DBL_MIN;
    bool twoD=true;

    if (swarm[0]->getPositionArrayPointer()[1]==DBL_MAX
        ||swarm[0]->getPositionArrayPointer()[1]==DBL_MAX)
    {
        twoD=false;
    }
    double tmpDistance;
    double basePositon[2];
    basePositon[0]=swarm[0]->getPositionArrayPointer()[0];
    basePositon[1]=swarm[0]->getPositionArrayPointer()[1];

    for (int i=1;i<swarmSize;i++)
    {

        if (twoD==true)
        {
            tmpDistance=getDistance(swarm[i]->getPositionArrayPointer()[0],basePositon[0]);
        } else
            {
                tmpDistance=getDistance(swarm[i]->getPositionArrayPointer(),basePositon);
            }

        if (tmpDistance>maxDistance)
            {
                maxDistance=tmpDistance;
            }
    }

    if (numSucccses>sc)
    {
        return 2*maxDistance;
    }else if (numFailures>fc)
        {
            return (1/1.5)*maxDistance;
        } else return maxDistance;

}


void GCPSO::calculateSearchParticleVelocity(double bestVelocity,double pt) {
    double r=getRandomNumberMT();
    double tmp;

    tmp=bestVelocity+(constrictionCoefficient*getPastVelocity())+pt*(1-(2*r));

    setPastVelocity(tmp);
}

bool GCPSO::guaranteeConvergence(Particle ** swarm,int s) {
    double basePosition[2];
    int bestParticleIndex;
    double tmpBestFitness=-1;
    bool twoD=true;
    int swarmSize=s;
    if (swarm[0]->getPositionArrayPointer()[1]==DBL_MAX
        || swarm[0]->getPositionArrayPointer()[1]==DBL_MIN)
    {
        twoD=false;
    }

    for (int i=0;i<swarmSize;i++)
    {
        if (swarm[i]->getFitnessValue()>tmpBestFitness)
        {
            tmpBestFitness=swarm[i]->getFitnessValue();
            bestParticleIndex=i;
        }
    }


    calculateSearchParticleVelocity(swarm[bestParticleIndex]->getFitnessValue()
            ,calculatePt(swarm,swarmSize));
    double result;
    if (twoD) {
        for(int i=0;i<swarmSize;i++)
        {
            basePosition[0] = swarm[i]->getPositionArrayPointer()[0]+pastVelocity;
            basePosition[1]=swarm[i]->getPositionArrayPointer()[1]+pastVelocity;

            result=objectiveFunction->functionInput(basePosition);

            if (result>tmpBestFitness)
            {
                numSucccses++;
                return true;
            } else
            {
                numFailures++;
                return false;
            }
        }

    } else
    {
        for(int i=0;i<swarmSize;i++)
        {
            basePosition[0] = swarm[i]->getPositionArrayPointer()[0]+pastVelocity;
            result=objectiveFunction->functionInput(basePosition);
            if (result>tmpBestFitness)
            {
                numSucccses++;
                return true;
            } else
            {
                numFailures++;
                return false;
            }
        }

    }


    return false;
}

void GCPSO::iterate() {
    bool cont=true;
    Particle ** swarm;
    int s;
    while (cont)
    {
        cont=false;

        PSO::iterate();
        swarm=snapshotManager->getLast()->getSwarm();
         s=snapshotManager->getLast()->getSwarmSize();
        cont=guaranteeConvergence(swarm,s);
    }

    for(int i=0;i<s;i++)
    {
        delete swarm[i];
    }
    delete [] swarm;
}

double GCPSO::getDistance(double a, double b) {
    return abs(a-b);
}

double GCPSO::getDistance(double *a, double *b) {
    return sqrt(pow((a[0]-b[0]),2)+pow((a[1]-b[1]),2));
}

double GCPSO::getConstrictionCoefficient() const {
    return constrictionCoefficient;
}

int GCPSO::getNumSucccses() const {
    return numSucccses;
}

int GCPSO::getNumFailures() const {
    return numFailures;
}

int GCPSO::getSc() const {
    return sc;
}

int GCPSO::getFc() const {
    return fc;
}

double GCPSO::getPastVelocity() const {
    return pastVelocity;
}

void GCPSO::setConstrictionCoefficient(double constrictionCoefficient) {
    GCPSO::constrictionCoefficient = constrictionCoefficient;
}

void GCPSO::setNumSucccses(int numSucccses) {
    GCPSO::numSucccses = numSucccses;
}

void GCPSO::setNumFailures(int numFailures) {
    GCPSO::numFailures = numFailures;
}

void GCPSO::setSc(int sc) {
    GCPSO::sc = sc;
}

void GCPSO::setFc(int fc) {
    GCPSO::fc = fc;
}

void GCPSO::setPastVelocity(double pastVelocity) {
    GCPSO::pastVelocity = pastVelocity;
}
