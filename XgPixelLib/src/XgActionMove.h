#pragma once
#include "XgAction.h"
#include "XgCharacter.h"

class XgActionMove :
	public XgAction
{
public:
	XgActionMove(float dx, float dy);
	XgActionMove(float dx, float dy, float dz);
	virtual ~XgActionMove();

public:
	virtual void update(float deltaTime, XgCharacter *item);

private:
	float dx, dy, dz;
};

