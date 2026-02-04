#pragma once

class Window {
public:
	GLFWwindow* window;
	glm::vec4 fill_color;

	void init_window(int width, int height, std::string name = "new_window", glm::vec4 color = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));
	void clear_window();
	void swap_buffers();

private:
	static void frame_size_callback(GLFWwindow* win, int width, int height);
};
