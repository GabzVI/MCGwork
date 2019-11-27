#include "Camera.h"
#include "Ray.h"
#include "sphere.h"

Ray Camera::Returnray(glm::ivec2 _pixelcp, Sphere sphere) 
{
	Ray _ray;
	Sphere sphere;
	_ray.origin = glm::vec3(_pixelcp, 0);
	_ray.direction = glm::vec3(0, 0, -1);
	 
	return _ray;
}

void Camera::setCampos(glm::vec3 camPos) 
{
	camPosition = camPos;
}

void Camera::setCamori(glm::vec3 camOri) 
{
	camOrientation = camOri;
}

glm::vec3 Camera::getCampos() 
{
	return camPosition;
}

glm::vec3 Camera::getCamori()
{
	return camOrientation;
}