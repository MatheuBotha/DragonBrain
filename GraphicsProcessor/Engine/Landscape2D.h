//
// Created by matheu on 9/26/16.
//

#ifndef LEARNINGOGL_LANDSCAPE2D_H
#define LEARNINGOGL_LANDSCAPE2D_H

#include <GL/glew.h>

#include "GLSLProgram.h"
#include "../../OPT/GenOPT/src/ObjectiveFunction.h"

class Landscape2D {
public:
    Landscape2D(GLSLProgram textureProgram, ObjectiveFunction* objective, double* boundaries);
    ~Landscape2D();
    void draw();

    void setObjective(ObjectiveFunction* objective);

private:
    GLSLProgram textureProgram;
    ObjectiveFunction* objective;
    double* boundaries;

    GLint attribute_coord2d;
    GLint uniform_vertex_transform;
    GLint uniform_texture_transform;
    GLint uniform_color;
    GLuint texture_id;
    GLint uniform_mytexture;

    float offset_x = 0.0;
    float offset_y = 0.0;
    float scale = 1.0;

    bool interpolate = false;
    bool clamp = false;
    bool rotate = false;
    bool polygonoffset = true;

    GLuint vbo[3];
};


#endif //LEARNINGOGL_LANDSCAPE2D_H
