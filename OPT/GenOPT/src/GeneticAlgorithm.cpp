//
// Created by gerard on 2016/10/09.
//

#include "GeneticAlgorithm.h"

void GeneticAlgorithm::iterate() {

    Snapshot *last;
    Snapshot *newIteration;
    Particle **swarm;
    Particle **oldSwarm;
    int swarmSize;

    last = snapshotManager->getLast();

    newIteration = new Snapshot(last);

    oldSwarm = last->getSwarm();
    swarm = newIteration->getSwarm();

    swarmSize = newIteration->getSwarmSize();

    //Build new generation
    Particle * parent1 = oldSwarm[0];
    Particle * parent2 = oldSwarm[0];
    int randomParentIndex;
    if(tournamentSize<3){
        tournamentSize=3;
    }
    for(int i=0; i<swarmSize; i++){
        for(int j=0; j<tournamentSize; j++){
            randomParentIndex = rand() % swarmSize;
            if(oldSwarm[randomParentIndex]->getFitnessValue() < parent1->getFitnessValue()){
                parent1 = oldSwarm[randomParentIndex];
            }else if(oldSwarm[randomParentIndex]->getFitnessValue() < parent2->getFitnessValue()){
                parent2 = oldSwarm[randomParentIndex];
            }
        }
        crossover(parent1,parent2,swarm[i]);
    }

    //Add mutations
    for(int i=0; i<swarmSize; i++){
        mutate(swarm[i]);
    }

    snapshotManager->enqueue(newIteration);
}

void GeneticAlgorithm::crossover(Particle * parent1, Particle * parent2, Particle * child){
    double *childPosition = new double[2];
    childPosition[0] = parent1->getPositionArrayPointer()[0];
    childPosition[1] = parent2->getPositionArrayPointer()[1];
    child->setParticlePosition(childPosition);
    childPosition[0] = parent1->getPersonalBestPos()[0];
    childPosition[1] = parent1->getPersonalBestPos()[1];
    child->setPersonalBestPosition(childPosition);
    child->setPersonalBest(parent1->getPersonalBest());
}

void GeneticAlgorithm::mutate(Particle *particle) {
    double *newPosition = particle->getPositionArrayPointer();
    double xRange = bounds[1]-bounds[0];
    double yRange = bounds[3]-bounds[2];

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
    fitness = objectiveFunction->functionInput(newPosition);
    particle->setFitnessValue(fitness);
    if(particle->getFitnessValue() < particle->getPersonalBest()){
        particle->setPersonalBestPosition(newPosition);
        particle->setPersonalBest(particle->getFitnessValue());
    }

    if(ideal == nullptr ||
       ideal != nullptr && particle->getPersonalBest() < ideal->getPersonalBest()) {
        ideal = particle;
    }
}
