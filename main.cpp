#include <iostream>
#include <math.h>
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
#include "./core/texture.hpp"

#include "./utils/obj_reader.hpp"

#include "./inits.cpp"

#define STB_IMAGE_IMPLEMENTATION
#include "./include/stb_image.h"

#define FOV 100.0f
#define WIDTH 1280
#define HEIGHT 720

int main() {
	stbi_set_flip_vertically_on_load(1);

	glfw_init();
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	
	Window game_win;
	game_win.init_window(WIDTH, HEIGHT, "bark bark skibidi labubu");
	
	glad_init();

	ObjReader rd;
	rd.import_file("/home/abobus1337/Downloads/MIKU_MODEL/teto/source/tetokasane.obj");
	
	Shader tsh;
	tsh.create_shader("./shaders/test/tv.glsl", "./shaders/test/tf.glsl");

	Texture text1; text1.import_texture("./test/png/t1.png");
	Texture text2; text2.import_texture("./test/png/t2.png");
	Texture text3; text3.import_texture("./test/png/t4.png");

	Mesh m = rd.create_mesh(tsh);
	m.bind_texture(text2);
	m.bind_texture(text1);
	m.bind_texture(text2);
	m.bind_texture(text1);
	m.bind_texture(text2);
	m.bind_texture(text3);
	m.bind_texture(text1);
	m.init_root();
	m.position.z -= 40;
	m.position.y += 5;
	m.rotation.z = 3.14;
	m.scale = glm::vec3(0.1, 0.1, 0.1);

	while(!glfwWindowShouldClose(game_win.window)) {
		game_win.clear_window();
		
		m.rotation.y = glfwGetTime();
		
		m.prepare_to_draw(FOV, WIDTH/HEIGHT);
		m.shader.set_vec3("light_dir", glm::vec3(0.0f,0.0f,1.0f));
		m.shader.set_vec3("light_color", glm::vec3(1.0f,1.0f,1.0f));
		m.shader.set_vec3("obj_color", glm::vec3(1.0,1.0f,1.0f));
		m.draw();

		game_win.swap_buffers();
	}

	m.kill();
	tsh.kill_shader();

	return 0;
}
