#version 330 core

uniform vec3 light_dir;
uniform vec3 light_color;
uniform vec3 obj_color;

in vec3 sh_normal;
in vec2 sh_UV;

out vec4 FragColor;

uniform sampler2D text1;

void main() {
	float ambient_strength = 0.1;
	vec3 ambient = ambient_strength * light_color;

	// diffuse 
	vec3 norm = normalize(sh_normal);
	float diff = max(dot(norm, light_dir), 0.0);
	vec3 diffuse = diff * light_color;
			
	vec3 result = (ambient + diffuse) * obj_color;
	FragColor = texture(text1 ,sh_UV) * vec4(result, 1.0);
}
