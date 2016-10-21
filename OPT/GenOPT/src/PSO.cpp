//
// Created by Warmaster on 7/1/2016.
//

#include "PSO.h"


PSO::PSO(bool output,double inBounds[4]) : OPT_Process(output,inBounds) {

}

PSO::PSO(ObjectiveFunction *myObjectiveFunction, SnapshotManager *mySnapshotManager, bool output,double inBounds[4], double wVal, double s, double c)
        : OPT_Process(output,inBounds) {

    this->objectiveFunction=myObjectiveFunction;
    this->snapshotManager=mySnapshotManager;
    generator.seed((unsigned)time(NULL));
    w=wVal;
    cog=c;
    soc=s;
}

PSO::~PSO() {

}

double PSO::getRandomNumberMT() {
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    return distribution(generator);
}

void PSO::updateVelocity(Particle *particle) {
    double cogComp,socComp,inertiaComp;
    double r1,r2;
    double bestPos[2], currentPos[2], gbestPos[2];
    particle->getPersonalBestPosition(bestPos);
    particle->getPositionArray(currentPos);
    ideal->getPersonalBestPosition(gbestPos);

    for(int i = 0; i < 2; ++i) {
        r1 = getRandomNumberMT();
        r2 = getRandomNumberMT();
        inertiaComp = particle->getVelocity(i) * w;

        cogComp = (r1 * cog) * (bestPos[i] - currentPos[i]);
        socComp = (r2 * soc) * (gbestPos[i] - currentPos[i]);

        particle->setVelocity( inertiaComp+cogComp+socComp, i);
    }
}

void PSO::updatePosition(Particle *particle) {
    double currentPos[2];
    particle->getPositionArray(currentPos);
    for (int i=0;i<2;i++)
    {
        particle->setPositionAtDimension(currentPos[i]+particle->getVelocity(i),i);
    }

    if (currentPos[1]==DBL_MAX)
    {
        if (checkSpecificBound(bounds[0],bounds[1],particle->getPositionArrayPointer()[0])==false)
        {
            int c=checkProximityDistances(bounds[0],bounds[1],particle->getPositionArrayPointer()[0]);
            if (c==1)
            {
                particle->setPositionAtDimension(bounds[1],0);
            } else
                {
                    particle->setPositionAtDimension(bounds[0],0);
                }

        }
    }
    else
        {
            if (checkSpecificBound(bounds[0],bounds[1],particle->getPositionArrayPointer()[0])==false) {
                int c = checkProximityDistances(bounds[0], bounds[1], particle->getPositionArrayPointer()[0]);
                if (c == 1) {
                    particle->setPositionAtDimension(bounds[1], 0);
                } else {
                    particle->setPositionAtDimension(bounds[0], 0);
                }
            }
            if (checkSpecificBound(bounds[2],bounds[3],particle->getPositionArrayPointer()[1])==false) {
                int c = checkProximityDistances(bounds[2], bounds[3], particle->getPositionArrayPointer()[1]);
                if (c == 1) {
                    particle->setPositionAtDimension(bounds[3], 1);
                } else {
                    particle->setPositionAtDimension(bounds[2], 1);
                }
            }
        }
}

void PSO::iterate() {
    Snapshot *last;
    Snapshot *newIteration;
    Particle **swarm;
    int swarmSize;

    ideal = nullptr;
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
        updateVelocity(swarm[j]);
        updatePosition(swarm[j]);
    }
    ideal->getPositionArray(currentPos);
    if(printer)
    {
        std::cout << "Best located particle so far was at position: (" << currentPos[0] << ", "
                  << currentPos[1] << ") with fitness of: " << ideal->getPersonalBest() << std::endl;
    }

    newIteration->setGBest(ideal);
    snapshotManager->enqueue(newIteration);
}

