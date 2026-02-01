#include <iostream>
#include <math.h>
#include <vector>

#include "include/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "./core/node.hpp"
#include "./core/mesh.hpp"

//DEBUG
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

int main() {
	Node3D root("sigma", glm::vec3(2,2,2));
	root.init_root();

	Node3D boba("boba", glm::vec3(1,1,1));
	root.add_child(&boba);
	
	Node3D biba("biba", glm::vec3(0,0,0), glm::vec3(1,0,0));
	boba.add_child(&biba);

	//root.print_tree();

	glm::mat4 smat = biba.get_global_matrix();

	std::cout << glm::to_string(smat) << std::endl;

	return 0;
}

