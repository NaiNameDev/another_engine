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

void Camera3D::create_proj_matrix(float mwidth, float mheight, float mfov, float mnear, float mfar) {
	proj_matrix = glm::perspective(glm::radians(mfov), mwidth / mheight, mnear, mfar);
	fov = mfov;
	aspect = mwidth / mheight;
	near = mnear;
	far = mfar;

	width = mwidth;
	height = mheight;
}

glm::vec3 Camera3D::get_mouse_ray(float mouse_x, float mouse_y) {
	float near_height = tan(glm::radians(fov / 2.0f)) * near;
	return glm::normalize(glm::vec3(near_height * 3.141592f * (mouse_x / width - 0.5f), near_height * (mouse_y / height - 0.5f) * -aspect, -near));
}
