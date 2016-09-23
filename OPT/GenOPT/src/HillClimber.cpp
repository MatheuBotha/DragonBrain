#include <iostream>
#include "HillClimber.h"

void HillClimber::iterate() {

    Snapshot *last;
    Snapshot *newIteration;
    Particle **swarm;
    int swarmSize;

    last = snapshotManager->getLast();
    newIteration = new Snapshot(last);
  if(printer)  cout << "NEW ITERATION\n";

    swarm = newIteration->getSwarm();

    swarmSize = newIteration->getSwarmSize();
    double pos[2];
    for(int i=0; i<swarmSize; i++){
        swarm[i]->setPositionArray(pos);
        if(printer)        std::cout << "Particle " << i;
        mutate(swarm[i]);
        if(printer)        std::cout << " is at coords (" << pos[0] << ", "
                                     << pos[1] << ") has fitness of: "
                                     << swarm[i]->getFitnessValue() << " and personal best of: "
                                     << swarm[i]->getPersonalBest() << std::endl;
    }
    if(printer)std::cout << "ITERATION COMPLETE. CURRENT BEST: " << ideal->getPersonalBest() << std::endl;
    snapshotManager->enqueue(newIteration);
}

void HillClimber::mutate(Particle *particle) {
    double newPosition[2];
    particle->setPositionArray(newPosition);
    int loop;
    if(newPosition[1] == DBL_MAX)
        loop = 1;
    else loop = 2;
    for (int i = 0; i < loop; ++i) {
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
//    if(printer)
  //      std::cout<<"New best: "<<fitness<<std::endl;
        if(ideal == nullptr ||
                ideal != nullptr && particle->getPersonalBest() > ideal->getPersonalBest())
            ideal = particle;
    }
    double newBest[2];
    particle->getPersonalBestPosition(newBest);
    particle->setParticlePosition(newBest);
}
