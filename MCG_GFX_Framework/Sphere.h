#include <glm/glm.hpp>

class Ray;

struct intersectResult
{
	bool hit;
	float pointdistance;
};

class Sphere 
{

private:
  float radius; //radius of sphere
  glm::vec3 sphereOri; //Sphere Origin
public:

  intersectResult Rayintersection(Ray _ray);
  void SetRadius(float _setr);
  void SetSphereori(glm::vec3 _setsphereOri);
  float getRadius();
  glm::vec3 getSphereori();

};