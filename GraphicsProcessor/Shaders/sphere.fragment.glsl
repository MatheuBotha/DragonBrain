#version 300 es

in mediump vec3 texPos;

out mediump vec4 colour;

uniform sampler2D ourTexture1;

void main(){
	// Output color = color of the texture at the specified UV
	colour = texture(ourTexture1, texPos.xy);

}
