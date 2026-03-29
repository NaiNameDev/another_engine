#pragma once

class ObjReader {
public:
	std::vector<float> vertices; // 3 float vertexes, 2 floats UV, 1 float materal_id, 3 floats normals
	unsigned int vertex_count;
	
	std::vector<float> vertexes;
	std::vector<float> normals;
	std::vector<float> UVs;

	std::string name;

	void import_obj(std::string path);
	void import_mtl_textures(std::string mtl_path, std::string textures_path, Mesh* msh);
	void clear();

	Mesh create_mesh(Shader shd);
	CollisionMesh create_collision_mesh();
};
