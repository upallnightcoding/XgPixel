#pragma once

#include "Xg.h"
#include "XgCharacter.h"
#include "XgShader.h"

class XgPaper
{
public:
	XgPaper();
	virtual ~XgPaper();

public:
	void add(XgCharacter *item);

	void animate(XgShader *shader);
	void update(float deltaTime);
	void create();

private:
	std::vector<XgCharacter*> itemList;
};

/*****************************************************************************
add()
*****************************************************************************/
inline void XgPaper::add(XgCharacter *item)
{
	if (item != NULL) {
		itemList.push_back(item);
	}
}



