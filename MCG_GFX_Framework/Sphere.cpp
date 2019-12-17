#include "Sphere.h"
#include "Ray.h"
#include "Camera.h"
#include <iostream>


intersectResult Sphere::Rayintersection(Ray _ray) 
{
	intersectResult rtn;
	Camera camera;
	
	/* TODO: KP Debug, compare against GLM ray sphere */
	/* TODO: https://glm.g-truc.net/0.9.5/api/a00203.html */

	//Steps of Equation for intersection of sphere
	glm::vec3 pa = sphereOri - _ray.origin; 
	float dist = glm::length(pa);
	float a = glm::dot(pa, glm::normalize(_ray.direction)); 

	rtn.distfromCameratoSphere = glm::distance(rtn.sphereintersection, camera.getCampos()); //Calculates distance between intersectionpoint of sphere and camera origin.

	if (dist <= radius) 
	{
		//std::cout << "ray origin is inside sphere\n";
		rtn.hit = false;
		return rtn;
	}

	glm::vec3 dVec = pa - (a * glm::normalize(_ray.direction));
	dist = glm::length(dVec);

	if (dist <= radius) 
	{
    rtn.hit = true;
	float x = glm::sqrt(pow(radius, 2) - pow(dist, 2));
	rtn.pointdistance = a - x;
	rtn.sphereintersection = _ray.origin + (rtn.pointdistance)*(_ray.direction);
	sphereNormal = glm::normalize(rtn.sphereintersection - sphereOri);
	}
	else 
	{
		rtn.hit = false;  
	}
	
	return rtn;
 
}

void Sphere::SetRadius(float _setr)
{
	radius = _setr;
}

void Sphere::SetSphereori(glm::vec3 _setsphereOri)
{
	sphereOri = _setsphereOri;
}

float Sphere::getRadius()
{
	return radius;
}

glm::vec3 Sphere::getSphereori() 
{
	return sphereOri;
}

glm::vec3 Sphere::getSpherenormal()
{
  return sphereNormal;
}
