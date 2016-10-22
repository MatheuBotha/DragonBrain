//
// Created by matheu on 10/9/16.
//

#ifndef SWARMVIZ_BOUNDINGBOX_H
#define SWARMVIZ_BOUNDINGBOX_H


#include "Mesh.h"
#include "GLSLProgram.h"

class BoundingBox : public Mesh {

public:
    BoundingBox(GLSLProgram shaderProgram);
    ~BoundingBox();
    void draw(GLfloat deltaTime);

    void activateShader();
    void deactivateShader();

    void rotate(GLfloat angle, glm::vec3 rotationVector);
    void scale(glm::vec3 scaleVector);
    void translate(glm::vec3 location);

    void setModel();

    void setCamera(Camera* camera);

private:
    GLSLProgram shaderProgram;
    Camera* camera;
    GLuint VBO, VAO;
    glm::mat4 model;
    GLuint _texture1;
};


#endif //SWARMVIZ_BOUNDINGBOX_H
