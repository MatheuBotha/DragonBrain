//
// Created by matheu on 2016/10/08.
//

#include <iostream>
#include "../Engine/Engine.h"
#include "../Engine/Window.h"
#include "../Engine/GLSLProgram.h"
#include "../Engine/Texture.h"
#include "../Engine/Cube.h"

int main()
{

    std::cout << "Starting Cube Test" << std::endl;
    //init SDL stuffz
    Engine::init();

    //make a window
    Window window;
    window.create("Cube Test", 800, 600, 0);
    //Create the shader program
    GLSLProgram shaderProgram;
    shaderProgram.compileShaders("Shaders/cube.vertex.glsl", "Shaders/cube.fragment.glsl");
    shaderProgram.linkShaders();

    SDL_Event event;

    //Set up drawables
//    Texture texture1("Textures/container.jpg");
//    Texture texture2("Textures/awesomeface.png");
//    Cube cube(shaderProgram, &texture1, &texture2);
    Cube cube(shaderProgram);
    cube.scale(glm::vec3(0.5f));

    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;



    while(true){

        // Set frame time
        GLfloat currentFrame = SDL_GetTicks()/1;
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
            {
                return 0;
            }
        }
        //Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        cube.activateShader();

        cube.rotate(deltaTime/1000, glm::vec3(1.0f, 0.3f, 0.5f));

        cube.draw();

        cube.deactivateShader();

        window.swapBuffer();
    }
}
