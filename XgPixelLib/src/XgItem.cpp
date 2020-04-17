#include "XgItem.h"

#include "XgConstants.h"

XgItem::XgItem()
{
	localBehavior = new XgBehavior();
	framework = NULL;
}

XgItem::~XgItem()
{
	delete localBehavior;

	if (framework != NULL) {
		delete framework;
	}
}

/*****************************************************************************
render() -
*****************************************************************************/
void XgItem::render(XgShader *shader)
{
	shader->uniform(XgConstant::UNIFORM_TRANSFORM, transform.getTransformMatrix());

	draw();
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgItem::add(XgAction *action)
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
void XgItem::fsm(XgFramework *framework)
{
	if (framework != NULL) {
		this->framework = framework;
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgItem::update(float deltaTime)
{
	if (framework != NULL) {
		XgBehavior *behavior = framework->update();

		if (behavior != NULL) {
			behavior->update(deltaTime, this);
		}
	}

	localBehavior->update(deltaTime, this);
}

/*****************************************************************************
getTransform() - Returns a reference to the transform object.  This 
function should always return a non-NULL object.
*****************************************************************************/
XgTransform *XgItem::getTransform()
{
	return(&transform);
}
