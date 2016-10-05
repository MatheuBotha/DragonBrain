//
// Created by matheu on 9/26/16.
//

#include "Landscape2D.h"
#include "Debug.h"
#include <iostream>
#include <math.h>
#include <sstream>


Landscape2D::Landscape2D(GLSLProgram textureProgram){
    program = create_program("graph.v.glsl", "graph.f.glsl");
    if (program == 0)
        return 0;

    attribute_coord2d = get_attrib(program, "coord2d");
    uniform_vertex_transform = get_uniform(program, "vertex_transform");
    uniform_texture_transform = get_uniform(program, "texture_transform");
    uniform_mytexture = get_uniform(program, "mytexture");
    uniform_color = get_uniform(program, "color");

    if (attribute_coord2d == -1 || uniform_vertex_transform == -1 || uniform_texture_transform == -1 || uniform_mytexture == -1)
        return 0;

    // Create our datapoints, store it as bytes
#define N 256
    GLbyte graph[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float x = (i - N / 2) / (N / 2.0);
            float y = (j - N / 2) / (N / 2.0);
            float d = hypotf(x, y) * 4.0;
            float z = (1 - d * d) * expf(d * d / -2.0);

            graph[i][j] = roundf(z * 127 + 128);
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
            vertices[i][j].x = (j - 50) / 50.0;
            vertices[i][j].y = (i - 50) / 50.0;
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

}
