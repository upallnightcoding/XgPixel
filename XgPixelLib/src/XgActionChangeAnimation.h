#pragma once
#include "XgAction.h"
#include "XgCharacter.h"
//#include "XgEntity.h"

class XgActionChangeAnimation :
	public XgAction
{
public:
	XgActionChangeAnimation(int flipBook);
	virtual ~XgActionChangeAnimation();

public:
	void update(float deltaTime, XgCharacter *item);

private:
	int flipBook;
};

