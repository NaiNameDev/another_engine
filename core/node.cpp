#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "node.hpp"

//NODE

Node::Node(std::string new_name) {
	name = new_name;
}

void Node::print_name() {
	std::cout << name << std::endl;
}
void Node::print_tree(int depth) {
	if(depth == 0) {
		print_name();
		std::cout << "\\/" << std::endl;
	}

	if (childs.size() != 0) {
		for (Node* child : childs) {
			for (int i = 0; i < depth; i++) std::cout << "\t";
			
			child->print_name();
			child->print_tree(depth + 1);
		}
	}
}

void Node::init_root() {
	parant = this;
}
void Node::insert_as_child(Node* parant) {
	parant->add_child(this);
}
void Node::add_child(Node* child) {
	childs.push_back(child);
	child->parant = this;
}

glm::mat4 Node::get_global_matrix() {
	glm::mat4 ret = get_local_matrix();

	if (parant != this) {
		ret = parant->get_global_matrix() * ret;
	}

	return ret;
}
glm::mat4 Node::get_local_matrix() {
	return glm::mat4(0.0f);
}

//NODE3D

Node3D::Node3D(
	std::string new_name,
	glm::vec3 new_position,
	glm::vec3 new_rotation,
	glm::vec3 new_scale
) : Node(new_name) {
	position = new_position;
	rotation = new_rotation;
	scale = new_scale;
}

glm::vec3 Node3D::get_global_position() {
	return glm::vec3(get_global_matrix() * glm::vec4(position, 1.0f));
}
glm::mat4 Node3D::get_local_matrix() {
	glm::mat4 ret(1.0f);
	
	ret = glm::translate(ret, position);
	
	ret = glm::scale(ret, scale);
	
	ret = glm::rotate(ret, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	ret = glm::rotate(ret, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	ret = glm::rotate(ret, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	return ret;
}
