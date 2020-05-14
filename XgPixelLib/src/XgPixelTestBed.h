#pragma once

#include "XgPaper.h"

class XgPixelTestBed
{
public:
	XgPixelTestBed();
	virtual ~XgPixelTestBed();

public:
	static XgPaper *characterAttack();
	static XgPaper *characterIdle();
	static XgPaper *characterTwoIdle();
};

