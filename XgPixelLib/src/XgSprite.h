#pragma once

#include "Xg.h"
#include "XgItem.h"
#include "XgAction.h"
//#include "XgBehavior.h"

class XgSprite 
	: public XgItem
{
public:
	XgSprite(std::string texturePath);
	virtual ~XgSprite();

public:
	virtual void dispose();
	virtual void draw();
	virtual void create();

private:
	void dataFormat();
	void loadTexture();

private:
	std::string imagePath;

	unsigned int vbo, vao, ebo;

	unsigned int texture;
	
	float vertices[32] = {
		// positions          // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
	};

	unsigned int indices[6] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
};



