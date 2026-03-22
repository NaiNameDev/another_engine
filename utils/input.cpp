#include <vector>

#include "../include/glad.h"
#include <GLFW/glfw3.h>

#include "input.hpp"

int Input::is_action_pressed(GLFWwindow* win, int key) {
	return glfwGetKey(win, key) == GLFW_PRESS;
}
