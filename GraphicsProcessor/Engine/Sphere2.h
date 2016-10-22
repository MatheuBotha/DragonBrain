//
// Created by matheu on 2016/10/18.
//

#ifndef SWARMVIZ_SPHERE2_H
#define SWARMVIZ_SPHERE2_H


#include "Mesh.h"
#include "GLSLProgram.h"

class Sphere2 : public Mesh {
public:
    Sphere2(GLSLProgram shaderProgram);

    ~Sphere2();

    void draw(GLfloat deltaTime);

    void activateShader();

    void deactivateShader();

    void rotate(GLfloat angle, glm::vec3 rotationVector);

    void scale(glm::vec3 scaleVector);

    void translate(glm::vec3 location);

    void setModel();
    void setModel(glm::mat4 model);

    void setCamera(Camera *camera);

protected:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normals;
    std::vector<GLfloat> texcoords;
    std::vector<GLushort> indices;

private:
    GLSLProgram shaderProgram;
    Camera *camera;

    GLuint _texture1;

    GLuint VAO;
    GLuint VBO;
    GLuint VTO;
    GLuint VIO;

    glm::mat4 model;
};


#endif //SWARMVIZ_SPHERE2_H
