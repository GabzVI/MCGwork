#include "LightSource.h"
#include "Sphere.h"
#include <cmath>
#include  <GLM/glm.hpp>

glm::vec3 LightSource::Diffuselighting(Sphere sphere, intersectResult result)
{
  wi = glm::normalize( -result.sphereintersection + lightPos);
  float stepone = glm::max(glm::dot(wi, sphere.getSpherenormal()), 0.0f); //wi . N
  Li = glm::vec3(1, 0, 0);
  Kd = glm::vec3(1, 0, 0);
  diffuseLight = stepone * Li  * Kd;
  
  return diffuseLight;
  
}

void LightSource::setLightpos(glm::vec3 _setLightpos)
{
  lightPos = _setLightpos;
}

glm::vec3 LightSource::getLightpos()
{
  return lightPos;
}
