//
// Created by matheu on 2016/09/09.
//

#ifndef LEARNINGOGL_WINDOW_H
#define LEARNINGOGL_WINDOW_H


#include <SDL2/SDL.h>
#include <string>


    enum WindowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

class Window
{
public:
    Window();
    ~Window();

    int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);

    void swapBuffer();

    int getScreenWidth() { return _screenWidth; }
    int getScreenHeight() { return _screenHeight; }

    SDL_Window* getWindowInstance();
private:
    SDL_Window* _sdlWindow;
    int _screenWidth, _screenHeight;
};


#endif //LEARNINGOGL_WINDOW_H
