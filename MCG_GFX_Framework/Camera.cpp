#include "Camera.h"
#include "Ray.h"
#include <GLM/ext.hpp>
#include <iostream>

Ray Camera::Returnray(glm::ivec2 _pixelcp) 
{
	Ray _ray;
	
  projectionMatrix = glm::perspective((30.0f * 3.14159265358979f / 180.0f), ((float)windowSize.x / (float)windowSize.y), 0.1f, 100.0f);
  //projectionMatrix = glm::perspective(glm::radians(45.0f), ((float)windowSize.x / (float)windowSize.y), 0.1f, 100.0f);
  viewMatrix = glm::translate(glm::mat4(1.0f), camPosition); //Modelmatrix of camera created

  //viewMatrix = glm::inverse(mat); //inverses the view modelmatrix

  //Map the coordinates into worldspace space
  /*mapCoordinate.x = (((float)_pixelcp.x / (float)windowSize.x) * 2.0f)  - 1.0f;
  mapCoordinate.y = (((float)_pixelcp.y / (float)windowSize.y) * 2.0f) - 1.0f;*/

  float x, y;

  x = (2.0f * (float)_pixelcp.x) / ((float)windowSize.x) - 1.0f;
  y = (2.0f * (float)_pixelcp.y) / ((float)windowSize.y) - 1.0f;

  glm::vec4 startPlane = glm::vec4(x, y, -1.0f, 1.0f);
  glm::vec4 endPlane = glm::vec4(x, y, 1.0f, 1.0f);

  startPlane = glm::inverse(projectionMatrix) * startPlane;
  startPlane = glm::inverse(viewMatrix) * startPlane;
  startPlane = startPlane/startPlane.w;

  endPlane = glm::inverse(projectionMatrix) * endPlane;
  endPlane = glm::inverse(viewMatrix) * endPlane;
  endPlane = endPlane / endPlane.w;

  ////setting near and far plane
  //nearPlane = glm::vec4((float)mapCoordinate.x, (float)mapCoordinate.y, -1.0f, 1.0f);
  //farPlane = glm::vec4((float)mapCoordinate.x, (float)mapCoordinate.y, 1.0f, 1.0f);

  ////Doing the inverse of projection matrix onto planes
  //nearPlane = glm::inverse(projectionMatrix) * nearPlane;
  //farPlane = glm::inverse(projectionMatrix) * farPlane;

  //nearPlane = nearPlane / nearPlane.w;
  //farPlane = farPlane / farPlane.w;

  ////Applying the view matrix onto planes
  //nearPlane = glm::inverse(viewMatrix) * nearPlane;
  //farPlane = glm::inverse(viewMatrix) * farPlane;

  //Setting new origin and direction of rays after applying inverse projection and view matrix onto planes.
  //glm::vec3 newOrigin = glm::vec3(nearPlane.x, nearPlane.y, nearPlane.z);
  //glm::vec3 newDirection = glm::normalize(glm::vec3(farPlane.x, farPlane.y, farPlane.z) - newOrigin);
  //
  //_ray.origin = newOrigin;
  //_ray.direction = newDirection;

  _ray.origin = glm::vec3(startPlane);
  _ray.direction = glm::vec3(glm::normalize(endPlane - startPlane));
	 
	return _ray;
}

void Camera::setWindowsize(glm::ivec2 _windowSize)
{
  windowSize = _windowSize;
}
glm::ivec2 Camera::getWindowsize()
{
  return windowSize;
}
void Camera::setCampos(glm::vec3 camPos) 
{
	camPosition = camPos;
}

glm::vec3 Camera::getCampos() 
{
	return camPosition;
}

