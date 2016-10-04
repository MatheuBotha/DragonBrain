//
// Created by matheu on 2016/10/04.
//

#include "Texture.h"

#include <SOIL/SOIL.h>
#include <iostream>

Texture::Texture(const std::string& fileName)
{
    // Load and create a texture
    // ====================
    // Texture 1
    // ====================
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    int width, height;
    unsigned char* image = SOIL_load_image("Textures/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture_id);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
}
