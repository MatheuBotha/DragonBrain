#version 330 core

in vec3 texPos;

out vec4 colour;

uniform sampler2D ourTexture1;

void main(){
	// Output color = color of the texture at the specified UV
	colour = texture(ourTexture1, texPos.xy);

}
