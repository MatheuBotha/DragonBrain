#version 300 es
layout (location = 0) in  mediump vec3 position;
out mediump vec3 TexCoords;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;


void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    TexCoords = position;
}
