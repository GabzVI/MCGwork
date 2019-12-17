#include <glm/glm.hpp>

class Ray;
class Camera;

struct intersectResult
{
	bool hit;
	float pointdistance;
  glm::vec3 sphereintersection;
	float distfromCameratoSphere;
};

class Sphere 
{

private:
  float radius; //radius of sphere
  glm::vec3 sphereOri; //Sphere Origin
  glm::vec3 sphereNormal;
	
public:

  intersectResult Rayintersection(Ray _ray);
  void SetRadius(float _setr);
  void SetSphereori(glm::vec3 _setsphereOri);
  float getRadius();
  glm::vec3 getSphereori();
  glm::vec3 getSpherenormal();
	

};