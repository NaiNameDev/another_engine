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

void ObjReader::read_file(std::string file) {
	std::vector<float> tv = {}; //vertexes
	std::vector<float> tn = {}; //noramls
	std::vector<float> tu = {}; //UVs
	
	std::vector<float> over = {}; //out vertices
	std::vector<unsigned int> oind = {}; //out indices

	char mod = '#';
	std::string word = "";

	for(int i = 0; i < file.length(); i++) {
		switch(file[i]) {
			case 's':
				i++;
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
						i+=2;
						break;
					case 't':
						mod = 't';
						i+=2;
						break;
					case ' ':
						mod = 'v';
						i+=2;
						break;
				}
				break;
		}
			
		if (file[i] == ' ' || file[i] == '\n') {
			if (word != "") {
				switch(mod) {
					case 'o':
						std::cout << word << std::endl;
						name = word;
						break;
					case 'v':
						std::cout << word << std::endl;
						tv.push_back(std::stof(word));
						break;
					case 'n':
						std::cout << word << std::endl;
						tn.push_back(std::stof(word));
						break;
					case 't':
						std::cout << word << std::endl;
						tu.push_back(std::stof(word));
						break;

				}
				word = "";
			}
		}
		else word.push_back(file[i]);
	}

	vertices = over;
	indices = oind;
}

Mesh ObjReader::create_mesh() {
	
}
