//
// Created by matheu on 10/6/16.
//

#include <SDL/SDL_timer.h>
#include "ParticleSystem.h"
#include "Cube.h"
#include "Sphere.h"
#include "Sphere2.h"
bool twoD = false;

ParticleSystem::ParticleSystem(SnapshotManager* snapshotManager, GLSLProgram shaderProgram, Landscape2D* landscape)
{
    model = glm::mat4(1.0f);
    this->snapshotManager = snapshotManager;
    this->fromSnapshot = snapshotManager->dequeue();
    this->toSnapshot = snapshotManager->dequeue();

    currentRotation = new glm::vec3[this->fromSnapshot->getSwarmSize()];
    animationSpeed = 100;
    animationTime = 1;
    globalBestGrowth = 0;
    this->shaderProgram = shaderProgram;
    this->landscape = landscape;

    if(fromSnapshot->getSwarm()[0]->getPositionAtDimension(1) == DBL_MAX)
        twoD = true;
    printf("xMin = %f\n", landscape->getBoundaries()[0]);
    printf("xMax = %f\n", landscape->getBoundaries()[1]);

    printf("yMin = %f\n", landscape->getBoundaries()[2]);
    printf("yMax = %f\n", landscape->getBoundaries()[3]);

    printf("zMin = %f\n", landscape->getZMin());
    printf("zMax = %f\n", landscape->getZMax());


    particle = new Sphere2(shaderProgram);
    //analyzeSnapshotManager();
}

ParticleSystem::~ParticleSystem(){}

void ParticleSystem::draw(GLfloat deltaTime)
{
    particle->activateShader();

    int stagnantParticles = 0;

    for(int i=0; i<fromSnapshot->getSwarmSize(); ++i)
    {
//        printf("Particle:\n");
//        printParticleDetails(fromSnapshot->getSwarm()[i]);
//        printf("/Particle\n");
        particle->setModel(model);
        if(animationSpeed == animationTime || fromSnapshot == toSnapshot)
        {
            particle->translate(scaleParticleVector(getParticleVector(toSnapshot->getSwarm()[i])));
            particle->translate(glm::vec3(0.0f,0.04f,0.0f));
            particle->rotate(glm::radians(SDL_GetTicks() / 10.0f), currentRotation[i]);

            stagnantParticles++;
        }
        else
        {
            glm::vec3 currentPosition = scaleParticleVector(getCurrentPosition(fromSnapshot->getSwarm()[i], toSnapshot->getSwarm()[i]));

            currentRotation[i] = glm::vec3(currentPosition.x, 0, currentPosition.z);
            particle->translate(currentPosition);
            particle->translate(glm::vec3(0.0f,0.04f,0.0f));
            particle->rotate(glm::radians(SDL_GetTicks() / 10.0f), currentRotation[i]);
        }

        particle->scale(glm::vec3(0.05f));
        particle->draw(deltaTime);
    }

    if(fromSnapshot->getGBest())
    {
        particle->setModel(model);
        if(animationSpeed == animationTime || fromSnapshot == toSnapshot)
        {
            particle->translate(scaleParticleVector(getParticleVector(toSnapshot->getGBest())));
            particle->translate(glm::vec3(0.0f,0.04f,0.0f));
            particle->rotate(glm::radians(SDL_GetTicks() / 10.0f), glm::vec3(1,1,1));
        }
        else
        {
            glm::vec3 currentPosition = scaleParticleVector(
                    getCurrentPosition(
                            fromSnapshot->getGBest(),
                            toSnapshot->getGBest()
                    )
            );

            particle->translate(currentPosition);
            particle->translate(glm::vec3(0.0f,0.04f,0.0f));
            particle->rotate(glm::radians(SDL_GetTicks() / 10.0f), glm::vec3(1,1,1));
        }

        particle->scale(glm::vec3(0.05f) * globalBestGrowth);
        particle->draw(deltaTime);
        if(globalBestGrowth < 2)
        {
            globalBestGrowth += 0.01;
        }
    }

    if(animationSpeed == animationTime)
    {
        fromSnapshot = toSnapshot;
        toSnapshot = snapshotManager->dequeue();
        animationTime = 0;
    }
    else
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

glm::vec3 ParticleSystem::getCurrentDirection(Particle* from, Particle* to)
{
    glm::vec3 fromPosition = getParticleVector(from);

    glm::vec3 toPosition = getParticleVector(to);

    return toPosition - fromPosition;

}

glm::vec3 ParticleSystem::getCurrentPosition(Particle* from, Particle* to)
{
    glm::vec3 direction = getCurrentDirection(from, to);
    glm::vec3 currentPosition = getParticleVector(from) + (direction * (float(animationTime)/animationSpeed));

    double params[2];
    params[0] = currentPosition.x;
    params[1] = currentPosition.z;
    currentPosition.y = landscape->getObjective()->functionInput(params);
    if(twoD) {
        from->setPositionAtDimension(0.0, 1);
                to->setPositionAtDimension(0.0,1);
        currentPosition.z = 0;
    }
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

void ParticleSystem::setAnimationSpeed(unsigned int animationSpeed)
{
    this->animationSpeed = animationSpeed;
}

void ParticleSystem::activateShader()
{
    shaderProgram.use();
}

void ParticleSystem::deactivateShader()
{
    shaderProgram.unuse();
}

void ParticleSystem::rotate(GLfloat angle, glm::vec3 rotationVector)
{
    model = glm::rotate(model, angle, rotationVector);
}

void ParticleSystem::scale(glm::vec3 scaleVector)
{
    model = glm::scale(model, scaleVector);
}

void ParticleSystem::translate(glm::vec3 location)
{
    model = glm::translate(model, location);
}

void ParticleSystem::setModel()
{
    model = glm::mat4();
}

void ParticleSystem::setModel(glm::mat4 model)
{
    this->model = model;
}