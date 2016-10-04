//
// Created by matheu on 9/8/16.
//

#ifndef DRAGONBRAIN_RESOURCEMANAGER_H
#define DRAGONBRAIN_RESOURCEMANAGER_H


#include "TextureCache.h"
#include <string>

namespace GraphicsEngine {

    //This is a way for us to access all our resources, such as
    //Models or textures.
    class ResourceManager
    {
    public:
        static GLTexture getTexture(std::string texturePath);

    private:
        static TextureCache _textureCache;
    };

}


#endif //DRAGONBRAIN_RESOURCEMANAGER_H
