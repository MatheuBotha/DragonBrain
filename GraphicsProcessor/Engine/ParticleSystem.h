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

protected:
private:
    SnapshotManager* snapshotManager;
    GLSLProgram shaderProgram;
    Landscape2D* landscape;
    Camera* camera;

    Mesh* particle;
};


#endif //SWARMVIZ_PARTICLESYSTEM_H
