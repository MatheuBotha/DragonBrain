//
// Created by matheu on 9/8/16.
//

#ifndef DRAGONBRAIN_TEXTURECACHE_H
#define DRAGONBRAIN_TEXTURECACHE_H


namespace GraphicsEngine {

    //This caches the textures so that multiple sprites can use the same textures
    class TextureCache
    {
    public:
        TextureCache();
        ~TextureCache();

        GLTexture getTexture(std::string texturePath);

    private:
        std::map<std::string, GLTexture> _textureMap;
    };

}


#endif //DRAGONBRAIN_TEXTURECACHE_H
