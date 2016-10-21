#include <iostream>
#include "HillClimber.h"

void HillClimber::iterate() {

    Snapshot *last;
    Snapshot *newIteration;
    Particle **swarm;
    int swarmSize;

    ideal = nullptr;
    last = snapshotManager->getLast();

    newIteration = new Snapshot(last);
  if(printer){
      cout << "NEW ITERATION\n";
  }

    swarm = newIteration->getSwarm();

    swarmSize = newIteration->getSwarmSize();

    for(int i=0; i<swarmSize; i++){
        if(printer){
            std::cout << "Particle " << i;
        }

        mutate(swarm[i]);

        if(printer){
            std::cout << " is at coords (" << swarm[i]->getPositionArrayPointer()[0] << ", "
                      << swarm[i]->getPositionArrayPointer()[1] << ") has fitness of: "
                      << swarm[i]->getFitnessValue() << " and personal best of: "
                      << swarm[i]->getPersonalBest() << std::endl;
        }
    }
    if(printer){
        std::cout << "ITERATION COMPLETE. CURRENT BEST: " << ideal->getPersonalBest() << std::endl;
    }
    newIteration->setGBest(ideal);
    snapshotManager->enqueue(newIteration);
}

void HillClimber::mutate(Particle *particle) {
    double *newPosition = particle->getPositionArrayPointer();
    double xRange = bounds[1] - bounds[0];
    double yRange = bounds[3] - bounds[2];

    if (newPosition[1]==DBL_MAX){

        newPosition[0]+=(mutationRate*xRange*(((double)rand()/(double)RAND_MAX)-0.5));

        if(newPosition[0]<bounds[0]){
            newPosition[0]=bounds[0];
        }else if(newPosition[0]>bounds[1]){
            newPosition[0]=bounds[1];
        }
    }else{

        newPosition[0]+=(mutationRate*xRange*(((double)rand()/(double)RAND_MAX)-0.5));
        newPosition[1]+=(mutationRate*yRange*(((double)rand()/(double)RAND_MAX)-0.5));

        if(newPosition[0] < bounds[0]){
            newPosition[0] = bounds[0];

        }else if(newPosition[0] > bounds[1]){
            newPosition[0] = bounds[1];
        }
        if(newPosition[1] < bounds[2]){
            newPosition[1] = bounds[2];

        }else if(newPosition[1] > bounds[3]){
            newPosition[1] = bounds[3];

        }
    }

    double fitness;
    double bestFitness;
    fitness = objectiveFunction->functionInput(newPosition);
    bestFitness = objectiveFunction->functionInput(particle->getPersonalBestPos());
    particle->setFitnessValue(fitness);
    particle->setPersonalBest(bestFitness);
    if(particle->getFitnessValue() < particle->getPersonalBest()){
        particle->setPersonalBestPosition(newPosition);
        particle->setPersonalBest(particle->getFitnessValue());
    }

    if(ideal == nullptr ||
       ideal != nullptr && particle->getPersonalBest() < ideal->getPersonalBest()) {
        ideal = particle;
    }

    particle->setParticlePosition(particle->getPersonalBestPos());
    particle->setFitnessValue(particle->getPersonalBest());
}
