#pragma once

class Node {
public:
	Node* parant;
	std::vector<Node*> childs;
	std::string name;

	Node(std::string new_name = "Node");

	void print_name();
	void print_tree(int depth = 0);

	void init_root();
	void insert_as_child(Node* parant);
	void add_child(Node* child);
	
	glm::mat4 get_global_matrix();
	virtual glm::mat4 get_local_matrix();
};

class Node3D : public Node {
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	
	Node3D(
		std::string new_name = "Node3D",
		glm::vec3 new_position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_rotation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);

	virtual glm::mat4 get_local_matrix();
	glm::vec3 get_global_position();
};
