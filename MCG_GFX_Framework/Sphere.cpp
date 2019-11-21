#include "Sphere.h"
#include "Ray.h"


intersectResult Sphere::Rayintersection(Ray _ray) 
{
	//Variables used in the equation
	glm::vec3 a = _ray.origin;
	glm::vec3 P = sphereOri;
	glm::vec3 n = _ray.direction;
	

	//Steps of Equation
	glm::vec3 stepone = P - a; //(P -a)
	float steptwo = glm::dot(stepone, n); //((P-a).n)
	glm::vec3 X = steptwo * n;//((P - a) . n) * n)

	float d = glm::length(P - a - X); //Distance between Center of sphere and X // d = (P - a - ((P-a) . n)* n)))

	float x = glm::sqrt(radius * radius - d * d); //x = square root(radius squared - d squared)


	glm::vec3 sphererayintesection = a + ((X - x)*n);
  
  sphereNormal = glm::normalize(sphererayintesection - sphereOri);//Normalizing normal of the sphere which gives a 3d vector direction

	intersectResult rtn;
  rtn.pointdistance = d;
  rtn.sphereintersection = sphererayintesection;

	if (d <= radius) 
	{
		rtn.hit = true;
    
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