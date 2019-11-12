#include "Camera.h"
#include "Ray.h"

Ray Camera::Returnray(glm::ivec2 _pixelcp) {
	Ray ray;
	ray.origin = glm::vec3(_pixelcp, 0);
	ray.direction = glm::vec3(0, 0, -1);
	return ray;
}