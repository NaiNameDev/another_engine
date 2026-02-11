#pragma once

class Camera3D : public Node3D {
public:
	glm::vec3 up;
	glm::vec3 dir;
	
	glm::mat4 proj_matrix;

	Camera3D(
		glm::vec3 new_up = glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3 new_dir = glm::vec3(0.0f, 0.0f, -1.0f),
		std::string new_name = "Camera3D",
		glm::vec3 new_position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_rotation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);

	glm::mat4 get_view();
	void create_proj_matrix(float fov = 90.0f, float aspect = 16/9, float near = 0.1f, float far = 100.0f);
};
