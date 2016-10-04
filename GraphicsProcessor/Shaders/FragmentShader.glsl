#version 330 core

//in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

// Texture samplers
uniform sampler2D myTexture;


void main()
{
	// Linearly interpolate between both textures (second texture is only slightly combined)
	//color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);
	color = texture(myTexture, TexCoord);
	//color = vec4(1.0f, 0.0f, 1.0f, 1.0f);
}

