#include "Sphere.h"
#include "Ray.h"
#include <iostream>


intersectResult Sphere::Rayintersection(Ray _ray) 
{

	intersectResult rtn;
	
	

	//Steps of Equation
	glm::vec3 pa = sphereOri - _ray.origin; //(P -a)
	float dist = glm::length(pa); //((P-a).n)
	float a = glm::dot(pa, glm::normalize(_ray.direction)); //((P-a).n)


	if (dist <= radius) {
		std::cout << "ray origin is inside sphere\n";
		rtn.hit = false;
		return rtn;
	}

	//glm::vec3 X = steptwo * n;//((P - a) . n) * n)

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