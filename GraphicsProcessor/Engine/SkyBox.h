//
// Created by matheu on 2016/10/20.
//

#ifndef SWARMVIZ_SKYBOX_H
#define SWARMVIZ_SKYBOX_H


#include "Mesh.h"
#include "GLSLProgram.h"

class SkyBox : public Mesh{
public:
    SkyBox(GLSLProgram shaderProgram);
    ~SkyBox();
    void draw(GLfloat deltaTime);

    void activateShader();
    void deactivateShader();

    void rotate(GLfloat angle, glm::vec3 rotationVector);
    void scale(glm::vec3 scaleVector);
    void translate(glm::vec3 location);

    void setModel();
    void setModel(glm::mat4 model);

    void setCamera(Camera* camera);

    GLuint loadCubemap(std::vector<const GLchar*> faces);
protected:

private:
    GLSLProgram shaderProgram;
    Camera* camera;

    GLuint _texture1;
    GLuint _texture2;

    GLuint VBO, VAO;

    glm::mat4 model;

    GLuint cubemapTexture;
};


#endif //SWARMVIZ_SKYBOX_H
