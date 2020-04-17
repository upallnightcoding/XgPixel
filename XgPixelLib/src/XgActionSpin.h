#pragma once
#include "XgAction.h"
#include "XgItem.h"

class XgActionSpin :
	public XgAction
{
public:
	XgActionSpin(float dx, float dy, float dz);
	virtual ~XgActionSpin();

public:
	virtual void update(float deltaTime, XgItem *item);

private:
	float dx;
	float dy;
	float dz;
};

