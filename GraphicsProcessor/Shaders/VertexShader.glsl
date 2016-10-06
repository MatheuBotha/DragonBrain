#version 330 core

//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;
//layout (location = 2) in vec2 texCoord;
////
//out vec2 TexCoord;
//
//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;
//
//void main()
//{
//    gl_Position = projection * view * model * vec4(position, 1.0f);
//	// ourColor = color;
//	// We swap the y-axis by substracing our coordinates from 1. This is done because most images have the top y-axis inversed with OpenGL's top y-axis.
//	TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
//}

layout (location = 0) in vec2 coord2d;
varying vec4 graph_coord;
uniform mat4 texture_transform;
uniform mat4 vertex_transform;
uniform sampler2D mytexture;

void main(void) {
	graph_coord = texture_transform * vec4(coord2d, 0, 1);
	graph_coord.z = (texture2D(mytexture, graph_coord.xy / 2.0 + 0.5).r);

	gl_Position = vertex_transform * vec4(coord2d, graph_coord.z, 1);
}


