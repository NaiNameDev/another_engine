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
#include "./core/texture.hpp"
#include "./core/camera.hpp"

#include "./physics/collision_shape.hpp"

#include "./core/debug/noclip_camera.hpp"

#include "./utils/obj_reader.hpp"
#include "./utils/input.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "./include/stb_image.h"

#include "./inits.cpp"

#define FOV 100.0f
#define WIDTH 1920.0f
#define HEIGHT 1080.0f

#if !defined(NDEBUG)
#define DBG
#endif

float mouse_x = 0;
float mouse_y = 0;

void mouse_callback(GLFWwindow* window, double x, double y) {
	mouse_x = static_cast<float>(x);
    mouse_y = static_cast<float>(y);
}

int main() {
#ifdef DBG
	std::cout << "DEBUG MODE\n";
#endif
	//init
	glfw_init();
	
	Window game_win;
	game_win.init_window(WIDTH, HEIGHT, "mw", glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));

	glad_init();
	glfwSetCursorPosCallback(game_win.window, mouse_callback);
	glfwSetInputMode(game_win.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



	//pre_render
	Shader tsh;
	tsh.create_shader("./shaders/test/tv.glsl", "./shaders/test/tf.glsl");

	ObjReader rd;
	rd.import_obj("./test/obj/tc.obj");
	Mesh m = rd.create_mesh(tsh);
	CollisionMesh cm = rd.create_collision_mesh();

	m.name = "TETOKASANE!!";
	//m.position.y -= 5.0f;
	//m.scale = glm::vec3(0.05f, 0.05f, 0.05f);
	rd.import_mtl_textures("./test/mtl/tetokasane.mtl", "./test/mtl/", &m);

	m.init_root();
	m.add_child(&cm);
	
	rd.import_obj("./editor/models/move_cursor.obj");
	Mesh cube = rd.create_mesh(tsh);
	cube.position = m.position;
	cube.init_root();

	NoclipCamera mc;
	mc.init_root();
	mc.create_proj_matrix(WIDTH, HEIGHT, FOV);

	//main loop
	float delta = 0;
	float last_frame = glfwGetTime();
	while(!glfwWindowShouldClose(game_win.window)) {
		//delta
		delta = glfwGetTime() - last_frame;
		last_frame = glfwGetTime();
		//std::cout << delta << "d & " << 1 / delta << "f\n";
		
		if (cm.is_coliding_with_ray(mc.get_global_position(), mc.get_mouse_ray(mouse_x, mouse_y))){
			std::cout << "touch\n";
		}
		else std::cout << "bruh\n";

		//prepare to draw
		game_win.clear_window();
		mc.mouse_input(mouse_x, mouse_y);
		mc.move(delta, game_win.window);

		//draw
		m.prepare_to_draw(mc.get_view(), mc.proj_matrix);
		m.shader.set_vec3("light_dir", glm::vec3(0.0f,0.0f,1.0f));
		m.shader.set_vec3("light_color", glm::vec3(1.0f,1.0f,1.0f));
		m.shader.set_vec3("obj_color", glm::vec3(1.0,1.0f,1.0f));
		m.draw();

		cube.prepare_to_draw(mc.get_view(), mc.proj_matrix);
		cube.shader.set_vec3("light_dir", glm::vec3(0.0f,0.0f,1.0f));
		cube.shader.set_vec3("light_color", glm::vec3(1.0f,1.0f,1.0f));
		cube.shader.set_vec3("obj_color", glm::vec3(1.0,1.0f,1.0f));
		cube.draw();

		game_win.swap_buffers();
	}

	//exit
	m.kill();
	cube.kill();
	tsh.kill_shader();

	glfwTerminate();

	return 0;
}
