//
// Created by matheu on 9/26/16.
//

#include "Landscape2D.h"
#include "Debug.h"
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Landscape2D::Landscape2D(GLSLProgram textureProgram, ObjectiveFunction* objective, int* boundaries) : textureProgram(textureProgram), objective(objective), boundaries(boundaries)
{
    textureProgram.addAttribute("coord2d");
    uniform_vertex_transform = textureProgram.getUniformLocation("vertex_transform");
    uniform_texture_transform = textureProgram.getUniformLocation("texture_transform");
    uniform_mytexture = textureProgram.getUniformLocation("mytexture");
    uniform_color = textureProgram.getUniformLocation("color");

    // Create our datapoints, store it as bytes
#define N 256

    //set up graph variables

    int xMin = boundaries[0];
    int xMax = boundaries[1];
    int yMin = boundaries[2];
    int yMax = boundaries[3];

    printf("xMin = %i\n", xMin);
    printf("xMax = %i\n", xMax);
    printf("yMin = %i\n", yMin);
    printf("yMax = %i\n", yMax);

    double xRange = (double)(xMax - xMin)/(double)N;
    double yRange = (double)(yMax - yMin)/(double)N;

    printf("xMin = %i\n", xMin);
    printf("xMax = %i\n", xMax);
    printf("yMin = %i\n", yMin);
    printf("yMax = %i\n", yMax);

    printf("xRange = %.2f\n", xRange);
    printf("yRange = %.2f\n", yRange);

    GLfloat results[N][N];
    GLbyte graph[N][N];

    int increment = 1;
    int cx = 0;
    int cy = 0;

    double currentX = (double)xMin;
    double currentY = (double)yMin;

    double zMax = DBL_MIN;
    double zMin = DBL_MAX;

    printf("currentX = %f\n", currentX);
    printf("currentY = %f\n", currentY);

    printf("Starting Loop\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

//            float x = (i - N / 2) / (N / 2.0);
//            float y = (j - N / 2) / (N / 2.0);
//            float d = hypotf(x, y) * 4.0;
//            float z = (1 - d * d) * expf(d * d / -2.0);
//            float z = sin(x) * sin(y);
//            graph[cx][cy] = roundf(z * 127 + 128);

            double* parameters = new double[2];
            parameters[0] = currentX;
            parameters[1] = currentY;
            results[i][j] = objective->functionInput(parameters);
            delete parameters;

            if(results[i][j] > zMax)
            {
                zMax = results[i][j];
            }

            if(results[i][j] < zMin)
            {
                zMin = results[i][j];
            }


            //printf("%d\t\t-\t\t%i\n", result, (signed)graph[i][j]);
            printf("currentX = %f\n",currentX);
            printf("currentY = %f\n",currentY);
            printf("result = %f\n",results[i][j]);
            currentY+=yRange;
        }
        currentY = yMin;
        currentX+=xRange;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //graph[i][j] = roundf(((((1-(-1))*(results[i][j] - zMin))/(zMax - zMin))-1) * 127 + 128);
        }
    }

    /* Upload the texture with our datapoints */
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, N, N, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, graph);

    // Create two vertex buffer objects
    glGenBuffers(3, vbo);

    // Create an array for 101 * 101 vertices
    glm::vec2 vertices[101][101];

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            vertices[i][j].x = (j - 50) / 51.0;
            vertices[i][j].y = (i - 50) / 51.0;
        }
    }

    // Tell OpenGL to copy our array to the buffer objects
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);

    // Create an array of indices into the vertex array that traces both horizontal and vertical lines
    GLushort indices[100 * 100 * 6];
    int i = 0;

    for (int y = 0; y < 101; y++) {
        for (int x = 0; x < 100; x++) {
            indices[i++] = y * 101 + x;
            indices[i++] = y * 101 + x + 1;
        }
    }

    for (int x = 0; x < 101; x++) {
        for (int y = 0; y < 100; y++) {
            indices[i++] = y * 101 + x;
            indices[i++] = (y + 1) * 101 + x;
        }
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 100 * 101 * 4 * sizeof *indices, indices, GL_STATIC_DRAW);

    // Create another array of indices that describes all the triangles needed to create a completely filled surface
    i = 0;

    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            indices[i++] = y * 101 + x;
            indices[i++] = y * 101 + x + 1;
            indices[i++] = (y + 1) * 101 + x + 1;

            indices[i++] = y * 101 + x;
            indices[i++] = (y + 1) * 101 + x + 1;
            indices[i++] = (y + 1) * 101 + x;
        }
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof indices, indices, GL_STATIC_DRAW);
}
Landscape2D::~Landscape2D(){}

void Landscape2D::draw(){
    glUniform1i(uniform_mytexture, 0);

    glm::mat4 model;

//    if (rotate)
//        model = glm::rotate(glm::mat4(1.0f), glm::radians(SDL_GetTicks() / 100.0f), glm::vec3(0.0f, 0.0f, 1.0f));
//
//    else
//        model = glm::mat4(1.0f);
    model = glm::rotate(glm::mat4(1.0f), glm::radians(SDL_GetTicks() / 100.0f), glm::vec3(0.0f, 0.0f, 1.0f));


    glm::mat4 view = glm::lookAt(glm::vec3(0.0, -2.0, 2.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 projection = glm::perspective(45.0f, 1.0f * 640 / 480, 0.1f, 10.0f);

    glm::mat4 vertex_transform = projection * view * model;
    glm::mat4 texture_transform = glm::translate(glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, 1)), glm::vec3(offset_x, offset_y, 0));

    glUniformMatrix4fv(uniform_vertex_transform, 1, GL_FALSE, glm::value_ptr(vertex_transform));
    glUniformMatrix4fv(uniform_texture_transform, 1, GL_FALSE, glm::value_ptr(texture_transform));

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Set texture wrapping mode */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, clamp ? GL_CLAMP_TO_EDGE : GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, clamp ? GL_CLAMP_TO_EDGE : GL_REPEAT);

    /* Set texture interpolation mode */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, interpolate ? GL_LINEAR : GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, interpolate ? GL_LINEAR : GL_NEAREST);

    /* Draw the triangles, a little dark, with a slight offset in depth. */
    GLfloat grey[4] = { 0.5, 0.5, 0.5, 1 };
    glUniform4fv(uniform_color, 1, grey);

    glEnable(GL_DEPTH_TEST);

    if (polygonoffset) {
        glPolygonOffset(1, 0);
        glEnable(GL_POLYGON_OFFSET_FILL);
    }

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
    glDrawElements(GL_TRIANGLES, 100 * 100 * 6, GL_UNSIGNED_SHORT, 0);

    glPolygonOffset(0, 0);
    glDisable(GL_POLYGON_OFFSET_FILL);

    /* Draw the grid, very bright */
    GLfloat bright[4] = { 2, 2, 2, 1 };
    glUniform4fv(uniform_color, 1, bright);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
    glDrawElements(GL_LINES, 100 * 101 * 4, GL_UNSIGNED_SHORT, 0);

    /* Stop using the vertex buffer object */
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Landscape2D::setObjective(ObjectiveFunction* objective)
{
    this->objective = objective;
}
