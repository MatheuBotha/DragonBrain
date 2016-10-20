//
// Created by matheu on 2016/10/18.
//

#ifndef SWARMVIZ_SPHERE_H
#define SWARMVIZ_SPHERE_H


#include "Mesh.h"
#include "GLSLProgram.h"

class Sphere : public Mesh {
public:
    Sphere(GLSLProgram shaderProgram);
    ~Sphere();
    void draw(GLfloat deltaTime);

    void activateShader();
    void deactivateShader();

    void rotate(GLfloat angle, glm::vec3 rotationVector);
    void scale(glm::vec3 scaleVector);
    void translate(glm::vec3 location);

    void setModel();
    void setModel(glm::mat4 model);

    void setCamera(Camera* camera);
protected:

private:
    GLSLProgram shaderProgram;
    Camera* camera;

    GLuint _texture1;
    GLuint _texture2;

    GLuint VBO, VAO, VIO;
    int lats, longs;
    int numsToDraw;

    glm::mat4 model;
};


#endif //SWARMVIZ_SPHERE_H