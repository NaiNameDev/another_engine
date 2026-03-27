#pragma once

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "../../utils/input.hpp"

class NoclipCamera : public Camera3D {
public:
	float yw;
	float ph;

	float lx;
	float ly;
	float sensitivity;

	bool mouse_state;

	NoclipCamera(
		float new_sensitivity = 0.05f,
		glm::vec3 new_up = glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3 new_dir = glm::vec3(0.0f, 0.0f, -1.0f),
		std::string new_name = "NoclipCamera",
		glm::vec3 new_position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_rotation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);

	void mouse_input(float x, float y);
	void move(float delta, GLFWwindow* win);
};
