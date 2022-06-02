#version 430
layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec2 uv;


layout(location=0) out vec3 Position;
layout(location=1) out vec3 Normal;
layout(location=2) out vec2 UV;

uniform mat4 Projection;
uniform mat4 ModelView;
uniform mat4 Model;

void main()
{

	gl_Position =  ModelView * Projection * vec4(position, 1);
	Position = (Model * vec4(position, 1)).xyz;
	Normal = Normal = mat3(transpose(inverse(Model))) * normal.xyz;
	UV = uv;

}
