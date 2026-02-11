#pragma once

class ObjReader {
public:
	std::vector<float> vertices; // 3 float vertexes, 2 floats UV, 1 float materal_id, 3 floats normals
	unsigned int vertex_count;

	std::string name;

	void import_file(std::string path);
	void import_mtl_textures(std::string mtl_path, std::string textures_path, Mesh* msh);

	Mesh create_mesh(Shader shd);
};
