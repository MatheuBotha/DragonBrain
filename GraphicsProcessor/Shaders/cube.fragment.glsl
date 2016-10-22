#version 300 es

in mediump vec2 TexCoord;

out mediump vec4 color;

uniform sampler2D ourTexture1;

void main()
{
    color = texture(ourTexture1, TexCoord);
}