#version 300 es
in mediump vec2 TexCoords;
out mediump vec4 color;

uniform mediump sampler2D text;
uniform mediump vec3 textColor;

void main()
{
    mediump vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
    color = vec4(textColor, 1.0) * sampled;
}
