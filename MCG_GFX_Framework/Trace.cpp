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
		
		glm::vec3 spherenormal = sphere.getSpherenormal();
		//intensity * light color * surface color
		glm::vec3 lightDir = glm::normalize(lightpoint.getLightpos() - tmpResult.sphereintersection);// glm::normalize(spherenormal - lightpoint.getLightpos());
		glm::vec3 ambient = glm::vec3(0.1f);

		//diffuse = surface color * light color * intensity
		glm::vec3 diffuse = glm::vec3(glm::max(glm::dot(spherenormal, lightDir), 0.0f));
		std::cout << "diffuse done" << std::endl;

		//specular
		glm::vec3 Ks = glm::vec3(1.0f); //Surface specular colour
		glm::vec3 H = glm::normalize(-_ray.direction + lightDir);// H is the half vector between light direction and eye direction.
		float stepone = glm::pow(glm::max(glm::dot(spherenormal, H), 0.0f), 32.0f);

		float facing;

		if (glm::dot(spherenormal, lightDir) > 0)
		{
			facing = 1.0f;
		}
		else
		{
			facing = 0.0f;
		}

		glm::vec3 specularlight = Ks * facing * lightpoint.getLightColour() * stepone;




		pixelColour = diffuse + ambient + specularlight;
		pixelColour = glm::clamp(pixelColour * lightpoint.getSurfaceLight() * lightpoint.getLightColour(),glm::vec3(0),glm::vec3(1));
	}
	else
	{
		pixelColour = glm::vec3(1, 1, 1);
		//std::cout << "not being drawn, yellow back" << std::endl;
	}



	return pixelColour;
}