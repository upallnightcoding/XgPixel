#include "XgActionSetDirection.h"



XgActionSetDirection::XgActionSetDirection(float x, float y, float z)
{
	firstTime = true;

	this->x = x;
	this->y = y;
	this->z = z;
}


XgActionSetDirection::~XgActionSetDirection()
{
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgActionSetDirection::update(float deltaTime, XgItem *item)
{
	if (firstTime) {
		firstTime = false;

		item->getTransform()->setDirection(x, y, z);
	}
}