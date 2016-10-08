//
// Created by matheu on 10/6/16.
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(SnapshotManager* snapshotManager)
{
    this->snapshotManager = snapshotManager;
    analyzeSnapshotManager();
}

ParticleSystem::~ParticleSystem(){}

void ParticleSystem::draw()
{

}

void ParticleSystem::analyzeSnapshotManager()
{
    printf("Starting Analysis\n");

    for(int j=0; j<snapshotManager->getBound(); ++j)
    {
        printf("Snapshot %i\n", j);
        Snapshot s = snapshotManager->dequeue();

        printf("Swarm Size = %i\n", s.getSwarmSize());

        Particle** swarm = s.getSwarm();
        for(int i=0; i<s.getSwarmSize(); ++i)
        {
            printf("Particle %i\n", i);

            //get the x y position
            double* pos = new double[2];
            swarm[i]->getPositionArray(pos);
            printf("x = %f\n", pos[0]);
            printf("y = %f\n", pos[1]);
            printf("z = %f\n", swarm[i]->getFitnessValue());
        }
    }
}