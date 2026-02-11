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
#include "./core/camera.hpp"

#include "./utils/obj_reader.hpp"

#include "./inits.cpp"

#define STB_IMAGE_IMPLEMENTATION
#include "./include/stb_image.h"

#define FOV 100.0f
#define WIDTH 1280
#define HEIGHT 720

int main() {
	//init
	glfw_init();
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	stbi_set_flip_vertically_on_load(1);
	
	Window game_win;
	game_win.init_window(WIDTH, HEIGHT, "bark bark skibidi labubu", glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));
	
	glad_init();

	//pre_render
	Shader tsh;
	tsh.create_shader("./shaders/test/tv.glsl", "./shaders/test/tf.glsl");

	ObjReader rd;
	rd.import_file("./test/obj/tc.obj");
	Mesh m = rd.create_mesh(tsh);
	rd.import_file("./test/obj/tmo.obj");
	Mesh m2 = rd.create_mesh(tsh);
	//rd.import_mtl_textures("./test/mtl/tetokasane.mtl", "./test/mtl/", &m);
	
	m.init_root();
	m.add_child(&m2);
	
	m.position.z -= 10;
	m.position.x -= 4;
	m2.position.x -= 4;
	
	Camera3D mc;
	mc.init_root();
	mc.create_proj_matrix(FOV, WIDTH/HEIGHT);
	mc.position.z += 20;


	//main loop
	float delta = 0;
	float last_frame = glfwGetTime();
	while(!glfwWindowShouldClose(game_win.window)) {
		//delta
		delta = glfwGetTime() - last_frame;
		last_frame = glfwGetTime();
		std::cout << delta << "d & " << 1 / delta << "f\n";

		//prepare to draw
		game_win.clear_window();

		m2.rotation.z = glfwGetTime();
		m.rotation.y = glfwGetTime()/2.12;
		m.rotation.x = cos(glfwGetTime()) * 10;
		

		//draw
		m2.prepare_to_draw(mc.get_view(), mc.proj_matrix);
		m2.shader.set_vec3("light_dir", glm::vec3(0.0f,0.0f,1.0f));
		m2.shader.set_vec3("light_color", glm::vec3(1.0f,1.0f,1.0f));
		m2.shader.set_vec3("obj_color", glm::vec3(1.0,1.0f,1.0f));
		m2.draw();

		m.prepare_to_draw(mc.get_view(), mc.proj_matrix);
		m.shader.set_vec3("light_dir", glm::vec3(0.0f,0.0f,1.0f));
		m.shader.set_vec3("light_color", glm::vec3(1.0f,1.0f,1.0f));
		m.shader.set_vec3("obj_color", glm::vec3(1.0,1.0f,1.0f));
		m.draw();

		game_win.swap_buffers();
	}

	//exit
	m.kill();
	tsh.kill_shader();

	return 0;
}
