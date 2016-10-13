//
// Created by matheu on 10/6/16.
//

#include <SDL/SDL_timer.h>
#include "ParticleSystem.h"
#include "Cube.h"

ParticleSystem::ParticleSystem(SnapshotManager* snapshotManager, GLSLProgram shaderProgram, Landscape2D* landscape)
{
    this->snapshotManager = snapshotManager;
    this->shaderProgram = shaderProgram;
    this->landscape = landscape;

    printf("xMin = %f\n", landscape->getBoundaries()[0]);
    printf("xMax = %f\n", landscape->getBoundaries()[1]);

    printf("yMin = %f\n", landscape->getBoundaries()[2]);
    printf("yMax = %f\n", landscape->getBoundaries()[3]);

    printf("zMin = %f\n", landscape->getZMin());
    printf("zMax = %f\n", landscape->getZMax());


    particle = new Cube(shaderProgram);
    //analyzeSnapshotManager();
}

ParticleSystem::~ParticleSystem(){}

void ParticleSystem::draw(GLfloat deltaTime)
{


    particle->activateShader();
//    particle->setModel();
//    //particle->rotate(deltaTime/1000, glm::vec3(1.0f, 0.3f, 0.5f));
//    particle->translate(glm::vec3( 0.0f,  1.0f, 1.0f));
//    particle->translate(glm::vec3( 1.0f,  0.0f, 0.0f));
//
//    particle->draw(deltaTime);


    //Loop through snapshot and draw each particle
    for(int j=0; j<snapshotManager->getBound(); ++j)
    {
        //printf("Snapshot %i\n", j);
        Snapshot s = snapshotManager->dequeue();

        //printf("Swarm Size = %i\n", s.getSwarmSize());

        Particle** swarm = s.getSwarm();
        for(int i=0; i<s.getSwarmSize(); ++i)
        {
//            printf("Particle %i\n", i);


            //get the x y position
            double* pos = new double[2];
            swarm[i]->getPositionArray(pos);
            printf("x = %f\n", pos[0]);
            printf("scaled x = %f\n", scaleX(pos[0]));
            printf("y = %f\n", pos[1]);
            printf("scaled y = %f\n", scaleY(pos[1]));
            printf("z = %f\n", swarm[i]->getFitnessValue());
            printf("normalized z = %f\n", scaleZ(swarm[i]->getFitnessValue()));
            printf("\n\n");

            particle->setModel();
            //particle->translate(glm::vec3(scaleX(-1), scaleZ(-1), scaleY(1)));
            particle->translate(glm::vec3(scaleX(pos[0]), scaleZ(swarm[i]->getFitnessValue()), scaleY(pos[1])));
            particle->scale(glm::vec3(0.1f));
            particle->rotate(glm::radians(SDL_GetTicks() / 10.0f), glm::vec3(0.0f, 1.0f, 1.0f));
            //particle->translate(glm::vec3(0.0f,0.0f,0.3f));
            particle->draw(deltaTime);


        }
    }

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

double ParticleSystem::scaleX(double value)
{
    double min = landscape->getBoundaries()[0];
    double max = landscape->getBoundaries()[1];
    return ((((1-(-1))*(value - min))/(max - min))-1);
}

double ParticleSystem::scaleY(double value)
{
    double min = landscape->getBoundaries()[2];
    double max = landscape->getBoundaries()[3];
    return ((((1-(-1))*(value - min))/(max - min))-1);
}

double ParticleSystem::scaleZ(double value)
{
    double min = landscape->getZMin();
    double max = landscape->getZMax();
    return ((((1-(0))*(value - min))/(max - min)));
}

void ParticleSystem::setCamera(Camera* camera)
{
    this->camera = camera;
    particle->setCamera(camera);
}