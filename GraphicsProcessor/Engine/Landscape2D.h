//
// Created by matheu on 9/26/16.
//

#ifndef LEARNINGOGL_LANDSCAPE2D_H
#define LEARNINGOGL_LANDSCAPE2D_H

#include <GL/glew.h>

#include "GLSLProgram.h"

class Landscape2D {
public:
    Landscape2D(GLSLProgram textureProgram);
    ~Landscape2D();

    void draw();

private:
    GLSLProgram textureProgram;

    struct point {
        GLfloat x;
        GLfloat y;
    };

    GLuint VBO;
};


#endif //LEARNINGOGL_LANDSCAPE2D_H
