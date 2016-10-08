//
// Created by matheu on 2016/10/04.
//

#ifndef SWARMVIZ_GRAPHICSPROCESSOR_H
#define SWARMVIZ_GRAPHICSPROCESSOR_H

#include "Engine/Window.h"
#include "Engine/GLSLProgram.h"
#include "../OPT/GenOPT/src/ObjectiveFunction.h"
#include "../SettingsPackage/src/problemdomainsettingspackage.h"
#include "../SnapshotManager/SnapshotManager.h"
#include "Engine/ParticleSystem.h"


class GraphicsProcessor {

public:
    GraphicsProcessor(ProblemDomainSettingsPackage pdsp);
    GraphicsProcessor(ProblemDomainSettingsPackage pdsp, SnapshotManager* snapshotManager);
    ~GraphicsProcessor();
    void run();

    void setObjective(ObjectiveFunction* objective);
    void setBounds(double* boundaries);

protected:
private:
    Window window;
    GLSLProgram shaderProgram;
    GLSLProgram particleShaderProgram;
    SDL_Event event;

    ProblemDomainSettingsPackage pdsp;
    SnapshotManager* snapshotManager;
    ObjectiveFunction* objective;
    double* boundaries;

    ParticleSystem* particleSystem;
};


#endif //SWARMVIZ_GRAPHICSPROCESSOR_H
