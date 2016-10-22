#version 300 es
layout (location = 0) in mediump vec4 vertex; // <vec2 pos, vec2 tex>
out mediump vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{

    gl_Position = projection * view * model * vec4(vertex.xy, 0.0, 1.0);
    TexCoords = vertex.zw;
}
