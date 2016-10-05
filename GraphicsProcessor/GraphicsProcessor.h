//
// Created by matheu on 2016/10/04.
//

#ifndef SWARMVIZ_GRAPHICSPROCESSOR_H
#define SWARMVIZ_GRAPHICSPROCESSOR_H

#include "Engine/Window.h"
#include "Engine/GLSLProgram.h"
#include "../OPT/GenOPT/src/ObjectiveFunction.h"


class GraphicsProcessor {

public:
    GraphicsProcessor(ObjectiveFunction* objective);
    ~GraphicsProcessor();
    void run();
protected:
private:
    Window window;
    GLSLProgram shaderProgram;
    SDL_Event event;

    ObjectiveFunction* objective;
};


#endif //SWARMVIZ_GRAPHICSPROCESSOR_H
