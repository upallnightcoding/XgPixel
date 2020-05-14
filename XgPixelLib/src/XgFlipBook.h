#pragma once

#include "XgSprite.h"
#include "XgTransform.h"

/*****************************************************************************
XgFlipBook
*****************************************************************************/
class XgFlipBook
{
public:
	XgFlipBook(float speed);
	virtual ~XgFlipBook();

public:
	void add(XgSprite *sprite);
	
	void draw();
	void collision();
	void create();
	void update(float deltaTime);

	void setId(int flipBookId);
	int *getId();

	void worldCord(XgTransform &transform);

	float getHeightWidthRatio();

	void bindVao();

private:
	// List of animation images
	std::vector<XgSprite*> spriteList;

	// Number of images in the flipbook
	int nSprites;

	// Current image being displayed
	int currentSprite;

	// Current speed of animation
	float animationSpeed;
	float speedBuffer;
	float speed;

	int *spriteId;
};


