#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "./node.hpp"
#include "./camera.hpp"

Camera3D::Camera3D(
	glm::vec3 new_up,
	glm::vec3 new_dir,
	std::string new_name,
	glm::vec3 new_position,
	glm::vec3 new_rotation,
	glm::vec3 new_scale
) : Node3D(new_name, new_position, new_rotation, new_scale) {
	up = new_up;
	dir = new_dir;
}

glm::mat4 Camera3D::get_view() {
	glm::vec3 gp = get_global_position();

	glm::mat4 ret = glm::lookAt(
		gp,
		gp + to_global(dir),
		up
	);

	return ret;
}

void Camera3D::create_proj_matrix(float fov, float aspect, float near, float far) {
	proj_matrix = glm::perspective(glm::radians(fov), aspect, near, far);
}
