#version 330 core
// Input vertex data, different for all executions of this shader.
layout (location = 0) in vec3 position;

// Output data ; will be interpolated for each fragment.
layout (location = 1) in vec3 texCoords;

out vec3 texPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	texPos = texCoords;
}
