#include "XgFlipBook.h"



XgFlipBook::XgFlipBook()
{
	
}


XgFlipBook::~XgFlipBook()
{
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgFlipBook::add(XgSprite *sprite)
{
	if (sprite != NULL) {
		flipBookList.push_back(sprite);
	}
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgFlipBook::create()
{
	for (auto sprite : flipBookList) {
		sprite->create();
	}

	nSprites = flipBookList.size();
	currentSprite = 0;

	speed = 60 / 30;
	speedBuffer = 0.0;
}

/*****************************************************************************
animate() - Executes the animation of a flipbook.  The transformation of the
object is set first via a uniform and the current sprite of the flipbook is
drawn with the current shader.
*****************************************************************************/
void XgFlipBook::draw()
{
	flipBookList.at(currentSprite)->draw();
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgFlipBook::update(float deltaTime)
{
	speedBuffer += deltaTime;

	if (speedBuffer > speed) {
		currentSprite = ++currentSprite % nSprites;
		speedBuffer = 0.0;
	}
}