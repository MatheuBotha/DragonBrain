//
// Created by matheu on 2016/10/18.
//

#include "Sphere2.h"
#include <SDL2/SDL.h>
// Other Libs
#include <SOIL/SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>
#include <vector>

inline void push_indices(std::vector<GLushort>& indices, int sectors, int r, int s) {
    int curRow = r * sectors;
    int nextRow = (r+1) * sectors;

    indices.push_back(curRow + s);
    indices.push_back(nextRow + s);
    indices.push_back(nextRow + (s+1));

    indices.push_back(curRow + s);
    indices.push_back(nextRow + (s+1));
    indices.push_back(curRow + (s+1));
}

Sphere2::Sphere2(GLSLProgram shaderProgram)
{


    float radius = 1;
    unsigned int rings = 12;
    unsigned int sectors = 24;



    model = glm::mat4(1.0f);
    this->shaderProgram = shaderProgram;

    VAO = 0;
    VBO = 0;
    VIO = 0;

    float const R = 1./(float)(rings-1);
    float const S = 1./(float)(sectors-1);

    for(int r = 0; r < rings; ++r) {
        for(int s = 0; s < sectors; ++s) {
            float const y = sin( -M_PI_2 + M_PI * r * R );
            float const x = cos(2*M_PI * s * S) * sin( M_PI * r * R );
            float const z = sin(2*M_PI * s * S) * sin( M_PI * r * R );

            texcoords.push_back(s*S);
            texcoords.push_back(r*R);
            vertices.push_back(x * (radius));
            vertices.push_back(y * (radius));
            vertices.push_back(z * (radius));

            push_indices(indices, sectors, r, s);
        }
    }

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray (0);

    glGenBuffers(1, &VTO);
    glBindBuffer(GL_ARRAY_BUFFER, VTO);
    glBufferData(GL_ARRAY_BUFFER, texcoords.size() * sizeof(GLfloat), &texcoords[0], GL_STATIC_DRAW);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray (1);

    glGenBuffers(1, &VIO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VIO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0); // Unbind VAO

    // Load and create a texture

    // ====================
    // Texture 1
    // ====================
    glGenTextures(1, &_texture1);
    glBindTexture(GL_TEXTURE_2D, _texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    int width, height;
    unsigned char* image = SOIL_load_image("Textures/map.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}

Sphere2::~Sphere2()
{
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &VTO);
    glDeleteBuffers(1, &VIO);
}

void Sphere2::draw(GLfloat deltaTime)
{
    shaderProgram.use();
    //Bind Textures using texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture1);
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
    GLint projLoc = shaderProgram.getUniformLocation("projection");
    // Pass the matrices to the shader
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));


    // draw sphere
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    glBindVertexArray(0);

    shaderProgram.unuse();
}

void Sphere2::activateShader()
{
    shaderProgram.use();
}

void Sphere2::deactivateShader()
{
    shaderProgram.unuse();
}

void Sphere2::rotate(GLfloat angle, glm::vec3 rotationVector)
{
    model = glm::rotate(model, angle, rotationVector);
}

void Sphere2::scale(glm::vec3 scaleVector)
{
    model = glm::scale(model, scaleVector);
}

void Sphere2::translate(glm::vec3 location)
{
    model = glm::translate(model, location);
}

void Sphere2::setModel()
{
    model = glm::mat4();
}

void Sphere2::setModel(glm::mat4 model)
{
    this->model = model;
}

void Sphere2::setCamera(Camera* camera)
{
    this->camera = camera;
}




