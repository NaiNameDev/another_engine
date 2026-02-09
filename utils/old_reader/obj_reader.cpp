#include <string>
#include <vector>

#include <glm/glm.hpp>

#include "../include/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "../core/old_shader.h"

#include "../core/node.hpp"
#include "../core/mesh.hpp"

#include "obj_reader.hpp"

void ObjReader::import_file(std::string path) {
	std::vector<float> tv = {}; //vertexes
	std::vector<float> tn = {}; //noramls
	std::vector<float> tu = {}; //UVs
	float material_ids_cnt = 0;

	std::vector<float> over = {}; //out vertices
	unsigned int vertex_cnt = 0;

	char mod = ' ';
	std::string word = "";

	std::ifstream t(path);
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	std::string file(size, ' ');
	t.seekg(0);
	t.read(&file[0], size); 

	for(int i = 0; i < file.length(); i++) {
		switch(file[i]) {
			case 's':
				mod = ' ';
				i+=2;
				break;
			case 'o':
				mod = 'o';
				i++;
				break;
			case 'f':
				mod = 'f';
				i++;
				break;
			
			case 'v':
				switch(file[i + 1]) {
					case 'n':
						mod = 'n';
						break;
					case 't':
						mod = 't';
						break;
					case ' ':
						mod = 'v';
						break;
				}
				i+=2;
				break;
		}
			
		if (file[i] == ' ' || file[i] == '\n') {
			if (word != "") {
				switch(mod) {
					case 'o':
						name = word;
						break;
					case 'v':
						tv.push_back(std::stof(word));
						break;
					case 'n':
						tn.push_back(std::stof(word));
						break;
					case 't':
						tu.push_back(std::stof(word));
						break;
					case 'f':
						std::vector<int> tmp_nums = {};
						std::string buffer = "";

						for (char ch : word) {
							if (ch != '/') {buffer.push_back(ch); continue;}
							tmp_nums.push_back(std::stoi(buffer)); buffer = "";
						}
						tmp_nums.push_back(std::stoi(buffer));
						
						//vertexes
						over.push_back(tv[tmp_nums[0] * 3 - 3]);
						over.push_back(tv[tmp_nums[0] * 3 - 2]);
						over.push_back(tv[tmp_nums[0] * 3 - 1]);
						vertex_cnt+=3;
						
						//UVs
						over.push_back(tu[tmp_nums[1] * 2 - 2]);
						over.push_back(tu[tmp_nums[1] * 2 - 1]);
	
						//material_id
						over.push_back(material_ids_cnt);

						//normals
						over.push_back(tn[tmp_nums[2] * 3 - 3]);
						over.push_back(tn[tmp_nums[2] * 3 - 2]);
						over.push_back(tn[tmp_nums[2] * 3 - 1]);
				}
				word = "";
			}
		}
		else word.push_back(file[i]);
	}

	vertices = over;
	vertex_count = vertex_cnt;
}

Mesh ObjReader::create_mesh(Shader shd) {
	return Mesh(shd, vertices, vertex_count, name);
}
