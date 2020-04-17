#pragma once

#include "XgTransform.h"
#include "XgShader.h"
#include "XgAction.h"
#include "XgFlipBook.h"

class XgBehavior;
class XgFramework;

class XgCharacter
{
public:
	XgCharacter();
	virtual ~XgCharacter();

public:
	virtual void create();
	virtual void dispose();
	virtual void draw();

	virtual void update(float deltaTime);

public:
	void add(XgFlipBook *flipBook);
	void add(XgAction *action);

	void changeFlipBook(int flipBook);

	void fsm(XgFramework *framework);

	void render(XgShader *shader);

	XgTransform *getTransform();

private:
	std::vector<XgFlipBook*> flipBookList;
	int flipBook;

	XgTransform transform;

	XgFramework *framework;

	XgBehavior *localBehavior;
};

#include "XgBehavior.h"
#include "XgFramework.h"