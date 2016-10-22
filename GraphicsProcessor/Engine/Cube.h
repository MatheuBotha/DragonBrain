//
// Created by matheu on 9/26/16.
//

#ifndef LEARNINGOGL_CUBE_H
#define LEARNINGOGL_CUBE_H


#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Mesh.h"
#include "GLSLProgram.h"
#include "Texture.h"

class Cube : public Mesh {

public:
    Cube(GLSLProgram shaderProgram);
    Cube(GLSLProgram shaderProgram, Texture* texture1, Texture* texture2);
    ~Cube();
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
    Texture* texture1;
    Texture* texture2;
    Camera* camera;

    GLuint _texture1;
    GLuint _texture2;

    GLuint VBO, VAO;

    glm::mat4 model;
};


#endif //LEARNINGOGL_CUBE_H
