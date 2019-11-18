#include "Trace.h"
#include "Ray.h"
#include <cmath>

glm::ivec3 Traceray::Raytracer(Ray _ray) {

  pixelColour = glm::ivec3(255, 0, 0);

  return pixelColour;
}