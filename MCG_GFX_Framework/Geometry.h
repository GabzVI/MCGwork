#include <glm/glm.hpp>

class Ray;
class Sphere;

class Geometry {

private:
  glm::vec3 _sphereOri;
public:
  glm::vec3 Closestpa(Ray _ray, glm::vec3 _sphereOri);
  void Raysphereint(Ray _ray, glm::vec3 _sphereOri, Sphere _r);
  glm::vec3 Spherenormal(glm::vec3 _sphereOri, glm::vec3 _samplep);

};