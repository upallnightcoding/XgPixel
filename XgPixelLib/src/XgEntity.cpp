#include "XgEntity.h"

#include "XgConstants.h"

XgEntity::XgEntity()
{
	flipBook = 0;
}


XgEntity::~XgEntity()
{
}

/*****************************************************************************
update()
*****************************************************************************/
void XgEntity::changeFlipBook(int flipBook)
{
	this->flipBook = flipBook;
}

/*****************************************************************************
update()
*****************************************************************************/
void XgEntity::update(float deltaTime)
{
	XgItem::update(deltaTime);

	flipBookList.at(flipBook)->update(deltaTime);
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgEntity::create()
{
	for (auto flipBook : flipBookList) {
		flipBook->create();
	}
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgEntity::add(XgFlipBook *flipBook)
{
	if (flipBook != NULL) {
		flipBookList.push_back(flipBook);
	}
}

/*****************************************************************************
animate()
*****************************************************************************/
void XgEntity::draw()
{
	if (flipBook != XgConstant::FLIP_BOOK_NULL) {
		flipBookList.at(flipBook)->draw();
	}
}

/*****************************************************************************
animate()
*****************************************************************************/
void XgEntity::dispose()
{

}