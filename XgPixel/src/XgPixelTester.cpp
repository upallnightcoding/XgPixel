// XgPixel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "XgPixel.h"
#include "XgPixelTestBed.h"

int main()
{
	// (1) Define the 2D engine
	//-------------------------
	XgPixel pixel("XgPixel Test Bed", 600, 600);
	
	// (2) Create 2D paper object container
	//-------------------------------------
	XgPaper *paper = XgPixelTestBed::characterTwoIdle();

	// (3) Add the 2D object into the engine
	//--------------------------------------
	pixel.add(paper);

	// (4) Start the engine animation
	//-------------------------------
	pixel.startAnimation();
}

