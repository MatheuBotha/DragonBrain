#version 300 es
// Input vertex data, different for all executions of this shader.
layout (location = 0) in mediump vec3 position;

// Output data ; will be interpolated for each fragment.
layout (location = 1) in mediump vec3 texCoords;

out mediump vec3 texPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	texPos = texCoords;
}
