#pragma once

#include "XgTransform.h"
#include "XgShader.h"
#include "XgAction.h"

class XgBehavior;
class XgFramework;

class XgItem
{
public:
	XgItem();
	virtual ~XgItem();

public:
	virtual void create() = 0;
	virtual void dispose() = 0;
	virtual void draw() = 0;

	virtual void update(float deltaTime);

public:
	void add(XgAction *action);
	void fsm(XgFramework *framework);

	void render(XgShader *shader);

	XgTransform *getTransform();

private:
	XgTransform transform;

	XgFramework *framework;

	XgBehavior *localBehavior;
};

#include "XgBehavior.h"
#include "XgFramework.h"