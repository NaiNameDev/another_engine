class ObjReader {
public:
	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> UV;
	std::vector<unsigned int> indices;
	
	std::string name;

	void read_file();

	Mesh create_mesh();
};
