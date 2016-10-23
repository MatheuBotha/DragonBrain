//
// Created by gerard on 2016/10/09.
//

#include "RandomSearch.h"
#include <iostream>


void RandomSearch::iterate() {

    Snapshot *last;
    Snapshot *newIteration;
    Particle **swarm;
    int swarmSize;

    last = snapshotManager->getLast();
    //ideal = nullptr;
    newIteration = new Snapshot(last);
    if(printer){
        cout << "NEW ITERATION\n";
    }

    swarm = newIteration->getSwarm();

    swarmSize = newIteration->getSwarmSize();


    //Mutate all the particles to be completely different
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

void RandomSearch::mutate(Particle *particle) {
    double *newPosition = particle->getPositionArrayPointer();
    double xRange = bounds[1]-bounds[0];
    double yRange = bounds[3]-bounds[2];

    if (newPosition[1]==DBL_MAX){

        newPosition[0]=bounds[0]+((double)rand()/(double)RAND_MAX)*xRange;

        if(newPosition[0]<bounds[0]){
            newPosition[0]=bounds[0];
        }else if(newPosition[0]>bounds[1]){
            newPosition[0]=bounds[1];
        }
    }else{

        newPosition[0]=bounds[0]+((double)rand()/(double)RAND_MAX)*xRange;
        newPosition[1]=bounds[2]+((double)rand()/(double)RAND_MAX)*yRange;

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

    particle->setPositionArray(newPosition);
}