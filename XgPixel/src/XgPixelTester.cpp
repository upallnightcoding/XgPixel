// XgPixel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "XgPixel.h"
#include "XgPixelTestBed.h"

int main()
{
	

	XgPixel pixel("XgPixel Test Bed", 1000, 600);
	
	XgPaper *paper = XgPixelTestBed::CharacterAttack();

	pixel.add(paper);

	pixel.startAnimation();
}

