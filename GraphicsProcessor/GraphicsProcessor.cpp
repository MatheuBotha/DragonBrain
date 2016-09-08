#include "GraphicsProcessor.h"

#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/"

#include <SDL2/SDL.h>
#include <iostream>

GraphicsProcessor::GraphicsProcessor() :
    _screenWidth(800),
    _screenHeight(600),
    _runState(RunState::PLAY)
{
    // Empty
}

GraphicsProcessor::~GraphicsProcessor() {
    // IMPLEMENT THIS!
}

void GraphicsProcessor::run() {
    // IMPLEMENT THIS!
}

void GraphicsProcessor::initSystems() {
    GraphicsEngine::init();

    _window.create("Temp Title", 800, 640, 0);

    initShaders();
}

void GraphicsProcessor::initShaders() {
    // Compile our color shader
    _textureProgram.compileShaders("Shaders/textureShading.vert", "Shaders/textureShading.frag");
    _textureProgram.addAttribute("vertexPosition");
    _textureProgram.addAttribute("vertexColor");
    _textureProgram.addAttribute("vertexUV");
    _textureProgram.linkShaders();
}

void GraphicsProcessor::loop() {
    // IMPLEMENT THIS!

    while(_runState == RunState::PLAY)
    {

    }
}

void GraphicsProcessor::processInput() {
    SDL_Event evnt;
    //Will keep looping until there are no more events to process
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_QUIT:
                // Exit the game here!
                break;
            case SDL_MOUSEMOTION:
                _inputManager.setMouseCoords(evnt.motion.x, evnt.motion.y);
                break;
            case SDL_KEYDOWN:
                _inputManager.pressKey(evnt.key.keysym.sym);
                break;
            case SDL_KEYUP:
                _inputManager.releaseKey(evnt.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                _inputManager.pressKey(evnt.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                _inputManager.releaseKey(evnt.button.button);
                break;
        }
    }
}

void GraphicsProcessor::draw() {
    // Set the base depth to 1.0
    glClearDepth(1.0);
    // Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // IMPLEMENT THIS!

    // Swap our buffer and draw everything to the screen!
    _window.swapBuffer();
}