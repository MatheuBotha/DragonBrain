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
    Texture() {}
    Texture(const std::string& fileName);
    virtual ~Texture();

    void bind();

protected:
private:

    GLuint texture_id;
};


#endif //SWARMVIZ_TEXTURE_H
