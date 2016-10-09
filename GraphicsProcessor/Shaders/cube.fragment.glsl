#version 130
in mediump vec2 TexCoord;

out mediump vec4 color;

uniform sampler2D ourTexture1;

void main()
{
    gl_FragColor = vec4(texture2D(ourTexture1, TexCoord));
}