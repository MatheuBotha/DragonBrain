//
// Created by E.Singh on 9/11/2016.
//

#include "FIPS.h"

FIPS::FIPS(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i, double boundArr[4], int size,double wA) : PSO(pFunction, pManager, i, boundArr){
nSize=size;
    constrictionCoefficient=wA;
}

/**The Fully Informed PSO algorithm is predicated on increasing the scope of a particle's knowledge of the
 * problem by aggregating the best's of k nearest neighbours when considering velocity updates.
 *
 * */
void FIPS::updateVelocity(Particle *particle,Snapshot * snappy) {
    int k;
    if (snappy->getSwarmSize()<nSize)
    {
        k=snappy->getSwarmSize();
    } else
        {
            k=nSize;
        }

    for (int i=0;i<snappy->getSwarmSize();i++)
    {
        double cTemp=0;
        vector<int> tmpVector;
        int a[snappy->getSwarmSize()] ;
        for(int r=0;r<snappy->getSwarmSize();r++)
        {
            a[r]=r;
        }
        ///construct local neighbourhood
        while(tmpVector.size()!=k)
        {
            double smallestValue=DBL_MAX;
            int index;

            for (int e=0;e<snappy->getSwarmSize();e++)
            {
                if (a[e]!=-1 &&distanceFunction(particle->getPositionArrayPointer(),snappy->getSwarm()[e]->getPositionArrayPointer())<smallestValue)
                {
                    smallestValue=distanceFunction(particle->getPositionArrayPointer(),snappy->getSwarm()[e]->getPositionArrayPointer());
                    index=e;
                }
            }

            tmpVector.push_back(index);
            a[index]=-1;
        }
        ///
        for(int j=0;j<tmpVector.size();j++)
        {
            cTemp+=getRandomNumberMT()*(snappy->getSwarm()[tmpVector.at(i)]->getPersonalBest()-particle->getPersonalBest());
        }

        double vUP=particle->getVelocity()+constrictionCoefficient*(particle->getVelocity()+((1/k)*cTemp));
        particle->setVelocity(vUP);
        particle->setNIndices(tmpVector);
        tmpVector.clear();
    }
}

void FIPS::iterate() {
    Snapshot *last;
    Snapshot *newIteration;
    Particle **swarm;
    int swarmSize;

    last=snapshotManager->getLast();
    std::cout << last << std::endl;
    std::cout << last->getSwarmSize() << std::endl;
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

        if (tmpFit >= swarm[i]->getPersonalBest()) {
            swarm[i]->setPersonalBest(tmpFit);
        }

        if ((ideal == nullptr) ||
            (ideal != nullptr && swarm[i]->getPersonalBest() > ideal->getPersonalBest()))
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
        updateVelocity(swarm[j],newIteration);
        updatePosition(swarm[j]);
    }
    std::cout << "ITERATION COMPLETE. CURRENT BEST: " << ideal->getPersonalBest() << std::endl;
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

double FIPS::distanceFunction(double *a,double * b) {
    if (a[1]==DBL_MAX || a[1]==DBL_MIN || b[1]==DBL_MAX || b[1]==DBL_MIN)
    {
        return abs(a[0]-b[0]);
    } else
        {
            double val;
            val=sqrt(pow((a[0]-b[0]),2)+pow((a[1]-b[1]),2));
            return val;
        }
}
