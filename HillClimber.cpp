#include <iostream>
#include "HillClimber.h"

void HillClimber::iterate() {

    Snapshot *last;
    Snapshot *newIteration;
    Particle *swarm;
    int swarmSize;

    last = snapshotManager->getLast();

    newIteration = new Snapshot(last);
    cout << "NEW ITERATION\n";
    swarm = newIteration->getSwarm();
    swarmSize = newIteration->getSwarmSize();

    for(int i=0; i<swarmSize; i++){
        mutate(&swarm[i]);
    }

    snapshotManager->enqueue(newIteration);

}

void HillClimber::mutate(Particle *particle) {

    double *newPosition = particle->getPositionArray();

    for (int i = 0; i < 2; ++i) {
        newPosition[i]+=(mutationRate*newPosition[i]*(((double)rand()/(double)RAND_MAX)-0.5));
    }

    double fitness;
    fitness = objectiveFunction->functionInput(newPosition);
    particle->setFitnessValue(fitness);
    if(particle->getFitnessValue() > particle->getPersonalBest()){
        //cout<<"CurrentFitness: "<<particle->getFitnessValue()<<endl;
        //cout<<"BestFitness: "<<particle->getPersonalBest()<<endl;
        particle->setPersonalBestPosition(newPosition);
        particle->setPersonalBest(particle->getFitnessValue());
        std::cout<<"New best: "<<fitness<<std::endl;
    }else{
        //cout<<"worse\n";
    }
    particle->setParticlePosition(particle->getPersonalBestPosition());
}
