#include <glm/glm.hpp>

class Ray;
class Sphere;
struct intersectResult;

class Traceray 
{

private:
  glm::ivec3 pixelColour;
public:
  glm::ivec3 Raytracer(Ray _ray, intersectResult tmpResult);

};