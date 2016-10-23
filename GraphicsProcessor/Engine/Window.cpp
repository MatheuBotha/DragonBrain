//
// Created by matheu on 9/8/16.
//
#include "Window.h"
#include "Errors.h"

#include <GL/glew.h>


Window::Window()
{
}


Window::~Window()
{
    SDL_DestroyWindow(_sdlWindow);
}

int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags) {

    Uint32 flags = SDL_WINDOW_OPENGL;
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;

    if (currentFlags & INVISIBLE) {
        flags |= SDL_WINDOW_HIDDEN;
    }
    if (currentFlags & FULLSCREEN) {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    if (currentFlags & BORDERLESS) {
        flags |= SDL_WINDOW_BORDERLESS;
    }

    //Open an SDL window
    _sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
    if (_sdlWindow == nullptr) {
        fatalError("SDL Window could not be created!");
    }

    //Set up our OpenGL context
    SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
    if (glContext == nullptr) {
        fatalError("SDL_GL context could not be created!");
    }

    //Set up glew (optional but recommended)
    glewExperimental = GL_TRUE;
    GLenum error = glewInit();
    if (error != GLEW_OK) {
        fatalError("Could not initialize glew!");
    }

    //Check the OpenGL version
    //std::printf("***   OpenGL Version: %s   ***\n", glGetString(GL_VERSION));

    //Set VSYNC


    // Enable alpha blend
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    return 0;
}

void Window::swapBuffer() {
    SDL_GL_SwapWindow(_sdlWindow);
}

SDL_Window* Window::getWindowInstance()
{
    return _sdlWindow;
}