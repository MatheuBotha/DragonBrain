//
// Created by matheu on 2016/10/04.
//

#include "GraphicsProcessor.h"

#include <iostream>

#include "Engine/Debug.h"
#include "Engine/Engine.h"
#include "Engine/Camera.h"
#include "Engine/Landscape2D.h"
#include "Engine/Cube.h"

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
bool keys[1024];
GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

GraphicsProcessor::GraphicsProcessor(ProblemDomainSettingsPackage pdsp) : pdsp(pdsp){
    std::cout << "Starting Graphics Processor Test" << std::endl;
    //init SDL stuffz
    Engine::init();

    //make a window
    window.create("Temp Title", 800, 600, 0);

    //Create the shader program
    shaderProgram.compileShaders("Shaders/VertexShader.glsl", "Shaders/FragmentShader.glsl");
    shaderProgram.linkShaders();

    boundaries = new double[4];
    pdsp.getBoundaries(boundaries);
}

GraphicsProcessor::~GraphicsProcessor(){
    shaderProgram.unuse();
    shaderProgram.dispose();
    std::cout << "Ending Graphics Processor Test" << std::endl;
}

void GraphicsProcessor::run(){

    Landscape2D l(shaderProgram, objective, boundaries);

    while(true){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
            {
                return;
            }

            // Set frame time
            GLfloat currentFrame = SDL_GetTicks()/1000;
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            switch( event.type ){
                /* Look for a keypress */
                case SDL_KEYDOWN:
                    /* Check the SDLKey values and move change the coords */
                    switch( event.key.keysym.sym ){
                        case SDLK_q:
                            return;
                            break;
                        case SDLK_LEFT:
                            Debug::print("Moving LEFT");
                            camera.ProcessKeyboard(LEFT, deltaTime);
                            break;
                        case SDLK_RIGHT:
                            camera.ProcessKeyboard(RIGHT, deltaTime);
                            break;
                        case SDLK_UP:
                            camera.ProcessKeyboard(FORWARD, deltaTime);
                            break;
                        case SDLK_DOWN:
                            camera.ProcessKeyboard(BACKWARD, deltaTime);
                            break;
                        default:
                            break;
                    }
            }
        }
        //Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderProgram.use();

//        // Create camera transformation
//        glm::mat4 view;
//        view = camera.GetViewMatrix();
//        glm::mat4 projection;
//        projection = glm::perspective(camera.Zoom, (float)800/(float)600, 0.1f, 1000.0f);
//        // Get the uniform locations
//        GLint viewLoc = shaderProgram.getUniformLocation("view");
//        GLint projLoc = shaderProgram.getUniformLocation("projection");
//
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));


        l.draw();


        shaderProgram.unuse();
        window.swapBuffer();
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
