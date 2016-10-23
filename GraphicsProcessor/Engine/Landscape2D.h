//
// Created by matheu on 9/26/16.
//

#ifndef LEARNINGOGL_LANDSCAPE2D_H
#define LEARNINGOGL_LANDSCAPE2D_H

#include <GL/glew.h>

#include "GLSLProgram.h"
#include "../../OPT/GenOPT/src/ObjectiveFunction.h"
#include "Camera.h"
#include "Mesh.h"

class Landscape2D : public Mesh {
public:
    Landscape2D(GLSLProgram textureProgram, ObjectiveFunction* objective, double* boundaries);
    ~Landscape2D();
    void draw();
    void activateShader();
    void deactivateShader();
    void rotate(GLfloat angle, glm::vec3 rotationVector);
    void scale(glm::vec3 scaleVector);
    void translate(glm::vec3 location);
    void setModel();
    void setModel(glm::mat4 model);

    void setObjective(ObjectiveFunction* objective);
    ObjectiveFunction* getObjective();

    double* getBoundaries();
    double getZMin();
    double getZMax();
    double normalize(double value);

    void setCamera(Camera* camera);

private:
    GLSLProgram textureProgram;
    Camera* camera;
    ObjectiveFunction* objective;
    double* boundaries;

    GLint uniform_vertex_transform;
    GLint uniform_color;
    GLuint texture_id;
    GLint uniform_mytexture;

    bool interpolate = true;
    bool clamp = true;
    bool rotateFactor = false;
    bool polygonoffset = true;

    GLuint vbo[3];

    double zMin;
    double zMax;

    glm::mat4 model;

    const unsigned int N = 1200;
};


#endif //LEARNINGOGL_LANDSCAPE2D_H
