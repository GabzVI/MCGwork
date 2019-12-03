#include "LightSource.h"
#include "Sphere.h"
#include <cmath>
#include  <GLM/glm.hpp>

glm::vec3 LightSource::Diffuselighting(Sphere sphere, intersectResult tmpResult)
{
  wi = glm::normalize(-tmpResult.sphereintersection + lightPos);
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

void LightSource::setLightColour(glm::vec3 _lightColour)
{
  Li = _lightColour;
}

glm::vec3 LightSource::getLightColour()
{
  return Li;
}

void LightSource::setSurfaceLight(glm::vec3 _surfaceLight)
{
  Kd = _surfaceLight;
}

glm::vec3 LightSource::getSurfaceLight()
{
  return Kd;
}