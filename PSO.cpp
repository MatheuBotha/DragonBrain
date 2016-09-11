//
// Created by Warmaster on 7/1/2016.
//

#include "PSO.h"


PSO::PSO(bool output) : OPT_Process(output) {

}

PSO::PSO(ObjectiveFunction *myObjectiveFunction, SnapshotManager *mySnapshotManager, bool output)
        : OPT_Process(output) {

    this->objectiveFunction=myObjectiveFunction;
    this->snapshotManager=mySnapshotManager;
    generator.seed((unsigned)time(NULL));
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
    r1=getRandomNumberMT();
    r2=getRandomNumberMT();
    inertiaComp=particle->getVelocity();
    cogComp=(r1*cog)*(particle->getPersonalBest()-particle->getFitnessValue());
    socComp=(r2*soc)*(ideal->getPersonalBest() - particle->getFitnessValue());

    particle->setVelocity(inertiaComp+cogComp+soc);
}

void PSO::updatePosition(Particle *particle) {

    for (int i=0;i<2;i++)
    {
        particle->setPositionAtDimension(particle->getPositionArray()[i]+particle->getVelocity(),i);
    }
}

void PSO::iterate() {
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
    for (int i=0;i<swarmSize;i++) {
        if (printer) { std::cout << "Particle " << i; }

        tmpFit = objectiveFunction->functionInput(swarm[i]->getPositionArray());
        swarm[i]->setFitnessValue(tmpFit);

        if (tmpFit >= swarm[i]->getPersonalBest()) {
            swarm[i]->setPersonalBest(tmpFit);
        }

        if ((ideal == nullptr) ||
                (ideal != nullptr && swarm[i]->getPersonalBest() > ideal->getPersonalBest()))
            ideal = swarm[i];

        if (printer)
        {
        std::cout << " is at coords (" << swarm[i]->getPositionArray()[0] << ", "
                  << swarm[i]->getPositionArray()[1] << ") has fitness of: "
                  << swarm[i]->getFitnessValue() << " and personal best of: "
                  << swarm[i]->getPersonalBest() << std::endl;

        }
    }

    for (int j=0;j<swarmSize;j++)
    {
        updateVelocity(swarm[j]);
        updatePosition(swarm[j]);
    }
    std::cout << "ITERATION COMPLETE. CURRENT BEST: " << ideal->getPersonalBest() << std::endl;
    snapshotManager->enqueue(newIteration);
}

