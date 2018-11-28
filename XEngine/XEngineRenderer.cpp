#include "stdafx.h"
#include "XEngineRenderer.h"

using namespace align;

void XEngineRenderer::SetParams() {
	temp.p0 = { mWidth / 2,mHeight / 2 };
	pTemp = &temp;
}

void XEngineRenderer::Init(HWND hWnd, HDC DC) {
	mDC = DC;
	mHwnd = hWnd;

	GetClientRect(hWnd, &mRect);

	mWidth = mRect.right;
	mHeight = mRect.bottom;
	
}



void XEngineRenderer::Render()
{
	DrawGizmos(CENTER);
	
	Draw2DPlane(temp);
	
}

void XEngineRenderer::Release() {
}

void XEngineRenderer::DrawLine(PARMLINE2D line_) {
	MoveToEx(mDC, line_.p0.x, line_.p0.y, NULL);
	LineTo(mDC, line_.p1.x, line_.p1.y);
}

void XEngineRenderer::DrawGizmos(AXIS Center) {
	
	PARMLINE2D horizontal, vertical;

	horizontal.p0 = { 0, mHeight / 2 };
	horizontal.p1 = { mWidth, mHeight / 2 };

	vertical.p0 = { mWidth / 2, 0 };
	vertical.p1 = { mWidth / 2 , mHeight };

	
	DrawLine(horizontal);
	DrawLine(vertical);
}


void XEngineRenderer::Draw2DPlane(PLANE2D plane_)
{
	PARMLINE2D E[3];
	int size = 25;

	E[0] = { {plane_.p0.x ,plane_.p0.y - size},{plane_.p0.x + size,plane_.p0.y + size} };
	E[1] = { {plane_.p0.x + size,plane_.p0.y + size},{plane_.p0.x - size,plane_.p0.y + size} };
	E[2] = { {plane_.p0.x - size,plane_.p0.y + size},{plane_.p0.x ,plane_.p0.y - size} };
	
	for (int i = 0; i < 3; i++) {
		DrawLine(E[i]);
	}
}

XEngineRenderer::XEngineRenderer()
{
}


XEngineRenderer::~XEngineRenderer()
{
}
