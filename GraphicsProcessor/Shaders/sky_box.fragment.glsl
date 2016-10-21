#version 300 es
in mediump vec3 TexCoords;
out mediump vec4 color;

uniform samplerCube ourTexture1;

void main()
{
    color = texture(ourTexture1, TexCoords);
}
