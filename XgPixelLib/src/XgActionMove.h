#pragma once
#include "XgAction.h"
#include "XgItem.h"

class XgActionMove :
	public XgAction
{
public:
	XgActionMove(float dx, float dy);
	XgActionMove(float dx, float dy, float dz);
	virtual ~XgActionMove();

public:
	virtual void update(float deltaTime, XgItem *item);

private:
	float dx, dy, dz;
};

