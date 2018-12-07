#include "X3DDevice.h"

X3DDevice::X3DDevice(HWND hWnd, HDC mDC) {
	mRenderer = new XEngineRenderer(hWnd);
	mRenderer->Init(mDC);
	int bufferSize = mRenderer->GetHeight * mRenderer->GetWidth();
	mZBuffer = new int[bufferSize];

}

X3DDevice::X3DDevice()
{

	
	

}


X3DDevice::~X3DDevice()
{
}
