#pragma once
#include "XgCharacter.h"
class XgBackGround :
	public XgCharacter
{
public:
	XgBackGround(std::string imageName);
	virtual ~XgBackGround();

public:
	void setScale(float xScale, float yScale);
	void setScale(float value);

private:
	XgFlipBook *flipBook;
};

