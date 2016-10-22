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
#include "Engine/SkyBox.h"
#include "Engine/TextRenderer.h"
#include <sstream>

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

GraphicsProcessor::GraphicsProcessor(ProblemDomainSettingsPackage pdsp, SnapshotManager** snapshotManagers,
                                     int width, int height, unsigned int animationSpeed, int numInstances)
:
screenWidth(width),
screenHeight(height),
animationSpeed(animationSpeed),
numInstances(numInstances),
updateFPS(100),
currentFPS(0)
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

    skyboxShadingProgram.compileShaders("Shaders/sky_box.vertex.glsl", "Shaders/sky_box.fragment.glsl");
    skyboxShadingProgram.linkShaders();

    textShadingProgram.compileShaders("Shaders/text.vertex.glsl", "Shaders/text.fragment.glsl");
    textShadingProgram.linkShaders();

    boundaries = new double[4];
    pdsp.getBoundaries(boundaries);
    if(pdsp.getDimensions() == 1)
    {
        boundaries[2] =  0.000001;
        boundaries[3] = -0.000001;
    }
    this->snapshotManagers = snapshotManagers;
    this->particleSystems = new ParticleSystem*[numInstances];

    camera = new Camera(screenWidth, screenHeight, glm::vec3(0.0f, 2.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90, -45);
    SDL_ShowCursor(SDL_DISABLE);

    timer.setMaxFPS(60.0f);

    isFocused = false;

    instanceLocations = new glm::vec3*[numInstances];

    if(numInstances == 1)
    {
        instanceLocations[0] = new glm::vec3(0,0,0);
    }

    if(numInstances == 2)
    {
        instanceLocations[0] = new glm::vec3(-1.3,0,0);
        instanceLocations[1] = new glm::vec3(1.3,0,0);
    }

    if(numInstances == 4)
    {
        instanceLocations[0] = new glm::vec3(-1.3,0,-1.3);
        instanceLocations[1] = new glm::vec3(1.3,0,-1.3);
        instanceLocations[2] = new glm::vec3(-1.3,0,1.3);
        instanceLocations[3] = new glm::vec3(1.3,0,1.3);
    }
}


GraphicsProcessor::~GraphicsProcessor(){
    shaderProgram.unuse();
    shaderProgram.dispose();
    delete camera;
    delete boundaries;
    delete particleSystems;
    std::cout << "Ending Graphics Processor Test" << std::endl;
}

void GraphicsProcessor::run(){
    Landscape2D l(shaderProgram, objective, boundaries);
    l.setCamera(camera);
    printf("Making Particle System\n");
    for(int i=0; i<numInstances; ++i)
    {
        particleSystems[i] = new ParticleSystem(snapshotManagers[i], sphereShaderProgram, &l);
        particleSystems[i]->setCamera(camera);
        particleSystems[i]->setAnimationSpeed(animationSpeed);
    }
    printf("Finished making particle system\n");

    BoundingBox bb(boundingBoxShaderProgram);
    bb.setCamera(camera);

    SkyBox skybox(skyboxShadingProgram);
    skybox.setCamera(camera);
    skybox.scale(glm::vec3(10,10,10));

    TextRenderer textRenderer(textShadingProgram);
    textRenderer.setCamera(camera);


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

            if (event.type == SDL_WINDOWEVENT_FOCUS_GAINED)
            {

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
                    if(isFocused)
                    {
                        cameraPitch = event.motion.x - screenWidth/2;
                        cameraYaw = screenHeight/2-event.motion.y;  // Reversed since y-coordinates go from bottom to left

                        SDL_WarpMouseInWindow(window.getWindowInstance(), screenWidth/2, screenHeight/2);
                        SDL_PumpEvents();
                        SDL_GetKeyboardState(NULL);

                        camera->ProcessMouseMovement(cameraPitch, cameraYaw);
                    }
                    else if(event.motion.x == screenWidth/2 && event.motion.y == screenHeight/2)
                    {
                        isFocused=true;
                    }
                    else
                    {
                        SDL_WarpMouseInWindow(window.getWindowInstance(), screenWidth/2, screenHeight/2);
                        SDL_PumpEvents();
                        SDL_GetKeyboardState(NULL);
                    }
                    break;
                case SDL_WINDOWEVENT_ENTER:

                    break;
            }
        }
        //Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        skybox.draw(deltaTime);

        for(int i=0; i<numInstances; ++i)
        {
            l.setModel();
            l.translate(*instanceLocations[i]);
            l.draw();
            particleSystems[i]->setModel();
            particleSystems[i]->translate(*instanceLocations[i]);
            particleSystems[i]->draw(deltaTime);
//            textRenderer.setModel();
//            textRenderer.translate(*instanceLocations[i]);
//            textRenderer.translate(glm::vec3(1,1,-1));
//            //textRenderer.rotate(glm::radians(-90.0f),glm::vec3(0,1,0));
//            //textRenderer.rotate(glm::radians(-45.0f),glm::vec3(1,0,1));
//            textRenderer.scale(glm::vec3(0.005f));
//            textRenderer.renderText(
//                    snapshotManagers[i]->getAlgorithmName(),
//                    0.0f,
//                    0.0f,
//                    1.0f,
//                    glm::vec3(float(51)/255, float(102)/255, float(255)/255)
//            );
        }


//        updateFPS++;
//        textRenderer.setModel();
//        textRenderer.translate(glm::vec3(-6,0,0));
//        textRenderer.rotate(glm::radians(90.0f),glm::vec3(0,1,0));
//        textRenderer.scale(glm::vec3(0.005f));
//        std::ostringstream buff;
//        buff<<currentFPS;
//        textRenderer.renderText("fps: " + buff.str(), 0.0f, 0.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));

//        bb.activateShader();
//        bb.setModel();
//        bb.translate(glm::vec3(0.0f, 0.5f, 0.0f));
//        bb.scale(glm::vec3(2.0f, 1.0f, 2.0f));
//        bb.draw(deltaTime);
//        bb.deactivateShader();

        window.swapBuffer();
        //std::cout << "fps = " << timer.end() << std::endl;
        if(updateFPS > currentFPS/2)
        {
            currentFPS = timer.end();
            updateFPS = 0;
        }
        else
        {
            timer.end();
        }
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
