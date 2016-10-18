//
// Created by matheu on 2016/10/18.
//

#include "Sphere.h"
#include <SDL2/SDL.h>
// Other Libs
#include <SOIL/SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sphere::Sphere(GLSLProgram shaderProgram)
{
    model = glm::mat4(1.0f);
    this->shaderProgram = shaderProgram;

    VAO = 0;
    VBO = 0;
    VIO = 0;

    lats = 40;
    longs = 40;

    int i, j;
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    int indicator = 0;
    for(i = 0; i <= lats; i++) {
        double lat0 = glm::pi<double>() * (-0.5 + (double) (i - 1) / lats);
        double z0  = sin(lat0);
        double zr0 =  cos(lat0);

        double lat1 = glm::pi<double>() * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);

        for(j = 0; j <= longs; j++) {
            double lng = 2 * glm::pi<double>() * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);

            vertices.push_back(x * zr0);
            vertices.push_back(y * zr0);
            vertices.push_back(z0);
            indices.push_back(indicator);
            indicator++;

            vertices.push_back(x * zr1);
            vertices.push_back(y * zr1);
            vertices.push_back(z1);
            indices.push_back(indicator);
            indicator++;
        }
        indices.push_back(GL_PRIMITIVE_RESTART_FIXED_INDEX);
    }

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray (0);

    glGenBuffers(1, &VIO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VIO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

    numsToDraw = indices.size();


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

Sphere::~Sphere()
{
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}




void Sphere::draw(GLfloat deltaTime)
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
    projection = glm::perspective(45.0f, 1.0f * 800 / 600, 0.1f, 10.0f);

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
    glEnable(GL_PRIMITIVE_RESTART);
    glPrimitiveRestartIndex(GL_PRIMITIVE_RESTART_FIXED_INDEX);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VIO);
    glDrawElements(GL_QUAD_STRIP, numsToDraw, GL_UNSIGNED_INT, NULL);
    glBindVertexArray(0);

    shaderProgram.unuse();
}

void Sphere::activateShader()
{
    shaderProgram.use();
}

void Sphere::deactivateShader()
{
    shaderProgram.unuse();
}

void Sphere::rotate(GLfloat angle, glm::vec3 rotationVector)
{
    model = glm::rotate(model, angle, rotationVector);
}

void Sphere::scale(glm::vec3 scaleVector)
{
    model = glm::scale(model, scaleVector);
}

void Sphere::translate(glm::vec3 location)
{
    model = glm::translate(model, location);
}

void Sphere::setModel()
{
    model = glm::mat4();
}

void Sphere::setCamera(Camera* camera)
{
    this->camera = camera;
}




