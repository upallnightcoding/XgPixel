#include "XgActionNegDirection.h"



XgActionNegDirection::XgActionNegDirection()
{
}


XgActionNegDirection::~XgActionNegDirection()
{
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgActionNegDirection::update(float deltaTime, XgItem *item)
{
	item->getTransform()->flipDirection();
}
