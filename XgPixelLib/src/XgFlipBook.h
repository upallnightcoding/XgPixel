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
	void create();
	void update(float deltaTime);

	void setScale(float scale);
	void setScale(float xScale, float yScale);
	void setScale(XgTransform *transform);

	void setId(int flipBookId);
	int *getId();

private:
	// List of animation images
	std::vector<XgSprite*> flipBookList;

	// Number of images in the flipbook
	int nSprites;

	// Current image being displayed
	int currentSprite;

	// Current speed of animation
	float animationSpeed;
	float speedBuffer;
	float speed;

	float xScale, yScale;

	int *flipBookId;
};


