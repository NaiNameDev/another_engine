#include <iostream>

#include "../include/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "window.hpp"

void Window::frame_size_callback(GLFWwindow* win, int width, int height) {
	glViewport(0,0, width, height);
}

void Window::init_window(int width, int height, std::string name, glm::vec4 color) {
	fill_color = color;

	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frame_size_callback);
}
void Window::clear_window() {
	glClearColor(fill_color.x, fill_color.y, fill_color.z, fill_color.w);
	glClear(GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/);
}
void Window::swap_buffers() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}
