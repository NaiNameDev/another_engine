#include <iostream>
//#include <math.h>
#include <vector>

#include "include/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>

#include "./core/old_shader.h"

#include "./core/node.hpp"
#include "./core/mesh.hpp"
#include "./core/window.hpp"

#include "./utils/obj_reader.hpp"

#include "./inits.cpp"

int main() {
	std::ifstream t("./test/obj/tc_not_trngltd.obj");
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	std::string buffer(size, ' ');
	t.seekg(0);
	t.read(&buffer[0], size); 

	ObjReader rd;
	rd.read_file(buffer);
	exit(0);

	glfw_init();
	
	Window game_win;
	game_win.init_window(1280, 720, "bark bark skibidi labubu");

	glad_init();

	
	Shader tsh;
	tsh.create_shader("/home/valenok/codeProjs/another_engine/shaders/test/tv.glsl", "/home/valenok/codeProjs/another_engine/shaders/test/tf.glsl");

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
