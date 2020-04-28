#pragma once
#include "XgShader.h"
#include "XgCamera.h"

class XgShaderObject :
	public XgShader
{
public:
	XgShaderObject(std::string pathName);
	virtual ~XgShaderObject();

public:
	virtual void apply(XgCamera *camera, XgScreenSize *screenSize, XgTransform &transform);
};

