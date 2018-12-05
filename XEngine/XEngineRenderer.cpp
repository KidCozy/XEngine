#include "stdafx.h"
#include "XEngineRenderer.h"

using namespace align;

void XEngineRenderer::SetParams() {
	temp.p0 = { mWidth/2,mHeight/2 };
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
	//DrawGizmos(CENTER);
	
	Draw2DPlane({ mWidth / 2,mHeight / 2 });

	RayFill(mHwnd, mDC, RGB(255, 255, 255), { mWidth / 2,mHeight / 2 });
	
}

void XEngineRenderer::Release() {
}

void XEngineRenderer::RayFill(HWND hWnd, HDC mDC, COLORREF bgColor, POINT2D axis) {

	// bgColor = COLOR_BLACK;

	int count = 0;

	COLORREF ref, borderColor;

	borderColor = RGB(0, 0, 0);


	
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


void XEngineRenderer::DrawLineByBresenHam(POINT2D from, POINT2D to) {

	// 1. x와 y 각각의 변화량을 구한다.
	int W = abs(from.x - to.x);
	int H = abs(from.y - to.y);

	int b = 0;

	int yF = H / W + b;
	int xF = 0;

	b = to.y - (H / W)*to.x;

	yF = ((H / W) * xF) + to.y - (H / W)*to.x;

		

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

void XEngineRenderer::Draw2DTriangle(TRIANGLE2D tri_) {
	


}

void XEngineRenderer::Draw2DSquare(SQUARE2D sqr_) {
	

}

XEngineRenderer::XEngineRenderer()
{
}


XEngineRenderer::~XEngineRenderer()
{
}
