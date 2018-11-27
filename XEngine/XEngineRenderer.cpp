#include "stdafx.h"
#include "XEngineRenderer.h"


void XEngineRenderer::Init(HWND hWnd, HDC DC) {
	mDC = DC;
	mHwnd = hWnd;
	temp.p0.x = 100;
	temp.p0.y = 100;
}

void XEngineRenderer::Render()
{
	Draw2DPlane(temp);
}

void XEngineRenderer::Draw2DPlane(PLANE2D plane_)
{
	MoveToEx(mDC, plane_.p0.x, plane_.p0.y, NULL);
	LineTo(mDC, plane_.p0.x + 25, plane_.p0.y + 25);
	MoveToEx(mDC, plane_.p0.x + 25, plane_.p0.y + 25, NULL);
	LineTo(mDC, plane_.p0.x, plane_.p0.y + 25);
	MoveToEx(mDC, plane_.p0.x, plane_.p0.y + 25, NULL);
	LineTo(mDC, plane_.p0.x, plane_.p0.y);
}

XEngineRenderer::XEngineRenderer()
{
}


XEngineRenderer::~XEngineRenderer()
{
}
