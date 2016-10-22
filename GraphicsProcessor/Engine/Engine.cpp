//
// Created by matheu on 9/8/16.
//
#include "Engine.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

namespace Engine
{
    int init() {
        //Initialize SDL
        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_GL_SetSwapInterval(1);

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

        return 0;
    }
}

