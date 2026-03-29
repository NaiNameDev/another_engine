#include "collision_shape.hpp"

CollisionMesh::CollisionMesh(
	std::vector<float> nvertexes,
	std::vector<float> nnormals,
	std::string new_name,
	glm::vec3 new_position,
	glm::vec3 new_rotation,
	glm::vec3 new_scale
) : Node3D(new_name, new_position, new_rotation, new_scale) {
	vertexes = nvertexes;
	normals = nnormals;
}

bool CollisionMesh::is_coliding_with_ray(glm::vec3 ro, glm::vec3 rd) {
	for (int i = 0; i < vertexes.size() / 9; i += 9) {
		glm::mat4 gm = get_global_matrix();
		if (glm::dot(rd, glm::vec3(normals[i], normals[i + 1], normals[i + 2]) * glm::mat3(gm)) == 0) continue;
		
		// get all the vertices from triangle
		glm::vec3 tn = glm::vec3(normals[i], normals[i + 1], normals[i + 2]) * glm::mat3(gm);
		glm::vec3 tv1 = glm::vec3(glm::vec4(vertexes[i    ], vertexes[i + 1], vertexes[i + 2], 1.0f) * gm);
		glm::vec3 tv2 = glm::vec3(glm::vec4(vertexes[i + 3], vertexes[i + 4], vertexes[i + 5], 1.0f) * gm);
		glm::vec3 tv3 = glm::vec3(glm::vec4(vertexes[i + 6], vertexes[i + 7], vertexes[i + 8], 1.0f) * gm);
	
		// find position where triangle local plane collides with ray
		float t = -glm::dot(ro - tv1, tn) / glm::dot(rd, tn);
		glm::vec3 pr = ro + rd * t;

		// SAT method
		float prpos = glm::dot(glm::normalize(tv1 - tv2), pr);
		float dist = glm::distance(tv1, tv2) * prpos < 0 ? -1 : 1;
		if (!(prpos < glm::max(dist, 0.0f) && prpos > glm::min(dist, 0.0f))) continue;

		prpos = glm::dot(glm::normalize(tv2 - tv3), pr);
		dist = glm::distance(tv2, tv3) * prpos < 0 ? -1 : 1;
		if (!(prpos < glm::max(dist, 0.0f) && prpos > glm::min(dist, 0.0f))) continue;
	
		prpos = glm::dot(glm::normalize(tv3 - tv1), pr);
		dist = glm::distance(tv3, tv1) * prpos < 0 ? -1 : 1;
		if (!(prpos < glm::max(dist, 0.0f) && prpos > glm::min(dist, 0.0f))) continue;
		
		// gg easy
		return true;
	}
	return false;
}
