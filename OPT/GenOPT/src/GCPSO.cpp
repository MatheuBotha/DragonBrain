//
// Created by E.Singh on 9/11/2016.
//

#include "GCPSO.h"

GCPSO::GCPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i, double boundArr[4], int scVal, int fcVal,double f,double s,double c) :
        PSO(pFunction, pManager, i, boundArr,f, s,c) {
    fc=fcVal;
    sc=scVal;
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
    double basePosition[2];

    if (twoD==false)
    {
        basePosition[0]=swarm[0]->getPositionArrayPointer()[0];

    }else
    {
        basePosition[0]=swarm[0]->getPositionArrayPointer()[0];
        basePosition[1]=swarm[0]->getPositionArrayPointer()[1];

    }

    for (int i=1;i<swarmSize;i++)
    {

        if (twoD==false)
        {
            tmpDistance=getDistance(swarm[i]->getPositionArrayPointer()[0],basePosition[0]);
        } else
            {

                tmpDistance=getDistanceArray(swarm[i]->getPositionArrayPointer(),basePosition);
            }

        if (tmpDistance>maxDistance)
            {
                maxDistance=tmpDistance;
            }
    }

    if (numSucccses>sc)
    {
        return 2.0*maxDistance;
    }else if (numFailures>fc)
        {
            return (1.0/1.5)*maxDistance;
        } else return maxDistance;

}


void GCPSO::calculateSearchParticleVelocity(double bestVelocity,double pt) {
    double r=getRandomNumberMT();
    double tmp;

    tmp=bestVelocity+(constrictionCoefficient*getPastVelocity())+pt*(1.0-(2.0*r));

    setPastVelocity(tmp);
}

bool GCPSO::guaranteeConvergence(Particle ** swarm,int s) {
    double basePosition[2];
    int bestParticleIndex;
    double tmpBestFitness=DBL_MAX;
    bool twoD=true;
    int swarmSize=s;
    if (swarm[0]->getPositionArrayPointer()[1]==DBL_MAX
        || swarm[0]->getPositionArrayPointer()[1]==DBL_MIN)
    {
        twoD=false;
    }

    for (int i=0;i<swarmSize;i++)
    {
        if (swarm[i]->getFitnessValue()<tmpBestFitness)
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

            if (result<tmpBestFitness)
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
            if (result<tmpBestFitness)
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
    int index=0;

    PSO::iterate();

    swarm = snapshotManager->getLast()->getSwarm();
    s = snapshotManager->getLast()->getSwarmSize();
    cont = guaranteeConvergence(swarm, s);
    if (cont==true)
    {
        PSO::iterate();
    }
    /*
    for(int i=0;i<s;i++)
    {
        delete swarm[i];
    }
    delete [] swarm;
    */
}

double GCPSO::getDistance(double a, double b) {
    return abs((a*100.0)-(b*100.0));
}

double GCPSO::getDistanceArray(double *a, double *b) {
    return sqrt(pow(((a[0]*100.0)-(b[0]*100.0)),2)+pow(((a[1]*100.0)-(b[1]*100.0)),2));
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
