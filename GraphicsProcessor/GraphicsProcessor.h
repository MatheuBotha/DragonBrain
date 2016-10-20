//
// Created by matheu on 2016/10/04.
//

#ifndef SWARMVIZ_GRAPHICSPROCESSOR_H
#define SWARMVIZ_GRAPHICSPROCESSOR_H

#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Window.h"
#include "Engine/GLSLProgram.h"
#include "../OPT/GenOPT/src/ObjectiveFunction.h"
#include "../SettingsPackage/src/problemdomainsettingspackage.h"
#include "../SnapshotManager/SnapshotManager.h"
#include "Engine/ParticleSystem.h"
#include "Engine/Camera.h"
#include "Engine/Timer.h"


class GraphicsProcessor {

public:
    GraphicsProcessor(ProblemDomainSettingsPackage pdsp, SnapshotManager** snapshotManagers,
                      int width, int height, unsigned int animationSpeed, int numInstances);
    ~GraphicsProcessor();
    void run();

    void setObjective(ObjectiveFunction* objective);
    void setBounds(double* boundaries);



protected:
private:
    int screenWidth;
    int screenHeight;
    Window window;
    Camera* camera;
    GLfloat cameraYaw;
    GLfloat cameraPitch;
    GLSLProgram shaderProgram;
    GLSLProgram particleShaderProgram;
    GLSLProgram sphereShaderProgram;
    GLSLProgram boundingBoxShaderProgram;
    GLSLProgram skyboxShadingProgram;
    Timer timer;
    SDL_Event event;

    ProblemDomainSettingsPackage pdsp;
    SnapshotManager** snapshotManagers;
    ObjectiveFunction* objective;
    double* boundaries;

    ParticleSystem** particleSystems;
    unsigned int animationSpeed;

    bool isFocused;
    int numInstances;
    glm::vec3** instanceLocations;
};


#endif //SWARMVIZ_GRAPHICSPROCESSOR_H
