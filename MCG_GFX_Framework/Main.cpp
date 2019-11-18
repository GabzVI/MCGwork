#include <cmath>
#include "Camera.h"
#include "Ray.h"
#include "Trace.h"
#include "MCG_GFX_Lib.h"



int main( int argc, char *argv[] )
{


	// Variable for storing window dimensions
	int x = 480;
	int y = 640;


	glm::ivec2 windowSize( x, y );

	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if( !MCG::Init( windowSize ) )
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGBA, numbers are from 0 to 255
	MCG::SetBackground( glm::ivec3(0,0,0) );

	// Preparing a position to draw a pixel
	glm::ivec2 pixelPosition = windowSize / 2;

	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 255
	glm::ivec3 pixelColour( 0, 255, 0);


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
	while( MCG::ProcessFrame() )
	{
		// Set every pixel to the same colour
	//	MCG::SetBackground( glm::ivec3( 0, 0, 0 ) );

		// Change our pixel's X coordinate according to time
		//pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
		// Update our time variable
		//timer += 1.0f / 60.0f;
    Camera camera;
    Traceray traceray;
    


		for (int i = 0; i <= y; i++ ) 
		{
			for (int j = 0; j <= x; j++) 
			{
				// Draw the pixel to the screen
        glm::ivec2 pixelPosition = glm::ivec2(j, i); //Gets the position of the pixel

        Ray raycreated = camera.Returnray(pixelPosition);  //stores the returnray inside raycreated
        pixelColour = traceray.Raytracer(raycreated);

				MCG::DrawPixel(pixelPosition, pixelColour);
       
			}
		}
		MCG::ProcessFrame();


	}

	

	return 0;
	

}
