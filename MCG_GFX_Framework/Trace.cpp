#include "Trace.h"
#include "Ray.h"
#include "Sphere.h"
#include <cmath>

glm::ivec3 Traceray::Raytracer(Ray _ray, intersectResult tmpResult) 
{
  
  //Sphere
  //iR

  //iR = Sphere.intersect(...)

  //if(iR.hit == false)

  if (tmpResult.hit == true) 
  {
    pixelColour = glm::ivec3(255, 0, 0);
  }
  else 
  {
    pixelColour = glm::ivec3(0, 255, 0);
  }
  
  

  return pixelColour;
}