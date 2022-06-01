#version 430

layout(location=0) out vec4 Color;

layout(location=0) in vec3 position;
layout(location=1) in vec2 uv;
layout(location=2) in vec3 normal;

layout(location=0) uniform sampler2D myTexture;
layout(location=4) uniform vec3 aColor;
layout(location=5) uniform vec3 dColor;
layout(location=6) uniform vec3 sColor;
layout(location=7) uniform float shine;
layout(location=8) uniform vec3 lColor;
layout(location=9) uniform vec3 lPos;
layout(location=10) uniform vec3 cPos;

void main()
{

//	Color.xy = uv;
//	Color.z = 0;
	vec3 L = normalize(lPos - position);
	vec3 V = normalize(cPos - position);
	vec3 H = normalize(L + V);
	vec3 colorMix = dColor + texture(myTexture, uv).xyz;
	vec3 D = colorMix * dot(L,normal) * lColor;
	vec3 S = sColor * pow(dot(normal, H), shine);
	Color = vec4(aColor + D + S, 1);

}