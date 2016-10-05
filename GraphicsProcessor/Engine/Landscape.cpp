//
// Created by matheu on 10/5/16.
//

#include "Landscape.h"
#include "Debug.h"
#include <iostream>
#include <math.h>
#include <sstream>


Landscape2D::Landscape2D(GLSLProgram textureProgram){

    // Create the vertex buffer object


    // Create our own temporary buffer
    point graph[2000];

    // Fill it in just like an array
    for (int i = 0; i < 2000; i++) {
        float x = (i) / 2000.0;
        graph[i].x = x;
        graph[i].y = sin(x);

        std::ostringstream ssx;
        ssx << x;
        std::string sx("x" + ssx.str());

        std::ostringstream ssy;
        ssy << sin(x);
        std::string sy("y" + ssy.str());

        Debug::print(sx);
        Debug::print(sy);
    }


//    point graph[3];
//
//    graph[0].x = 0;
//    graph[0].y = 0;
//
//    graph[1].x = 1;
//    graph[1].y = 1;
//
//    graph[2].x = 1;
//    graph[2].y = 0;

    // Tell OpenGL to copy our array to the buffer object
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof graph, graph, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 1 * sizeof(point), (GLvoid*)0);
    glEnableVertexAttribArray(0);

}
Landscape2D::~Landscape2D(){}

void Landscape2D::draw(){

    /* Draw using the vertices in our vertex buffer object */
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_LINE_STRIP, 0, 2000);
}
