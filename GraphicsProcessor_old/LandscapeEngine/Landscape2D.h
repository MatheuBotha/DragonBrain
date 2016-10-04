//
// Created by matheu on 9/8/16.
//

#ifndef DRAGONBRAIN_LANDSCAPE2D_H
#define DRAGONBRAIN_LANDSCAPE2D_H

#include "Landscape.h"

#include "../../Objectives/ObjectiveFunction.h"

#include "../GraphicsEngine/GLSLProgram.h"

#include <string>
#include <vector>

#include "../GraphicsEngine/SpriteBatch.h"

const int TILE_WIDTH = 64;

class Landscape2D : public Landscape
{
public:
    // Load the level
    Landscape2D(const std::string& fileName);
    ~Landscape2D();

    void draw();

    // Getters
    int getWidth() const { return _levelData[0].size(); }
    int getHeight() const { return _levelData.size(); }
    int getNumHumans() const { return _numHumans; }
    const std::vector<std::string>& getLevelData() const { return _levelData; }
    glm::vec2 getStartPlayerPos() const { return _startPlayerPos; }
    const std::vector<glm::vec2>& getZombieStartPositions() const { return _zombieStartPositions; }

private:
    std::vector<std::string> _levelData;
    int _numHumans;
    GraphicsEngine::SpriteBatch _spriteBatch;

    glm::vec2 _startPlayerPos;
    std::vector<glm::vec2> _zombieStartPositions;
};

#endif //DRAGONBRAIN_LANDSCAPE2D_H
