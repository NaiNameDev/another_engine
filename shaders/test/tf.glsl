#version 330 core

uniform vec3 light_dir;
uniform vec3 light_color;
uniform vec3 obj_color;

in vec3 sh_normal;
in vec2 sh_UV;
in float sh_mid;

out vec4 FragColor;

#define MAX_TEXTURES 16
uniform sampler2D textures[MAX_TEXTURES];

void main() {
	float ambient_strength = 0.1;
	vec3 ambient = ambient_strength * light_color;

	// diffuse 
	vec3 norm = normalize(sh_normal);
	float diff = max(dot(norm, light_dir), 0.0);
	vec3 diffuse = diff * light_color;
			
	vec3 result = (ambient + diffuse) * obj_color;
	
	//FragColor = vec4(float(a) / 7, float(a) / 7, float(a) / 7, 1.0f);
	if (int(round(sh_mid)) >= 0) {
		FragColor = texture(textures[int(round(sh_mid))] ,sh_UV) * vec4(result, 1.0);
		return;
	}
	
	FragColor = vec4(result, 1.0);
}
