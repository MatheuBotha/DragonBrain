//
// Created by matheu on 2016/10/18.
//


#include <iostream>
#include "../Engine/Engine.h"
#include "../Engine/Window.h"
#include "../Engine/GLSLProgram.h"
#include "../Engine/Texture.h"
#include "../Engine/Cube.h"
#include "../Engine/Sphere.h"
#include "../Engine/Sphere2.h"

int main()
{

    std::cout << "Starting Sphere Test" << std::endl;
    //init SDL stuffz
    Engine::init();

    //make a window
    Window window;
    window.create("Sphere Test", 800, 600, 0);

    Camera* camera;
    camera = new Camera(glm::vec3(0.0f, 2.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90, -45);


    //Create the shader program
    GLSLProgram shaderProgram;
    shaderProgram.compileShaders("Shaders/sphere.vertex.glsl", "Shaders/sphere.fragment.glsl");
    shaderProgram.linkShaders();

    SDL_Event event;

    //Set up drawables
//    Texture texture1("Textures/container.jpg");
//    Texture texture2("Textures/awesomeface.png");
//    Cube cube(shaderProgram, &texture1, &texture2);

    printf("Creating sphere\n");

    Sphere2 sphere(shaderProgram);
    sphere.setCamera(camera);
    sphere.scale(glm::vec3(0.5f));

    GLfloat deltaTime;
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

        sphere.rotate(deltaTime/1000, glm::vec3(1.0f, 0.3f, 0.5f));
        sphere.draw(deltaTime);

        window.swapBuffer();
    }
}


