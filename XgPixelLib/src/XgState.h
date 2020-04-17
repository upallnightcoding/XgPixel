#pragma once

#include "Xg.h"
#include "XgEvent.h"

/*****************************************************************************
class XgState
*****************************************************************************/

class XgBehavior;
class XgAction;

class XgState
{
public:
	XgState(std::string name);
	virtual ~XgState();

public:
	void add(XgAction *action);
	//void add(XgBehavior *behavior);
	void add(XgEvent *event);

	std::string update();

public:
	std::string name();
	XgBehavior *behavior();

private:
	std::string pName;
	XgBehavior *pBehavior;
	std::vector<XgEvent*> pEventList;
};

#include "XgBehavior.h"
#include "XgAction.h"