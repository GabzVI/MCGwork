#include "Trace.h"
#include "Ray.h"
#include "Sphere.h"
#include "LightSource.h"
#include <iostream>
#include <cmath>

glm::vec3 Traceray::Raytracer(Ray _ray, intersectResult tmpResult, LightSource lightpoint, Sphere sphere) 
{

  if (tmpResult.hit == true) 
  {
    glm::vec3 dv = -tmpResult.sphereintersection + lightpoint.getLightpos(); // Gets intersectionpoint and light source position to calculate directional vector. dv
    glm::vec3 normal = sphere.getSpherenormal();
    glm::vec3 normaldv = glm::normalize(dv); 
    pixelColour = glm::max(glm::dot(normaldv, normal), 1.0f) * glm::vec3(1.0f, 0.0f, 0.0f) * glm::vec3(1.0f, 0.0f, 0.0f);
    std::cout << "red sphere drawn" << std::endl;
  }
  else 
  {
    pixelColour = glm::vec3(1, 1, 1);
    //std::cout << "not being drawn, yellow back" << std::endl;
  }
  
  

  return pixelColour;
}