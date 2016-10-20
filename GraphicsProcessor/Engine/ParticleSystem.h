//
// Created by matheu on 10/6/16.
//

#ifndef SWARMVIZ_PARTICLESYSTEM_H
#define SWARMVIZ_PARTICLESYSTEM_H


#include "../../SnapshotManager/SnapshotManager.h"
#include "GLSLProgram.h"
#include "Mesh.h"
#include "Landscape2D.h"

class ParticleSystem {
public:
    ParticleSystem(SnapshotManager* snapshotManager, GLSLProgram shaderProgram, Landscape2D* landscape);
    ~ParticleSystem();
    void draw(GLfloat deltaTime);
    void analyzeSnapshotManager();

    double scaleX(double value);

    double scaleY(double value);

    double scaleZ(double value);

    void setCamera(Camera* camera);

    glm::vec3 getCurrentDirection(Particle* from, Particle* to);

    glm::vec3 getCurrentPosition(Particle* from, Particle* to);

    glm::vec3 getParticleVector(Particle* particle);

    glm::vec3 scaleParticleVector(glm::vec3 particleVector);

    void printParticleDetails(Particle* particle);

    void setAnimationSpeed(unsigned int animationSpeed);



protected:
private:
    SnapshotManager* snapshotManager;
    GLSLProgram shaderProgram;
    Landscape2D* landscape;
    Camera* camera;

    Mesh* particle;

    //Animation
    Snapshot* fromSnapshot;
    Snapshot* toSnapshot;
    glm::vec3 currentDirection;
    glm::vec3 currentPosition;
    unsigned int animationSpeed;
    unsigned int animationTime;

    glm::vec3* currentRotation;


};


#endif //SWARMVIZ_PARTICLESYSTEM_H
