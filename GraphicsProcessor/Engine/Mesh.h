//
// Created by matheu on 2016/10/04.
//

#ifndef SWARMVIZ_MESH_H
#define SWARMVIZ_MESH_H


#include <GL/glew.h>
#include <glm/vec3.hpp>

class Mesh {
public:
    virtual void draw(GLfloat deltaTime);

    virtual void activateShader();
    virtual void deactivateShader();

    virtual void rotate(GLfloat angle, glm::vec3 rotationVector);
    virtual void scale(glm::vec3 scaleVector);
    virtual void translate(glm::vec3 location);
};


#endif //SWARMVIZ_MESH_H
