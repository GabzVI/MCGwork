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
		
		pixelColour = lightpoint.Diffuselight(sphere , tmpResult) + lightpoint.getAmbientLight()  + lightpoint.getSpecularLight(_ray , sphere, tmpResult); // Diffuse + Ambient + specular light
		pixelColour = glm::clamp(pixelColour * lightpoint.getSurfaceLight() * lightpoint.getLightColour(), glm::vec3(0), glm::vec3(1));

	}
	else
	{
		pixelColour = glm::vec3(1, 1, 1);
		//std::cout << "not being drawn, yellow back" << std::endl;
	}



	return pixelColour;
}