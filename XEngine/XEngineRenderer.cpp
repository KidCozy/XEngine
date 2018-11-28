#include "stdafx.h"
#include "XEngineRenderer.h"

using namespace align;

void XEngineRenderer::Init(HWND hWnd, HDC DC) {
	mDC = DC;
	mHwnd = hWnd;
	temp.p0.x = 500;
	temp.p0.y = 500;

	GetClientRect(hWnd, &mRect);

	mWidth = mRect.right;
	mHeight = mRect.bottom;
}



void XEngineRenderer::Render()
{
	DrawGizmos(CENTER);

	Draw2DPlane(temp, { 600,600 });
	
}

void XEngineRenderer::Release()
{
}

void XEngineRenderer::DrawLine(PARMLINE2D line_) {
	MoveToEx(mDC, line_.p0.x, line_.p0.y, NULL);
	LineTo(mDC, line_.p1.x, line_.p1.y);
}

void XEngineRenderer::DrawGizmos(AXIS Center) {
	
	PARMLINE2D horizontal, vertical;
	PARMLINE2D temp;

	temp.p0 = { 0,0 };
	temp.p1 = { mWidth,mHeight };


	horizontal.p0 = { 0, mHeight / 2 };
	horizontal.p1 = { mWidth, mHeight / 2 };

	vertical.p0 = { mWidth / 2, 0 };
	vertical.p1 = { mWidth / 2 , mHeight };

	DrawLine(temp);
	DrawLine(horizontal);
	DrawLine(vertical);
}


void XEngineRenderer::Draw2DPlane(PLANE2D plane_, VECTOR2D pos)
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
