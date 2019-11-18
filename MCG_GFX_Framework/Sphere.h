#include <glm/glm.hpp>

class Ray;

class Sphere {

private:
  float _r; //radius of sphere

public:
  
  glm::ivec3 Rayintersection(Ray _ray, glm::vec3 intersectionp); 
};