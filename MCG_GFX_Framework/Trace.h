#include <glm/glm.hpp>

class Ray;

class Traceray {

private:
  glm::ivec3 pixelColour;
public:
  glm::ivec3 Raytracer(Ray _ray);

};