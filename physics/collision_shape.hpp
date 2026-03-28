class CollisionShape {
public:
	virtual void collide(CollisionShape* shp);
}

class CollisionMesh : public CollisionShape {
public:
	std::vector<float> vertexes;
	std::vector<float> normals;

	is_coliding_with_ray(glm::vec3 ro, glm::vec3 rd);
};
