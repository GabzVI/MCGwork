#include <glm/glm.hpp>

class Ray;
class Sphere;
class LightSource;
struct intersectResult;

class Traceray 
{

private:
  glm::vec3 pixelColour;
public:
  glm::vec3 Raytracer(Ray _ray, intersectResult tmpResult, LightSource pointlight, Sphere sphere);

};