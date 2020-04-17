#pragma once

class XgItem;

class XgAction
{
public:
	XgAction();
	virtual ~XgAction();

public:
	virtual void update(float deltaTime, XgItem *item) = 0;
};

#include "XgItem.h"