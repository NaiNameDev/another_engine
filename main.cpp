#include <iostream>
#include <math.h>
#include <vector>

#include "include/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "./core/old_shader.h"

#include "./core/node.hpp"
#include "./core/mesh.hpp"
#include "./core/window.hpp"

void glfw_init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void glad_init() {    
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
}

int main() {
	glfw_init();
	
	Window game_win;
	game_win.init_window(1280, 720, "bark bark skibidi labubu");

	glad_init();

	
	Shader tsh;
	tsh.create_shader("/home/abobus1337/codeProjs/poor_godot_clone/shaders/test/tv.glsl", "/home/abobus1337/codeProjs/poor_godot_clone/shaders/test/tf.glsl");

	Mesh m(
		tsh,
		std::vector<float>{-1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f},
		std::vector<unsigned int>{1, 2, 3}
	);

	while(!glfwWindowShouldClose(game_win.window)) {
		game_win.clear_window();
		
		m.draw();

		game_win.swap_buffers();
	}

	m.kill();
	tsh.kill_shader();

	return 0;
}

