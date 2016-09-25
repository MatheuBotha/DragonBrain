#include "GraphicsProcessor.h"

#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/FPSLimiter.h"

#include "LandscapeEngine/Landscape2D.h"

#include <SDL2/SDL.h>
#include <iostream>

GraphicsProcessor::GraphicsProcessor() :
    _screenWidth(640),
    _screenHeight(480),
    _runState(RunState::PLAY)
{
    // Empty
}

GraphicsProcessor::~GraphicsProcessor() {
    // IMPLEMENT THIS!
    delete _landscape;
}

void GraphicsProcessor::run() {
    // IMPLEMENT THIS!
    initSystems();
    initLandscape();

    loop();
}

void GraphicsProcessor::initSystems() {
    GraphicsEngine::init();

    _window.create("Temp Title", 800, 640, 0);

    initShaders();
}

void GraphicsProcessor::initLandscape()
{
//    _landscape = new Landscape2D();
//    _landscape->init();
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

    GraphicsEngine::FPSLimiter fpsLimiter;
    fpsLimiter.setMaxFPS(60.0f);

    while(_runState == RunState::PLAY)
    {
        fpsLimiter.begin();

        processInput();

//        _landscape->draw();
        draw();

        _fps = fpsLimiter.end();
    }
}

void GraphicsProcessor::processInput() {
    SDL_Event evnt;
    //Will keep looping until there are no more events to process
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_QUIT:
                // Exit the game here!
                _runState = RunState::EXIT;
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

    _textureProgram.use();
    // IMPLEMENT THIS!

    // Draw code goes here
    glActiveTexture(GL_TEXTURE0);

    // Make sure the shader uses texture 0
    GLint textureUniform = _textureProgram.getUniformLocation("mySampler");
    glUniform1i(textureUniform, 0);

    // Grab the camera matrix
    glm::mat4 projectionMatrix = _camera.getCameraMatrix();
    GLint pUniform = _textureProgram.getUniformLocation("P");
    glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);



    _textureProgram.unuse();
    // Swap our buffer and draw everything to the screen!
    _window.swapBuffer();
}