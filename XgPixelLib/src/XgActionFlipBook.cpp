#include "XgActionFlipBook.h"

#include "XgConstants.h"

XgActionFlipBook::XgActionFlipBook(int flipBook)
{
	this->flipBook = flipBook;
	firstTime = true;
}


XgActionFlipBook::~XgActionFlipBook()
{
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgActionFlipBook::update(float deltaTime, XgItem *item)
{
	if (firstTime) {
		firstTime = false;

		entity = (XgEntity *)item;
	}

	entity->changeFlipBook(flipBook);
}