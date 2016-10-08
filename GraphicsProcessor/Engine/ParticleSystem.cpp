//
// Created by matheu on 10/6/16.
//

#include "ParticleSystem.h"
#include "Cube.h"

ParticleSystem::ParticleSystem(SnapshotManager* snapshotManager, GLSLProgram shaderProgram)
{
    this->snapshotManager = snapshotManager;
    this->shaderProgram = shaderProgram;
    particle = new Cube(shaderProgram);
    //analyzeSnapshotManager();
}

ParticleSystem::~ParticleSystem(){}

void ParticleSystem::draw(GLfloat deltaTime)
{
    particle->activateShader();
    particle->rotate(deltaTime/1000, glm::vec3(1.0f, 0.3f, 0.5f));
    particle->draw(deltaTime);
    particle->deactivateShader();
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