#pragma once
#include <string>

class Texture {
public:
	unsigned int texture;
	int width, height, nrChannels;

	void import_texture(std::string path);

};
