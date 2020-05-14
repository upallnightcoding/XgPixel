#include "XgFlipBook.h"


XgFlipBook::XgFlipBook(float speed)
{
	this->speed = speed;

	spriteId = new int();
}

XgFlipBook::~XgFlipBook()
{
}

/*****************************************************************************
setId() -
*****************************************************************************/
void XgFlipBook::setId(int flipBookId)
{
	*(this->spriteId) = flipBookId;
}

/*****************************************************************************
getId() -
*****************************************************************************/
int *XgFlipBook::getId()
{
	return(spriteId);
}


/*****************************************************************************
add() -
*****************************************************************************/
void XgFlipBook::add(XgSprite *sprite)
{
	if (sprite != NULL) {
		spriteList.push_back(sprite);
	}
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgFlipBook::create()
{
	for (auto sprite : spriteList) {
		sprite->create();
	}

	nSprites = spriteList.size();
	currentSprite = 0;

	animationSpeed = 60 / speed;
	speedBuffer = 0.0;
}

/*****************************************************************************
draw() - Executes the animation of a flipbook.  The transformation of the
object is set first via a uniform and the current sprite of the flipbook is
drawn with the current shader.
*****************************************************************************/
void XgFlipBook::draw()
{
	spriteList.at(currentSprite)->draw();
}

void XgFlipBook::bindVao()
{
	spriteList.at(currentSprite)->bindVao();
}

/*****************************************************************************
worldCord() -
*****************************************************************************/
void XgFlipBook::worldCord(XgTransform &transform)
{
	spriteList.at(currentSprite)->worldCord(transform);
}

/*****************************************************************************
getHeightWidthRatio() -
*****************************************************************************/
float XgFlipBook::getHeightWidthRatio()
{
	return(spriteList.at(currentSprite)->getHeightWidthRatio());
}

/*****************************************************************************
collision() -
*****************************************************************************/
void XgFlipBook::collision()
{
	spriteList.at(currentSprite)->collision();
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgFlipBook::update(float deltaTime)
{
	speedBuffer += deltaTime;

	if (speedBuffer > animationSpeed) {
		currentSprite = ++currentSprite % nSprites;
		speedBuffer = 0.0;
	}
}