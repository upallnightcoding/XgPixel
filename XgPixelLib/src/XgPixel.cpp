#include "XgPixel.h"

#include "XgConstants.h"

XgPixel::XgPixel(std::string title, int screenWidth, int screenHeight)
	: XgWindow(title, screenWidth, screenHeight)
{
	shader = new XgShader(XgConstant::SPRITE_SHADER);
}

XgPixel::~XgPixel()
{
	delete paper;

	delete shader;
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::initRender(GLFWwindow* window)
{
	paper->create();

	camera.setPosition(5.0);

	camera.create(window);

	shader->create();

	shader->use();

	shader->uniform("u_View", camera.getView());

	shader->uniform("u_Projection", screenSize->getPerspective());

	//renderContext = new XgRenderContext();
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::renderScreen(float &deltaTime, int &fps)
{
	updateDeltaTime(deltaTime, fps);

	paper->animate(shader);
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::closeRender()
{

}

/*****************************************************************************
add() -
*****************************************************************************/
void XgPixel::add(XgPaper *paper)
{
	this->paper = paper;
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::updateDeltaTime(float &deltaTime, int &fps)
{
	while (deltaTime >= 1.0) {
		//camera.update(renderContext);
		//light.update();

		paper->update(deltaTime);

		//for (auto object : objectList) {
			//object->update(deltaTime);
		//}

		fps++;
		deltaTime--;
	}
}