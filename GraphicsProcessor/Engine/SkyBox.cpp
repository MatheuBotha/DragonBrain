//
// Created by matheu on 2016/10/20.
//

#include "SkyBox.h"

#include <SDL2/SDL.h>
// Other Libs
#include <SOIL/SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

SkyBox::SkyBox(GLSLProgram shaderProgram)
{
    model = glm::mat4(1.0f);
    this->shaderProgram = shaderProgram;

    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat skyboxVertices[] = {
            // Positions
            -1.0f,  1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

            -1.0f,  1.0f, -1.0f,
            1.0f,  1.0f, -1.0f,
            1.0f,  1.0f,  1.0f,
            1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
            1.0f, -1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
            1.0f, -1.0f,  1.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glBindVertexArray(0); // Unbind VAO

    // Cubemap (Skybox)
    std::vector<const GLchar*> faces;
    faces.push_back("Textures/SkyBox/sor_cwd/cwd_rt.JPG");
    faces.push_back("Textures/SkyBox/sor_cwd/cwd_lf.JPG");
    faces.push_back("Textures/SkyBox/sor_cwd/cwd_up.JPG");
    faces.push_back("Textures/SkyBox/sor_cwd/cwd_dn.JPG");
    faces.push_back("Textures/SkyBox/sor_cwd/cwd_bk.JPG");
    faces.push_back("Textures/SkyBox/sor_cwd/cwd_ft.JPG");

//    faces.push_back("Textures/SkyBox/mp_majestic/majestic_rt.tga");
//    faces.push_back("Textures/SkyBox/mp_majestic/majestic_lf.tga");
//    faces.push_back("Textures/SkyBox/mp_majestic/majestic_up.tga");
//    faces.push_back("Textures/SkyBox/mp_majestic/majestic_dn.tga");
//    faces.push_back("Textures/SkyBox/mp_majestic/majestic_bk.tga");
//    faces.push_back("Textures/SkyBox/mp_majestic/majestic_ft.tga");
    cubemapTexture = loadCubemap(faces);
    printf("loaded cubemap\n");
}

SkyBox::~SkyBox()
{
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void SkyBox::draw(GLfloat deltaTime)
{
    shaderProgram.use();
    //printf("Drawing SkyBox\n");
    // Bind Textures using texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glUniform1i(shaderProgram.getUniformLocation("ourTexture1"), 0);

    // Create transformations
    glm::mat4 view;
    glm::mat4 projection;

    view = camera->getViewMatrix();
    projection = camera->getProjectionMatrix();

    // Get their uniform location
    GLint modelLoc = shaderProgram.getUniformLocation("model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    GLint viewLoc = shaderProgram.getUniformLocation("view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    GLint projLoc = shaderProgram.getUniformLocation("projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    //Drawing of the cube
    // Draw skybox first
    glDepthMask(GL_FALSE);// Remember to turn depth writing off
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthMask(GL_TRUE);
}

void SkyBox::activateShader()
{
    shaderProgram.use();
}

void SkyBox::deactivateShader()
{
    shaderProgram.unuse();
}

void SkyBox::rotate(GLfloat angle, glm::vec3 rotationVector)
{
    model = glm::rotate(model, angle, rotationVector);
}

void SkyBox::scale(glm::vec3 scaleVector)
{
    model = glm::scale(model, scaleVector);
}

void SkyBox::translate(glm::vec3 location)
{
    model = glm::translate(model, location);
}

void SkyBox::setModel()
{
    model = glm::mat4();
}

void SkyBox::setModel(glm::mat4 model)
{
    this->model = model;
}

void SkyBox::setCamera(Camera* camera)
{
    this->camera = camera;
}

// Loads a cubemap texture from 6 individual texture faces
// Order should be:
// +X (right)
// -X (left)
// +Y (top)
// -Y (bottom)
// +Z (front)
// -Z (back)
GLuint SkyBox::loadCubemap(std::vector<const GLchar*> faces)
{
    GLuint textureID;
    glGenTextures(1, &textureID);

    int width,height;
    unsigned char* image;

    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
    for(GLuint i = 0; i < faces.size(); i++)
    {
//        image = SOIL_load_image(faces[i], &width, &height, 0, SOIL_LOAD_RGB);
        int channels = 1;
        image = SOIL_load_image(faces[i], &width, &height, &channels, SOIL_LOAD_AUTO);
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        SOIL_free_image_data(image);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

    return textureID;
}
