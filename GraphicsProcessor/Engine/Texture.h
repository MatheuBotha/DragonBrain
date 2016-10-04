//
// Created by matheu on 2016/10/04.
//

#ifndef SWARMVIZ_TEXTURE_H
#define SWARMVIZ_TEXTURE_H


#include <string>
#include <GL/glew.h>

class Texture
{
public:
    Texture(const std::string& fileName);
    virtual ~Texture();

    void bind();
    Texture(const Texture& texture) {}

protected:
private:
    void operator=(const Texture& texture) {}

    GLuint texture_id;
};


#endif //SWARMVIZ_TEXTURE_H
