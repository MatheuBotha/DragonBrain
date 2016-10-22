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
#include "../Engine/TextRenderer.h"

int main()
{

    std::cout << "Starting Sphere Test" << std::endl;
    //init SDL stuffz
    Engine::init();

    //make a window
    Window window;
    window.create("Sphere Test", 800, 600, 0);

    Camera* camera;
    camera = new Camera(800, 600, glm::vec3(0.0f, 2.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90, -45);


    //Create the shader program
    GLSLProgram shaderProgram;
    shaderProgram.compileShaders("Shaders/text.vertex.glsl", "Shaders/text.fragment.glsl");
    shaderProgram.linkShaders();

    SDL_Event event;


    //Set up drawables
    printf("Creating Text Renderer\n");

    TextRenderer tr(shaderProgram);
    tr.setCamera(camera);

    printf("Done Creting Text Renderer\n");
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

        printf("Rendering text\n");
        tr.renderText("This is sample text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        tr.renderText("(C) LearnOpenGL.com", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
        printf("Done Rendering text\n");
        window.swapBuffer();
    }
}