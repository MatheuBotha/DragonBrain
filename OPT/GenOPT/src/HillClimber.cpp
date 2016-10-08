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

    for(int i=0; i<swarmSize; i++){
        if(printer)        std::cout << "Particle " << i;
        double * truck = new double[2];
        swarm[i]->getPositionArray(truck);
        if(printer) cout << "\nbefore mutate: " << truck[0] << " " << truck[1];
        mutate(swarm[i]);
        swarm[i]->getPositionArray(truck);
        if(printer) cout << "\nafter mutate: " << truck[0] << " " << truck[1];

        delete truck;
        if(printer)        std::cout << " is at coords (" << swarm[i]->getPositionArrayPointer()[0] << ", "
                                     << swarm[i]->getPositionArrayPointer()[1] << ") has fitness of: "
                                     << swarm[i]->getFitnessValue() << " and personal best of: "
                                     << swarm[i]->getPersonalBest() << std::endl;
    }
    if(printer) std::cout << "ITERATION COMPLETE. CURRENT BEST: " << ideal->getPersonalBest() << std::endl;
    snapshotManager->enqueue(newIteration);
}

void HillClimber::mutate(Particle *particle) {

    double *newPosition = particle->getPositionArrayPointer();

    for (int i = 0; i < 2; ++i) {
        newPosition[i]+=(mutationRate*newPosition[i]*(((double)rand()/(double)RAND_MAX)-0.5));
    }
    if (newPosition[1]==DBL_MAX)
    {
        if (checkSpecificBound(bounds[0],bounds[1],newPosition[0])==false)
        {
            int c=checkProximityDistances(bounds[0],bounds[1],newPosition[0]);

            if (c==1)
            {
                newPosition[0]=bounds[1];
            }else{
                newPosition[0]=bounds[0];
            }
        }
    } else {
            if (checkSpecificBound(bounds[0],bounds[1],newPosition[0])==false)
            {
                int c=checkProximityDistances(bounds[0],bounds[1],newPosition[0]);

                if (c==1)
                {
                    newPosition[0]=bounds[1];
                } else
                {
                    newPosition[0]=bounds[0];
                }
            }
            if (checkSpecificBound(bounds[2],bounds[3],newPosition[1])==false)
            {
                int c=checkProximityDistances(bounds[2],bounds[3],newPosition[1]);

                if (c==1)
                {
                    newPosition[1]=bounds[3];
                } else
                {
                    newPosition[1]=bounds[2];
                }
            }
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


    particle->setParticlePosition(newPosition);
}
