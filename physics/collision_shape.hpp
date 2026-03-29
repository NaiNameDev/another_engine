#pragma once
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../core/node.hpp"

class CollisionShape : public Node3D {
public:
	virtual void collide(CollisionShape* shp);
};

class CollisionMesh : public Node3D {
public:
	std::vector<float> vertexes;
	std::vector<float> normals;

	CollisionMesh(
		std::vector<float> nvertexes,
		std::vector<float> nnormals,
		std::string new_name = "CollisionMesh",
		glm::vec3 new_position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_rotation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 new_scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);

	bool is_coliding_with_ray(glm::vec3 ro, glm::vec3 rd);
};
