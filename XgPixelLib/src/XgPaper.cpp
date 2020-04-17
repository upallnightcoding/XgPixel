#include "XgPaper.h"



XgPaper::XgPaper()
{
	
}


XgPaper::~XgPaper()
{
	
}

/*****************************************************************************
animate()
*****************************************************************************/
void XgPaper::animate(XgShader *shader)
{
	// Animate all sprites that are on the paper
	//------------------------------------------
	for (auto item : itemList) {
		item->render(shader);
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgPaper::update(float deltaTime)
{
	// Animate all entities that are on the paper
	//-------------------------------------------
	for (auto item : itemList) {
		item->update(deltaTime);
	}
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgPaper::create()
{
	// Animate all entities that are on the paper
	//-------------------------------------------
	for (auto item : itemList) {
		item->create();
	}
}