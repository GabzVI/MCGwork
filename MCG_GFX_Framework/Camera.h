#include <glm/glm.hpp>

class Ray;
class Sphere;

class Camera 
{

private:
	glm::vec3 camPosition; // Camera Position
	glm::vec3 camOrientation; //Camera Oritentation
	glm::vec3 pixelNDC;
	glm::mat4 view;
	glm::mat4 projection;


public:

	Ray Returnray(glm::ivec2 _pixelcp, Sphere sphere);
	void setCampos(glm::vec3 camPos);
	void setCamori(glm::vec3 camOri);
	glm::vec3 getCampos();
	glm::vec3 getCamori();
};



