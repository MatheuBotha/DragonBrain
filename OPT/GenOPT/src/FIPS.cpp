//
// Created by E.Singh on 9/11/2016.
//

#include "FIPS.h"

FIPS::FIPS(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i, int size,double wA,double boundsD[4],double s,double c) : PSO(pFunction, pManager, i,boundsD,wA,s,c) {
nSize=size;
    for(int i=0;i<4;i++)
    {
        bounds[i]=boundsD[i];
    }
}

/**The Fully Informed PSO algorithm is predicated on increasing the scope of a particle's knowledge of the
 * problem by aggregating the best's of k nearest neighbours when considering velocity updates.
 *
 * */
void FIPS::updateVelocity(Particle *particle,Particle ** swarm,int ss,int indexVal) {
    int k;
    int sizeSwarm=ss;
    if (sizeSwarm<nSize)
    {
        k=sizeSwarm;
    } else
        {
            k=nSize;
        }
    vector<int> tmpVector;
    double cTemp;
    int a[sizeSwarm];

        tmpVector.clear();
        cTemp = 0;


    for (int r = 0; r < sizeSwarm; r++)
    {
       a[r] = r;
    }
        ///construct local neighbourhood
    int index;
    long double smallestValue = DBL_MAX;

    while (tmpVector.size() != k) {
            smallestValue=DBL_MAX;
            for (int e = 0; e < sizeSwarm; e++) {
                if (indexVal!=e && a[e] != -1 && distanceFunction(particle->getPositionArrayPointer(),
                                                   swarm[e]->getPositionArrayPointer()) < smallestValue) {
                    smallestValue = distanceFunction(particle->getPositionArrayPointer(),swarm[e]->getPositionArrayPointer());
                    index = e;
                }
            }

            tmpVector.push_back(index);
            a[index] = -1;
        }

        ///
        double vUP;
        for(int d=0;d<2;d++)
        {
            cTemp=0;
            for(int j=0;j<tmpVector.size();j++)
            {
                for(int y=0;y<2;y++){
                cTemp+=getRandomNumberMT()*(swarm[tmpVector.at(j)]->getPersonalBestPos()[y]-particle->getPositionAtDimension(y));
                }
            }
<<<<<<< HEAD
            vUP=0;
            vUP=particle->getVelocity(0)+w*(particle->getVelocity(d)+((1/k)*cTemp));
=======
            vUP=0.0;
            vUP=constrictionCoefficient*((particle->getVelocity(d)+((1.0/k)*cTemp)));
>>>>>>> master
            particle->setVelocity(vUP,d);
        }

    particle->setNIndices(tmpVector);
    tmpVector.clear();


}

void FIPS::iterate() {
    Snapshot *last;
    Snapshot *newIteration;
    Particle **swarm;
    int swarmSize;

    last=snapshotManager->getLast();
    newIteration=new Snapshot(last);

    if(printer)  cout << "NEW ITERATION\n";

    swarm = newIteration->getSwarm();

    swarmSize = newIteration->getSwarmSize();

    /*For each particle in swarm do
     *
     *  update personal Best
     *  update ideal best (gBest)
     *
     *For Each particle in swarm
     *  update velocity
     *  update position
    */
    double tmpFit;
    double currentPos[2];

    for (int i=0;i<swarmSize;i++) {
        if (printer) { std::cout << "Particle " << i; }

        swarm[i]->getPositionArray(currentPos);
        tmpFit = objectiveFunction->functionInput(currentPos);
        swarm[i]->setFitnessValue(tmpFit);

        if (tmpFit <= swarm[i]->getPersonalBest()) {
            swarm[i]->setPersonalBest(tmpFit);
        }

        if ((ideal == nullptr) ||
            (ideal != nullptr && swarm[i]->getPersonalBest() < ideal->getPersonalBest()))
            ideal = swarm[i];

        if (printer)
        {
            swarm[i]->getPositionArray(currentPos);

            std::cout << " is at coords (" << currentPos[0] << ", "
                      << currentPos[1] << ") has fitness of: "
                      << swarm[i]->getFitnessValue() << " and personal best of: "
                      << swarm[i]->getPersonalBest() << std::endl;

        }
    }

    for (int j=0;j<swarmSize;j++)
    {
        updateVelocity(swarm[j],swarm,swarmSize,j);
        updatePosition(swarm[j]);
    }
    snapshotManager->enqueue(newIteration);

}

double FIPS::getConstrictionCoefficient() const {
    return constrictionCoefficient;
}

void FIPS::setConstrictionCoefficient(double constrictionCoefficient) {
    FIPS::constrictionCoefficient = constrictionCoefficient;
}

int FIPS::getNSize() const {
    return nSize;
}

void FIPS::setNSize(int nSize) {
    FIPS::nSize = nSize;
}

long double FIPS::distanceFunction(double *a,double * b) {
    if (a[1]==DBL_MAX || a[1]==DBL_MIN || b[1]==DBL_MAX || b[1]==DBL_MIN)
    {
        return abs(a[0]-b[0]);
    } else
        {
            long double val;
            long double at0,at1,bt0,bt1;
            at0=a[0]*100;
            at1=a[1]*100;
            bt0=b[0]*100;
            bt1=b[1]*100;
            val=sqrt(pow((at0-bt0),2)+pow((at1-bt1),2));
            return val;
        }
}
