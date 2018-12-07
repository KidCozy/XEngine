#pragma once
#include"XEngineRenderer.h"
class X3DDevice
{
private:
	int* mZBuffer;
	XEngineRenderer* mRenderer;

public:
	X3DDevice();
	X3DDevice(HWND hWnd, HDC mDC);
	~X3DDevice();


};

