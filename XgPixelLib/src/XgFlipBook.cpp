#include "XgFlipBook.h"


XgFlipBook::XgFlipBook(float speed)
{
	this->xScale = 1.0;
	this->yScale = 1.0;

	this->speed = speed;

	flipBookId = new int();
}

XgFlipBook::~XgFlipBook()
{
}

/*****************************************************************************
setId() -
*****************************************************************************/
void XgFlipBook::setId(int flipBookId)
{
	*(this->flipBookId) = flipBookId;
}

/*****************************************************************************
getId() -
*****************************************************************************/
int *XgFlipBook::getId()
{
	return(flipBookId);
}

/*****************************************************************************
setScale() -
*****************************************************************************/
void XgFlipBook::setScale(float value)
{
	setScale(value, value);
}

/*****************************************************************************
setScale() -
*****************************************************************************/
void XgFlipBook::setScale(float xScale, float yScale)
{
	this->xScale *= xScale;
	this->yScale *= yScale;
}

/*****************************************************************************
setScale() -
*****************************************************************************/
void XgFlipBook::setScale(XgTransform *transform)
{
	return(transform->scale(xScale, yScale));
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
	flipBookList.at(currentSprite)->draw();
}

/*****************************************************************************
getHeightWidthRatio() -
*****************************************************************************/
float XgFlipBook::getHeightWidthRatio()
{
	return(flipBookList.at(currentSprite)->getHeightWidthRatio());
}

/*****************************************************************************
collision() -
*****************************************************************************/
void XgFlipBook::collision()
{
	flipBookList.at(currentSprite)->collision();
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