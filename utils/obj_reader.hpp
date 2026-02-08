#pragma once

class ObjReader {
public:
	std::vector<float> vertices; // 3 float vertexes, 2 floats UV, 3 floats normals
	unsigned int vertex_count;

	std::string name;

	void import_file(std::string path);

	Mesh create_mesh(Shader shd);
};
