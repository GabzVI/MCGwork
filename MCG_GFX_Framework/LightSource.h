#include <cmath>
#include <GLM/glm.hpp>


class Sphere;
class Trace;
struct intersectResult;

class LightSource
{
private:
  glm::vec3 lightPos;
  glm::vec3 Li; //Colour of the Light
  glm::vec3 Kd; //Colour of surface or sphere
  glm::vec3 wi; //vector pointing to light source
  glm::vec3 diffuseLight;
  
public:

  glm::vec3 Diffuselighting(Sphere sphere, intersectResult tmpResult);
  void setLightpos(glm::vec3 _setLightpos);
  void setLightColour(glm::vec3 _lightColour);
  void setSurfaceLight(glm::vec3 _surfaceLight);
  glm::vec3 getLightpos();
  glm::vec3 getLightColour();
  glm::vec3 getSurfaceLight();
};
