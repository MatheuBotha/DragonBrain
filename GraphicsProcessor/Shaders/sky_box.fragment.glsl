#version 330 core
in vec3 TexCoords;
out vec4 color;

uniform samplerCube ourTexture1;

void main()
{
    color = texture(ourTexture1, TexCoords);
}
