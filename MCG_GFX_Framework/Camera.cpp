#include "Camera.h"
#include "Ray.h"
#include "sphere.h"
#include <GLM/ext.hpp>

Ray Camera::Returnray(glm::ivec2 _pixelcp) 
{
	Ray _ray;
	Sphere sphere;

  windowSize.x = 480;
  windowSize.y = 640;
  
  projectionMatrix = glm::perspective(glm::radians(45.0f), ((float)windowSize.x / (float)windowSize.y), 0.1f, 100.0f);
  viewMatrix = glm::mat4(1.0f);
  viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, 3.0f));
  

  //Map the coordinates into worldspace space
  mapCoordinate.x = (((float)_pixelcp.x / (float)windowSize.x) * 2) * -1.0f;
  mapCoordinate.y = (((float)_pixelcp.y / (float)windowSize.y) * 2) * -1.0f;

  nearPlane = glm::vec4(mapCoordinate.x, mapCoordinate.y, -1.0f, 1.0f);
  farPlane = glm::vec4(mapCoordinate.x, mapCoordinate.y, 1.0f, 1.0f);

  //Doing the inverse of projection matrix onto planes
  nearPlane = glm::inverse(projectionMatrix) * nearPlane;
  farPlane = glm::inverse(projectionMatrix) * farPlane;

  //Applying the view matrix onto planes
  nearPlane = glm::inverse(viewMatrix) * nearPlane;
  farPlane = glm::inverse(viewMatrix) * farPlane;

  //Setting new origin and direction of rays after applying inverse projection and view matrix onto planes.
  glm::vec3 newOrigin = glm::vec3(nearPlane.x, nearPlane.y, nearPlane.z);
  glm::vec3 newDirection = glm::normalize(glm::vec3(farPlane.x, farPlane.y, farPlane.z) - newOrigin);
  
  _ray.origin = newOrigin;
  _ray.direction = newDirection;
	 
	return _ray;
}


void Camera::setCamera(glm::mat4 _view, glm::mat4 _projetction) 
{
  viewMatrix = _view;
  projectionMatrix = _projetction;
}
glm::mat4 Camera::getCamera()
{
  return viewMatrix, projectionMatrix;
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