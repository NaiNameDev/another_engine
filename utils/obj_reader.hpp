#pragma once

class ObjReader {
public:
	std::vector<float> vertices; // 3 float vertexes, 2 floats UV, 3 floats normals
	std::vector<unsigned int> indices;
	
	std::string name;

	void read_file(std::string file);

	Mesh create_mesh();
};
