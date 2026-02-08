#include <string>
#include <vector>

#include "../include/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "old_shader.h"
#include "mesh.hpp"
#include "node.hpp"

Mesh::Mesh(
	Shader new_shader,
	std::vector<float> vertices,
	unsigned int vertex_cnt,
	std::string new_name,
	glm::vec3 new_position,
	glm::vec3 new_rotation,
	glm::vec3 new_scale
) : Node3D(new_name, new_position, new_rotation, new_scale) {
	shader = new_shader;
	vertex_count = vertex_cnt;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);
}

void Mesh::prepare_to_draw(float fov, float aspect){
	shader.use();
	
	shader.set_mat4("modl", get_global_matrix());
	shader.set_mat4("view", glm::mat4(1.0f));
	shader.set_mat4("proj", glm::perspective(fov, aspect, 0.1f, 100.0f));
}

void Mesh::draw() {
	int i = 0;
	for (Texture tx : textures) {
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, tx.texture);
		i++;
	}
	glBindVertexArray(VAO);	
	glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}

void Mesh::kill() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
