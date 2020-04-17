#pragma once

#include "Xg.h"
#include "XgFlipBook.h"
#include "XgItem.h"

class XgEntity 
	: public XgItem
{
public:
	XgEntity();
	virtual ~XgEntity();

public:
	virtual void draw();
	virtual void create();
	virtual void dispose();

	virtual void update(float deltaTime);

	void add(XgFlipBook *flipBook);
	void changeFlipBook(int flipBook);

private:
	std::vector<XgFlipBook*> flipBookList;
	int flipBook;
};
