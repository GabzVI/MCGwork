#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Ray;
class Sphere;

class Camera 
{

private:
	glm::vec3 camPosition; // Camera Position
	glm::vec3 camOrientation; //Camera Oritentation
  glm::ivec2 windowSize;
  glm::vec3 mapCoordinate;
  glm::vec4 nearPlane;
  glm::vec4 farPlane;
	glm::mat4 projectionMatrix;
  glm::mat4 viewMatrix;


public:

	Ray Returnray(glm::ivec2 _pixelcp);
	void setCampos(glm::vec3 camPos);
	void setCamori(glm::vec3 camOri);
  void setCamera(glm::mat4 _view, glm::mat4 _projetction);
  glm::mat4 getCamera();
	glm::vec3 getCampos();
	glm::vec3 getCamori();
};



