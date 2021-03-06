#include <cmath>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "Camera.h"
#include "Ray.h"
#include "Trace.h"
#include "Sphere.h"
#include "LightSource.h"
#include "MCG_GFX_Lib.h"

std::mutex mutex;

void thread1(int id, int count, Sphere sphere, Traceray traceray, Camera camera, LightSource lightpoint, float startingPoint, float endingPoint, int x, int y)
{


	for (int k = startingPoint; k <= y; k++)
	{

		for (int j = 0; j <= x; j++)
		{
			glm::vec3 pixelColour;

			// Draw the pixel to the screen
			glm::ivec2 pixelPosition = glm::ivec2(j, k); //Gets the position of the pixel

			Ray raycreated = camera.Returnray(pixelPosition);//stores the returnray inside raycreated
			intersectResult tmpResult = sphere.Rayintersection(raycreated);
			pixelColour = traceray.Raytracer(raycreated, tmpResult, lightpoint, sphere);

			pixelColour = pixelColour * 255.0f;

			if (tmpResult.distfromCameratoSphere)
			{
				mutex.lock();
				MCG::DrawPixel(pixelPosition, pixelColour);
				mutex.unlock();
			}

		}

		if (id == 0)
		{
			mutex.lock();
			MCG::ProcessFrame();
			mutex.unlock();
		}

	}


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
		Sphere sphere[2];
		LightSource lightpoint;


    #define NUM_THREADS 10 //Change the number to whatever amount of threads you want to have
		std::thread threads[NUM_THREADS];

		lightpoint.setLightpos(glm::vec3(-10.0f, 0.0f, -10.0f));
		lightpoint.setLightColour(glm::vec3(1.0f, 1.0f, 1.0f));
		lightpoint.setSurfaceLight(glm::vec3(1.0f, 0.0f, 0.0f));
		lightpoint.setAmbientLight(glm::vec3(0.1f));
		lightpoint.setObjectShininess(10.0f);


		for (int i = 0; i < 2; i++)
		{
			sphere[i].SetRadius(1.0f);
			sphere[i].SetSphereori(glm::vec3(0.0f, 0.0f, -10.0f));
		}

		sphere[1].SetRadius(0.5f);
		sphere[1].SetSphereori(glm::vec3(-1.0f, 0.0f, -10.0f));
		sphere[2].SetRadius(0.5f);
		sphere[2].SetSphereori(glm::vec3(1.0f, 0.0f, -10.0f));


		camera.setWindowsize(glm::ivec2(x, y));
		camera.setCampos(glm::vec3(0.0f, 0.0f, 0.0f));

		float numOfthreads = NUM_THREADS;
		float startingPoint = 0;
		float endingPoint = y / numOfthreads;
		int id = 0;
		int count = 0;

		auto start = std::chrono::high_resolution_clock::now();
		// for loop that goes through each thread
		for (int k = 0; k < numOfthreads; k++)
		{
			count = k; 
			threads[k] = std::thread(&thread1, id, count, sphere[k], traceray, camera, lightpoint, startingPoint, endingPoint, x, y);


			startingPoint = startingPoint + endingPoint;

			//std::cout << " startingPoint = " << startingPoint << std::endl;   

		}

		auto stop = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double>elapsed = stop - start;
		std::cout << "Time taken: " << elapsed.count() << "s\n";

		for (int l = 0; l < numOfthreads; l++)
		{
			threads[l].join();
		}

		std::cout << "Done drawing Sphere" << std::endl;

	}


	return 0;


}






