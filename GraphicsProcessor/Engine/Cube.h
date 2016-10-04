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
    Cube(GLSLProgram textureProgram, Texture texture);
    ~Cube();
    glm::vec3 modelLocation;
    void draw();

    Texture getTexture();
    void setTexture();

protected:

private:
    GLuint VAO, VBO, EBO;
    Texture texture;
    GLSLProgram textureProgram;
};


#endif //LEARNINGOGL_CUBE_H
