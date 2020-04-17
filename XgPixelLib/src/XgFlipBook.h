#pragma once

#include "XgSprite.h"

/*****************************************************************************
XgFlipBook
*****************************************************************************/
class XgFlipBook
{
public:
	XgFlipBook();
	virtual ~XgFlipBook();

public:
	void add(XgSprite *sprite);
	
	void draw();
	void create();
	void update(float deltaTime);

private:
	// List of animation images
	std::vector<XgSprite*> flipBookList;

	// Number of images in the flipbook
	int nSprites;

	// Current image being displayed
	int currentSprite;

	// Current speed of animation
	float speed;
	float speedBuffer;
};


