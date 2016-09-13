//
// Created by matheu on 9/9/16.
//

#ifndef DRAGONBRAIN_LANDSCAPE3D_H
#define DRAGONBRAIN_LANDSCAPE3D_H

#include <GL/glew.h>
#include <SDL2/SDL.h>




class Landscape3D {

public:
    int init_resources();
    void free_resources();
    void display();
    void keyDown(SDL_KeyboardEvent *ev);
    void windowEvent(SDL_WindowEvent *ev);
    void mainLoop(SDL_Window *window);
    int run();

    GLuint program;
    GLint attribute_coord2d;
    GLint uniform_vertex_transform;
    GLint uniform_texture_transform;
    GLint uniform_color;
    GLuint texture_id;
    GLint uniform_mytexture;

    float offset_x = 0.0;
    float offset_y = 0.0;
    float scale = 1.0;

    bool interpolate = false;
    bool clamp = false;
    bool rotate = false;
    bool polygonoffset = true;

    GLuint vbo[3];
};


#endif //DRAGONBRAIN_LANDSCAPE3D_H
