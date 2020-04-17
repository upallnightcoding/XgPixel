#include "XgCharacter.h"

#include "XgConstants.h"

XgCharacter::XgCharacter()
{
	localBehavior = new XgBehavior();
	framework = NULL;
	flipBook = 0;
}

XgCharacter::~XgCharacter()
{
	delete localBehavior;

	if (framework != NULL) {
		delete framework;
	}
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgCharacter::add(XgFlipBook *flipBook)
{
	if (flipBook != NULL) {
		flipBookList.push_back(flipBook);
	}
}

/*****************************************************************************
update()
*****************************************************************************/
void XgCharacter::changeFlipBook(int flipBook)
{
	this->flipBook = flipBook;
}

/*****************************************************************************
animate()
*****************************************************************************/
void XgCharacter::dispose()
{

}

/*****************************************************************************
animate()
*****************************************************************************/
void XgCharacter::draw()
{
	if (flipBook != XgConstant::FLIP_BOOK_NULL) {
		flipBookList.at(flipBook)->draw();
	}
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgCharacter::create()
{
	for (auto flipBook : flipBookList) {
		flipBook->create();
	}
}

/*****************************************************************************
render() -
*****************************************************************************/
void XgCharacter::render(XgShader *shader)
{
	shader->uniform(XgConstant::UNIFORM_TRANSFORM, transform.getTransformMatrix());

	draw();
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgCharacter::add(XgAction *action)
{
	if (action != NULL) {
		localBehavior->add(action);
	}
}

/*****************************************************************************
add() - Adds a framework object to an item.  The item can now be manipulated
by using the states and action of a framework.  If the object framework is
NULL, it is not added to the item object.
*****************************************************************************/
void XgCharacter::fsm(XgFramework *framework)
{
	if (framework != NULL) {
		this->framework = framework;
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgCharacter::update(float deltaTime)
{
	if (framework != NULL) {
		XgBehavior *behavior = framework->update();

		if (behavior != NULL) {
			behavior->update(deltaTime, this);
		}
	}

	localBehavior->update(deltaTime, this);

	flipBookList.at(flipBook)->update(deltaTime);
}

/*****************************************************************************
getTransform() - Returns a reference to the transform object.  This 
function should always return a non-NULL object.
*****************************************************************************/
XgTransform *XgCharacter::getTransform()
{
	return(&transform);
}
