//
// Created by gerard on 2016/10/09.
//

#include "ElitistHillClimber.h"
#include <iostream>


void ElitistHillClimber::iterate() {

    Snapshot *last;
    Snapshot *newIteration;
    Particle **swarm;
    int swarmSize;

    last = snapshotManager->getLast();

    newIteration = new Snapshot(last);
    if(printer){
        cout << "NEW ITERATION\n";
    }

    swarm = newIteration->getSwarm();

    swarmSize = newIteration->getSwarmSize();

    //Get best particle
    Particle * elite = swarm[0];
    for(int j=0; j<swarmSize; j++) {
        if(swarm[j]->getFitnessValue() < elite->getFitnessValue()){
            elite = swarm[j];
        }
    }
    elite = new Particle(elite);
    //Make all particles the same as the best particle
    for(int k=0; k<swarmSize; k++) {
        delete swarm[k];
        swarm[k] = new Particle(elite);
    }
    delete elite;

    //Mutate all the particles to be slightly different
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
    snapshotManager->enqueue(newIteration);
}

void ElitistHillClimber::mutate(Particle *particle) {
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

        for(int i=0; i<2; i++) {
            if (newPosition[i] < bounds[0]) {
                newPosition[i] = bounds[0];
            } else if (newPosition[i] > bounds[1]) {
                newPosition[i] = bounds[1];
            }
        }
    }

    double fitness;
    fitness = objectiveFunction->functionInput(newPosition);
    particle->setFitnessValue(fitness);
    if(particle->getFitnessValue() < particle->getPersonalBest()){
        //cout<<"CurrentFitness: "<<particle->getFitnessValue()<<endl;
        //cout<<"BestFitness: "<<particle->getPersonalBest()<<endl;
        particle->setPersonalBestPosition(newPosition);
        particle->setPersonalBest(particle->getFitnessValue());
//    if(printer)
        //      std::cout<<"New best: "<<fitness<<std::endl;

    }

    if(ideal == nullptr ||
       ideal != nullptr && particle->getPersonalBest() < ideal->getPersonalBest()) {
        ideal = particle;
    }

    particle->setParticlePosition(particle->getPersonalBestPos());
    particle->setFitnessValue(particle->getPersonalBest());
}