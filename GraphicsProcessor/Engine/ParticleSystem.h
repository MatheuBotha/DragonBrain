//
// Created by matheu on 10/6/16.
//

#ifndef SWARMVIZ_PARTICLESYSTEM_H
#define SWARMVIZ_PARTICLESYSTEM_H


#include "../../SnapshotManager/SnapshotManager.h"
#include "GLSLProgram.h"
#include "Mesh.h"

class ParticleSystem {
public:
    ParticleSystem(SnapshotManager* snapshotManager, GLSLProgram shaderProgram);
    ~ParticleSystem();
    void draw(GLfloat deltaTime);
    void analyzeSnapshotManager();
protected:
private:
    SnapshotManager* snapshotManager;
    GLSLProgram shaderProgram;

    Mesh* particle;
};


#endif //SWARMVIZ_PARTICLESYSTEM_H
