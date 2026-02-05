#pragma once

#include "node.hpp"

class Mesh : public Node3D {
public:
	unsigned int VAO, VBO, EBO;
	unsigned int indices_count;

	Shader shader;

	Mesh(
		Shader new_shader,
		std::vector<float> vertices,
		std::vector<unsigned int> indices,
		std::string new_name = "Mesh",
		glm::vec3 new_position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_rotation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);

	void draw();
	void kill();
};
