#pragma once

class Camera3D : public Node3D {
public:
	glm::vec3 up;
	glm::vec3 dir;
	
	float fov;
	float aspect;
	float near;
	float far;

	float width;
	float height;

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
	void create_proj_matrix(float mwidth, float mheight, float mfov = 90.0f, float mnear = 0.1f, float mfar = 100.0f);

	glm::vec3 get_mouse_ray(float mouse_x, float mouse_y);
};
