//
// Created by matheu on 2016/10/04.
//

#include "GraphicsProcessor.h"

#include <iostream>

#include "Engine/Debug.h"
#include "Engine/Engine.h"
#include "Engine/Camera.h"
#include "Engine/Landscape2D.h"
#include "Engine/ParticleSystem.h"
#include "Engine/Cube.h"
#include "Engine/BoundingBox.h"

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL/SDL_video.h>

// Camera
GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

GraphicsProcessor::GraphicsProcessor(ProblemDomainSettingsPackage pdsp) : pdsp(pdsp){
    std::cout << "Starting Graphics Processor Test" << std::endl;
    //init SDL stuffz
    Engine::init();

    //make a window
    window.create("SwarmVis", 800, 600, 0);

    //Create the shader program
    shaderProgram.compileShaders("Shaders/landscape2d.vertex.glsl", "Shaders/landscape2d.fragment.glsl");
    shaderProgram.linkShaders();

    boundaries = new double[4];
    pdsp.getBoundaries(boundaries);

    this->snapshotManager = NULL;
}

GraphicsProcessor::GraphicsProcessor(ProblemDomainSettingsPackage pdsp, SnapshotManager* snapshotManager, int width, int height)
:
screenWidth(width),
screenHeight(height)
{
    std::cout << "Starting Graphics Processor Test" << std::endl;
    //init SDL stuffz
    Engine::init();

    //make a window
    window.create("SwarmVis", screenWidth, screenHeight, 0);

    //Create the shader program
    shaderProgram.compileShaders("Shaders/landscape2d.vertex.glsl", "Shaders/landscape2d.fragment.glsl");
    shaderProgram.linkShaders();

    particleShaderProgram.compileShaders("Shaders/cube.vertex.glsl", "Shaders/cube.fragment.glsl");
    particleShaderProgram.linkShaders();

    sphereShaderProgram.compileShaders("Shaders/sphere.vertex.glsl", "Shaders/sphere.fragment.glsl");
    sphereShaderProgram.linkShaders();

    boundingBoxShaderProgram.compileShaders("Shaders/bounding_box.vertex.glsl", "Shaders/bounding_box.fragment.glsl");
    boundingBoxShaderProgram.linkShaders();

    boundaries = new double[4];
    pdsp.getBoundaries(boundaries);

    this->snapshotManager = snapshotManager;

    camera = new Camera(glm::vec3(0.0f, 2.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90, -45);
    SDL_ShowCursor(SDL_DISABLE);

    timer.setMaxFPS(60.0f);
}


GraphicsProcessor::~GraphicsProcessor(){
    shaderProgram.unuse();
    shaderProgram.dispose();
    delete camera;
    delete boundaries;
    delete particleSystem;
    std::cout << "Ending Graphics Processor Test" << std::endl;
}

void GraphicsProcessor::run(){
    Landscape2D l(shaderProgram, objective, boundaries);
    l.setCamera(camera);
    printf("Making Particle System\n");
    particleSystem = new ParticleSystem(snapshotManager, sphereShaderProgram, &l);
    particleSystem->setCamera(camera);
    particleSystem->setAnimationSpeed(50);
    printf("Finished making particle system\n");

    BoundingBox bb(boundingBoxShaderProgram);
    bb.setCamera(camera);


    while(true){
        timer.begin();
        // Set frame time
        GLfloat currentFrame = SDL_GetTicks()/1;
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
            {
                return;
            }

            switch( event.type ){
                /* Look for a keypress */
                case SDL_KEYDOWN:
                    /* Check the SDLKey values and move change the coords */
                    switch( event.key.keysym.sym ){
                        case SDLK_q:
                            return;
                        case SDLK_LEFT:
                        case SDLK_a:
                            camera->ProcessKeyboard(LEFT, deltaTime/1000);
                            break;
                        case SDLK_RIGHT:
                        case SDLK_d:
                            camera->ProcessKeyboard(RIGHT, deltaTime/1000);
                            break;
                        case SDLK_UP:
                        case SDLK_w:
                            camera->ProcessKeyboard(FORWARD, deltaTime/1000);
                            break;
                        case SDLK_DOWN:
                        case SDLK_s:
                            camera->ProcessKeyboard(BACKWARD, deltaTime/1000);
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    cameraPitch = event.motion.x - screenWidth/2;
                    cameraYaw = screenHeight/2-event.motion.y;  // Reversed since y-coordinates go from bottom to left

                    SDL_WarpMouseInWindow(window.getWindowInstance(), screenWidth/2, screenHeight/2);
                    SDL_PumpEvents();
                    SDL_GetKeyboardState(NULL);

                    camera->ProcessMouseMovement(cameraPitch, cameraYaw);
                    break;
            }
        }
        //Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        
        shaderProgram.use();
        l.draw();
        shaderProgram.unuse();

        particleSystem->draw(deltaTime);

        bb.activateShader();
        bb.setModel();
        bb.translate(glm::vec3(0.0f, 0.5f, 0.0f));
        bb.scale(glm::vec3(2.0f, 1.0f, 2.0f));
        bb.draw(deltaTime);
        bb.deactivateShader();

        window.swapBuffer();
        //std::cout << "fps = " << timer.end() << std::endl;
        timer.end();
    }

}

void GraphicsProcessor::setObjective(ObjectiveFunction* objective)
{
    this->objective = objective;
}

void GraphicsProcessor::setBounds(double* boundaries)
{
    this->boundaries = boundaries;
}
