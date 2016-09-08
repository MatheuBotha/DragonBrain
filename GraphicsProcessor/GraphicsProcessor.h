//
// Created by matheu on 9/7/16.
//

#ifndef DRAGONBRAIN_GRAPHICSPROCESSOR_H
#define DRAGONBRAIN_GRAPHICSPROCESSOR_H

#include "GraphicsEngine/Window.h"
#include "GraphicsEngine/GLSLProgram.h"
#include "GraphicsEngine/Camera2D.h"
#include "GraphicsEngine/InputManager.h"

enum class RunState {
    PLAY,
    EXIT
};

class GraphicsProcessor
{
public:
    GraphicsProcessor();
    ~GraphicsProcessor();

    /// Runs the game
    void run();

private:
    /// Initializes the core systems
    void initSystems();

    /// Initializes the shaders
    void initShaders();

    /// Main game loop for the program
    void loop();

    /// Handles input processing
    void processInput();

    /// Renders the game
    void draw();

    /// Member Variables
    GraphicsEngine::Window _window; ///< The game window

    GraphicsEngine::GLSLProgram _textureProgram; ///< The shader program

    GraphicsEngine::InputManager _inputManager; ///< Handles input

    GraphicsEngine::Camera2D _camera; ///< Main Camera

    int _screenWidth, _screenHeight, _fps;

    RunState _runState;
};

#endif //DRAGONBRAIN_GRAPHICSPROCESSOR_H
