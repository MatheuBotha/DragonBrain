//
// Created by matheu on 9/8/16.
//

#ifndef DRAGONBRAIN_LANDSCAPE_H
#define DRAGONBRAIN_LANDSCAPE_H

#include <GL/glew.h>
#include <SDL2/SDL.h>


class Landscape {

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
    GLint uniform_offset_x;
    GLint uniform_scale_x;
    GLint uniform_sprite;
    GLuint texture_id;
    GLint uniform_mytexture;

    float offset_x = 0.0;
    float scale_x = 1.0;
    int mode = 0;

    struct point {
        GLfloat x;
        GLfloat y;
    };

    GLuint vbo;
};


#endif //DRAGONBRAIN_LANDSCAPE_H
