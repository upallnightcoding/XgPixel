#include "XgWindow.h"

#include "XgKeyboard.h"

#include <iostream>

using namespace std;

#include "XgConstants.h"

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	cout << "Input: " << key << ":" << scancode << ":" << action << ":" << mods << endl;

	XgKeyboard::getInstance()->setKey(key, scancode, action, mods);

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

/*****************************************************************************
mouseCallback()
*****************************************************************************/
void mouseCallback(GLFWwindow* window, double xpos, double ypos) 
{
	XgKeyboard::getInstance()->setMousePosition(xpos, ypos);
}

/*****************************************************************************
scrollCallback()
*****************************************************************************/
void scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	XgKeyboard::getInstance()->setScrollPosition(xOffset, yOffset);
}

XgWindow::XgWindow(string title, int screenWidth, int screenHeight)
{
	this->screenSize = new XgScreenSize(screenWidth, screenHeight);
	this->title = title;
}

XgWindow::~XgWindow()
{
	delete screenSize;
}

/*****************************************************************************
startAnimation()
*****************************************************************************/
int XgWindow::startAnimation()
{
	// glfw: initialize and configure opengl session
	// ---------------------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//GLFWmonitor* primary = glfwGetPrimaryMonitor();
	GLFWmonitor* primary = NULL;

	GLFWwindow* window = glfwCreateWindow(screenSize->width(), screenSize->height(), title.c_str(), primary, NULL);

	// Check to make sure the window was correctly created
	//----------------------------------------------------
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Setup the context, window and device input callbacks
	//-----------------------------------------------------
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetScrollCallback(window, scrollCallback);
	glfwSetKeyCallback(window, processInputCallback);

	// tell GLFW to capture our mouse
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Initialize GLEW
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	// Configure global opengl states
	// -----------------------------
	//glfwSwapInterval(1);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	//glShadeModel(GL_FLAT);

	// Initialize rendering
	//---------------------
	initRender(window);

	// Start the rendering loop
	//-------------------------
	renderLoop(window);

	// Close and end the rendering loop
	//---------------------------------
	closeRender();

	// Terminate the OpenGl session and de-allocated all GLFW resources.
	// -----------------------------------------------------------------
	glfwTerminate();

	return 0;
}

/*****************************************************************************
renderLoop() -
*****************************************************************************/
void XgWindow::renderLoop(GLFWwindow* window)
{
	// TODO Parameterize the 60.0
	static float limitFPS = 1.0f / 60.0f;

	float lastTime = (float)glfwGetTime(), timer = lastTime;
	float deltaTime = 0, nowTime = 0;
	int tickCount = 0, fps = 0;

	// Main Render Loop
	// ----------------
	while (!glfwWindowShouldClose(window)) {
		// - Measure time
		nowTime = (float)glfwGetTime();
		deltaTime += (nowTime - lastTime) / limitFPS;
		lastTime = nowTime;

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderScreen(deltaTime, fps);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();

		tickCount++;

		// - Reset after one second
		if (nowTime - timer > 1.0) {
			timer = nowTime;
			std::cout << "Ticks: " << tickCount << " FPS:" << fps << std::endl;
			fps = 0; tickCount = 0;
		}
	}
}

