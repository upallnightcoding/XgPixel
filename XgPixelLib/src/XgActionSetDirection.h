#pragma once
#include "XgAction.h"
#include "XgItem.h"

class XgActionSetDirection :
	public XgAction
{
public:
	XgActionSetDirection(float x, float y, float z);
	virtual ~XgActionSetDirection();

public:
	virtual void update(float deltaTime, XgItem *item);

private:
	float x, y, z;
	bool firstTime;
};

