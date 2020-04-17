#pragma once
#include "XgAction.h"
#include "XgItem.h"
#include "XgEntity.h"

class XgActionFlipBook :
	public XgAction
{
public:
	XgActionFlipBook(int flipBook);
	virtual ~XgActionFlipBook();

public:
	void update(float deltaTime, XgItem *item);

private:
	int flipBook;
	bool firstTime;
	XgEntity *entity;
};

