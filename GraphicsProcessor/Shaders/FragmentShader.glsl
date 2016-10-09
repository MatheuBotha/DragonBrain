#version 130
//
////in vec3 ourColor;
//in vec2 TexCoord;
//
//out vec4 color;
//
//// Texture samplers
//uniform sampler2D myTexture;
//
//
//void main()
//{
//	// Linearly interpolate between both textures (second texture is only slightly combined)
//	//color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);
//	color = texture(myTexture, TexCoord);
//	//color = vec4(1.0f, 0.0f, 1.0f, 1.0f);
//}

varying vec4 graph_coord;
uniform vec4 color;

void main(void) {
	float factor;

	if (gl_FrontFacing)
		factor = 1.0;
	else
		factor = 0.5;

	gl_FragColor = vec4(1 - graph_coord.z, graph_coord.z, 0.1, 1) * color * factor;
}


