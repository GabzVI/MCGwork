#include <cmath>
#include <iostream>
#include <thread>
#include <mutex>
#include "Camera.h"
#include "Ray.h"
#include "Trace.h"
#include "Sphere.h"
#include "LightSource.h"
#include "MCG_GFX_Lib.h"

std::mutex mutex;

void thread1(Sphere sphere, Traceray traceray, intersectResult tmpResult, Camera camera, LightSource lightpoint, glm::vec3 pixelColour, float startingPoint, float endingPoint, int x, int y)
{

	

	for (int k = startingPoint; k <= y; k++)
	{

		for (int j = 0; j <= x; j++)
		{

			// Draw the pixel to the screen
			glm::ivec2 pixelPosition = glm::ivec2(j, k); //Gets the position of the pixel

			Ray raycreated = camera.Returnray(pixelPosition);//stores the returnray inside raycreated
			tmpResult = sphere.Rayintersection(raycreated);
			pixelColour = traceray.Raytracer(raycreated, tmpResult, lightpoint, sphere);
			
			pixelColour = pixelColour * 255.0f;

			mutex.lock();
			MCG::DrawPixel(pixelPosition, pixelColour);
			mutex.unlock();


		}

		mutex.lock();
		MCG::ProcessFrame();
		mutex.unlock();
		
	
	}
	std::cout << "I am inside this thread"<< std::endl;
	
}

int main(int argc, char *argv[])
{


	// Variable for storing window dimensions
	int x = 640;
	int y = 480;

	glm::ivec2 windowSize(x, y);

	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if (!MCG::Init(windowSize))
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGBA, numbers are from 0 to 255
	MCG::SetBackground(glm::ivec3(0, 0, 0));

	// Preparing a position to draw a pixel
	glm::ivec2 pixelPosition = windowSize / 2;

	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 255
	glm::vec3 pixelColour(0, 255, 0);


	// Draws a single pixel at the specified coordinates in the specified colour!
	//MCG::DrawPixel( pixelPosition, pixelColour );

	// Do any other DrawPixel calls here
	// ...

	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	//return MCG::ShowAndHold();





	// Advanced access - comment out the above DrawPixel and MCG::ShowAndHold lines, then uncomment the following:


	// Variable to keep track of time
	float timer = 0.0f;

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while (MCG::ProcessFrame())
	{
		// Set every pixel to the same colour
		//	MCG::SetBackground( glm::ivec3( 0, 0, 0 ) );

		  // Change our pixel's X coordinate according to time
		  //pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
		  // Update our time variable
		  //timer += 1.0f / 60.0f;
		Camera camera;
		Traceray traceray;
		Sphere sphere;
		intersectResult tmpResult;
		LightSource lightpoint;

		std::thread threads[30];
		

		lightpoint.setLightpos(glm::vec3(-10.0f, 0.0f, -10.0f));
		lightpoint.setLightColour(glm::vec3(1.0f, 1.0f, 1.0f));
		lightpoint.setSurfaceLight(glm::vec3(1.0f, 0.0f, 0.0f));
		lightpoint.setAmbientLight(glm::vec3(0.1f));
		lightpoint.setObjectShininess(10.0f);

		sphere.SetRadius(1.0f);
		sphere.SetSphereori(glm::vec3(0.0f, 0.0f, -10.0f));

		camera.setWindowsize(glm::ivec2(x, y));
		camera.setCampos(glm::vec3(0.0f, 0.0f, 0.0f));

		float numOfthreads = (sizeof(threads) / sizeof(*threads)); //Divides the data by length of array, gets the length of threads.
		float startingPoint = 0;
		float endingPoint =  y / numOfthreads;
		

		// for loop that goes through each thread
		for (int k = 0; k < numOfthreads; k++)
		{
			threads[k] = std::thread(&thread1, sphere, traceray, tmpResult, camera, lightpoint, pixelColour, startingPoint, endingPoint, x, y);

			startingPoint = startingPoint + endingPoint;
			std::cout << " startingPoint = " << startingPoint << std::endl;   
		 
		}
		std::cout << "Done drawing Sphere" << std::endl;

		for (int l = 0; l < numOfthreads; l++)
		{
			threads[l].join();
		}

	}


	return 0;


}
