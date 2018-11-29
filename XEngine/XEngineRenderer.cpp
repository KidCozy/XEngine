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

	//RayFill(mHwnd, mDC, RGB(255, 255, 255));
	
}

void XEngineRenderer::Release() {
}

void XEngineRenderer::RayFill(HWND hWnd, HDC mDC, COLORREF bgColor, VECTOR2D top, VECTOR2D bottom) {

	// bgColor = COLOR_BLACK;

	int count = 0;

	COLORREF ref, borderColor;

	borderColor = RGB(0, 0, 0);
			//cout << ref << endl;
	for (int i = 0; i < mWidth; i++) {
		ref = GetPixel(mDC, i, mHeight / 2);
		if (ref == borderColor)
		{
			count++;
			break;
		}
	}

	while (count % 2 != 0) {

	}

	//for(int j = top.x)
			//ref = GetPixel(mDC, i, j);
			//if (count % 2 != 0 && count != 0)
			//{
			//	if (ref == bgColor) { // isEmpty
			//		SetPixel(mDC, i, j, RGB(0, 0, 0));
			//	}

			//}
			//
			//else {
			//	if(ref == borderColor)
			//		count++;
			//}
	
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
