//
// Created by matheu on 10/6/16.
//

#include <SDL/SDL_timer.h>
#include "ParticleSystem.h"
#include "Cube.h"

ParticleSystem::ParticleSystem(SnapshotManager* snapshotManager, GLSLProgram shaderProgram, Landscape2D* landscape)
{
    this->snapshotManager = snapshotManager;
    this->fromSnapshot = snapshotManager->dequeue();
    this->toSnapshot = snapshotManager->dequeue();
    animationSpeed = 100;
    animationTime = 1;
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

    int stagnantParticles = 0;

    for(int i=0; i<fromSnapshot->getSwarmSize(); ++i)
    {
        glm::vec3 currentPosition = getCurrentPosition(fromSnapshot->getSwarm()[i], toSnapshot->getSwarm()[i]);

//        printf("Comming from\n");
//        printParticleDetails(fromSnapshot->getSwarm()[i]);
//
//        printf("Going to\n");
//        printParticleDetails(toSnapshot->getSwarm()[i]);

        printf("Current Position\n");
        printf("x = %f\n", currentPosition.x);
        printf("y = %f\n", currentPosition.y);
        printf("z = %f\n", currentPosition.z);


        particle->setModel();
        //particle->translate(glm::vec3(scaleX(-1), scaleZ(-1), scaleY(1)));

        if(
                animationSpeed == animationTime || fromSnapshot == toSnapshot
//                getParticleVector(toSnapshot->getSwarm()[i]).x != currentPosition.x ||
//           getParticleVector(toSnapshot->getSwarm()[i]).y != currentPosition.y ||
//           getParticleVector(toSnapshot->getSwarm()[i]).z != currentPosition.z
        )
        {
            printf("\n\n\n\n\n\n\nDone animating\n\n\n\n\n\n\n");
            particle->translate(scaleParticleVector(getParticleVector(toSnapshot->getSwarm()[i])));
            stagnantParticles++;

        }
        else
        {
            printf("still animating\n");
            particle->translate(scaleParticleVector(currentPosition));
        }

        particle->scale(glm::vec3(0.1f));
        particle->rotate(glm::radians(SDL_GetTicks() / 10.0f), glm::vec3(0.0f, 1.0f, 1.0f));
        //particle->translate(glm::vec3(0.0f,0.0f,0.3f));
        particle->draw(deltaTime);

    }

    if(
            //stagnantParticles == fromSnapshot->getSwarmSize())
        animationSpeed == animationTime
            )
    {
        fromSnapshot = toSnapshot;
        toSnapshot = snapshotManager->dequeue();
        animationTime = 0;
    } else
    {
        animationTime++;
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

glm::vec3 ParticleSystem::getCurrentPosition(Particle* from, Particle* to)
{
    glm::vec3 fromPosition = getParticleVector(from);

    glm::vec3 toPosition = getParticleVector(to);

    glm::vec3 direction = toPosition - fromPosition;
    //direction = direction / 1200.0f;

    glm::vec3 currentPosition = fromPosition + (direction * (float(animationTime)/animationSpeed));

    double params[2];
    params[0] = currentPosition.x;
    params[1] = currentPosition.z;
    currentPosition.y = landscape->getObjective()->functionInput(params);

    return currentPosition;
}

glm::vec3 ParticleSystem::getParticleVector(Particle* particle)
{
    return glm::vec3(
            particle->getPositionArrayPointer()[0], //x
            particle->getFitnessValue(), //y
            particle->getPositionArrayPointer()[1] //z
    );
}

void ParticleSystem::printParticleDetails(Particle* particle)
{
    glm::vec3 currentPos = getParticleVector(particle);

    printf("x = %f\n", currentPos.x);
    printf("y = %f\n", currentPos.y);
    printf("z = %f\n", currentPos.z);
}

glm::vec3 ParticleSystem::scaleParticleVector(glm::vec3 particleVector)
{
    particleVector.x = scaleX(particleVector.x);
    particleVector.y = scaleZ(particleVector.y);
    particleVector.z = scaleY(particleVector.z);

    return particleVector;
}