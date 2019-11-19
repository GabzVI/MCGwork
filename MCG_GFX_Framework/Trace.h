#include <glm/glm.hpp>

class Ray;
class Sphere;

class Traceray 
{

private:
  glm::ivec3 pixelColour;
public:
  glm::ivec3 Raytracer(Ray _ray, Sphere sphere);

};