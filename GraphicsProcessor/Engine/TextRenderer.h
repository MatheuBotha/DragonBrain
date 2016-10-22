//
// Created by matheu on 10/22/16.
//

#ifndef SWARMVIZ_TEXTRENDERER_H
#define SWARMVIZ_TEXTRENDERER_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include "Mesh.h"
#include "GLSLProgram.h"

class TextRenderer : public Mesh {
public:
    TextRenderer(GLSLProgram shaderProgram);
    ~TextRenderer();
    void draw(GLfloat deltaTime);

    void activateShader();
    void deactivateShader();

    void rotate(GLfloat angle, glm::vec3 rotationVector);
    void scale(glm::vec3 scaleVector);
    void translate(glm::vec3 location);

    void setModel();
    void setModel(glm::mat4 model);

    void setCamera(Camera* camera);

    void renderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
protected:
private:
    GLSLProgram shaderProgram;
    Camera* camera;

    GLuint VBO, VAO;

    glm::mat4 model;
    /// Holds all state information relevant to a character as loaded using FreeType
    struct Character {
        GLuint TextureID;   // ID handle of the glyph texture
        glm::ivec2 Size;    // Size of glyph
        glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
        GLuint Advance;    // Horizontal offset to advance to next glyph
    };

    std::map<GLchar, Character> Characters;
    FT_Library ft;
    FT_Face face;
};


#endif //SWARMVIZ_TEXTRENDERER_H
