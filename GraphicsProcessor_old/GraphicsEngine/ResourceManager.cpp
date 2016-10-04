//
// Created by matheu on 9/8/16.
//

#include "ResourceManager.h"

namespace GraphicsEngine {

    TextureCache ResourceManager::_textureCache;

    GLTexture ResourceManager::getTexture(std::string texturePath) {
        return _textureCache.getTexture(texturePath);
    }

}
