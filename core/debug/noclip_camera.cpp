#include <iostream>

#include <glm/glm.hpp>

#include "../node.hpp"
#include "../camera.hpp"
#include "./noclip_camera.hpp"

NoclipCamera::NoclipCamera(
	float new_sensitivity,
	glm::vec3 new_up,
	glm::vec3 new_dir,
	std::string new_name,
	glm::vec3 new_position,
	glm::vec3 new_rotation,
	glm::vec3 new_scale
) : Camera3D(new_up, new_dir, new_name, new_position, new_rotation, new_scale) {
	sensitivity = new_sensitivity;
	
	lx = 0;
	ly = 0;

	yw = 0;
	ph = 0;

	mouse_state = true;
}

void NoclipCamera::mouse_input(float x, float y) {
	if (mouse_state) {
		rotation.y += glm::radians((x - lx) * 0.1f);
		rotation.x += glm::radians((y - ly) * 0.1f);
		rotation.x = glm::clamp(rotation.x, glm::radians(-89.0f), glm::radians(89.0f));
	}

	lx = x;
	ly = y;
}

void NoclipCamera::move(float delta, GLFWwindow* win) {
	float speed = static_cast<float>(4.5 * delta);

	glm::mat3 glo = glm::mat3(get_global_matrix());

	if (Input::is_action_pressed(win, GLFW_KEY_W)) position += speed * (dir * glo);
	if (Input::is_action_pressed(win, GLFW_KEY_S)) position -= speed * (dir * glo);
	
	if (Input::is_action_pressed(win, GLFW_KEY_A)) position -= glm::normalize(glm::cross((dir * glo), up)) * speed;
	if (Input::is_action_pressed(win, GLFW_KEY_D)) position += glm::normalize(glm::cross((dir * glo), up)) * speed;	
	
	if (Input::is_action_pressed(win, GLFW_KEY_SPACE)) position  += speed * up;
	if (Input::is_action_pressed(win, GLFW_KEY_LEFT_SHIFT)) position -= speed * up;
	
	if (Input::is_action_pressed(win, GLFW_KEY_Y)) {
		glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		mouse_state = false;
	}
	if (Input::is_action_pressed(win, GLFW_KEY_I)) { 
		glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		mouse_state = true;
	}
}
