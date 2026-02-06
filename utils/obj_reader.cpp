#include <string>
#include <vector>

#include "obj_reader.hpp"

void ObjReader::read_obj(std::string obj) {
	std::vector<float> tv = {}; //vertexes
	std::vector<float> tn = {}; //normals
	std::vector<float> tu = {}; //UV
	std::vector<unsigned int> ti = {}; //indices

	for (char ch : obj) {
		std::cout << ch;
	}

	vertices = tv;
	normals = tn;
	UV = tu;
	indices = ti;
}
