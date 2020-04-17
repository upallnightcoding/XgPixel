#pragma once

#include "Xg.h"
#include "XgItem.h"
#include "XgShader.h"

class XgPaper
{
public:
	XgPaper();
	virtual ~XgPaper();

public:
	void add(XgItem *item);

	void animate(XgShader *shader);
	void update(float deltaTime);
	void create();

private:
	std::vector<XgItem*> itemList;
};

/*****************************************************************************
add()
*****************************************************************************/
inline void XgPaper::add(XgItem *item)
{
	if (item != NULL) {
		itemList.push_back(item);
	}
}



