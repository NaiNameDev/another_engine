#version 330
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec2 UV;
layout (location = 2) in vec3 normal;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 modl;

out vec3 sh_normal;
out vec2 sh_UV;

void main() {
	sh_normal = inverse(transpose(mat3(modl))) * normal;
	sh_UV = UV;

	gl_Position = proj * view * modl * vec4(vertex, 1.0f);
}
