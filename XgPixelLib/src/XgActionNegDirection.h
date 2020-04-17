#pragma once
#include "XgAction.h"
#include "XgItem.h"

class XgActionNegDirection :
	public XgAction
{
public:
	XgActionNegDirection();
	virtual ~XgActionNegDirection();

public:
	virtual void update(float deltaTime, XgItem *item);
};

