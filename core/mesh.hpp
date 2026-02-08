#pragma once

#include "node.hpp"
#include "texture.hpp"

class Mesh : public Node3D {
public:
	unsigned int VAO, VBO;
	unsigned int vertex_count;
	std::vector<Texture> textures;

	Shader shader;

	Mesh(
		Shader new_shader,
		std::vector<float> vertices,
		unsigned int vertex_cnt,
		std::string new_name = "Mesh",
		glm::vec3 new_position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_rotation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);

	void bind_texture(Texture text) {
		textures.push_back(text);
	}

	void prepare_to_draw(float fov, float aspect);
	void draw();
	void kill();
};
