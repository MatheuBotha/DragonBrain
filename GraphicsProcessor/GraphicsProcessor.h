//
// Created by matheu on 2016/10/04.
//

#ifndef SWARMVIZ_GRAPHICSPROCESSOR_H
#define SWARMVIZ_GRAPHICSPROCESSOR_H

#include "Engine/Window.h"
#include "Engine/GLSLProgram.h"
#include "../OPT/GenOPT/src/ObjectiveFunction.h"
#include "../SettingsPackage/src/problemdomainsettingspackage.h"


class GraphicsProcessor {

public:
    GraphicsProcessor(ProblemDomainSettingsPackage pdsp);
    ~GraphicsProcessor();
    void run();

    void setObjective(ObjectiveFunction* objective);

protected:
private:
    Window window;
    GLSLProgram shaderProgram;
    SDL_Event event;

    ProblemDomainSettingsPackage pdsp;
    ObjectiveFunction* objective;
    int* boundaries;
};


#endif //SWARMVIZ_GRAPHICSPROCESSOR_H
