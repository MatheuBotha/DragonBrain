//
// Created by matheu on 10/5/16.
//

#ifndef SWARMVIZ_LANDSCAPE_H
#define SWARMVIZ_LANDSCAPE_H



#include <GL/glew.h>

#include "GLSLProgram.h"

class Landscape {
public:
    Landscape(GLSLProgram textureProgram);
    ~Landscape();

    void draw();

private:
    GLSLProgram textureProgram;

    struct point {
        GLfloat x;
        GLfloat y;
    };

    GLuint VBO;
};


#endif //SWARMVIZ_LANDSCAPE_H
