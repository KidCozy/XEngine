#include "stdafx.h"
#include "XEngineRenderer.h"

#define DrawBH DrawLineByBresenHam(POINT2D from, POINT2D to);

using namespace align;

ULONG mCurrentColor;

void XEngineRenderer::SetParams() {
	temp.p0 = { mWidth/2,mHeight/2 };

}

void XEngineRenderer::Init(HWND hWnd) {
	SetParams();
	mDevice_.Init(hWnd);

	GetClientRect(hWnd, &mRect);

	mWidth = mRect.right;
	mHeight = mRect.bottom;
	mIsRender = TRUE;
}


// 렌더 구간
void XEngineRenderer::Render()
{
	mDevice_.SetColor(255, 0, 0);

	Clear();

	
	mDevice_.SwapChain();
}

void XEngineRenderer::Release(HWND hWnd)
{
	mDevice_.Release(hWnd);
	mDevice_.~X3DDevice();
	this->~XEngineRenderer();
}

void XEngineRenderer::PixelOut(int x, int y)
{
	if (!IsInArea(x, y)) return;

	ULONG* dest = (ULONG*)mScreenBits;
	DWORD offset = mWidth * mHeight / 2 + mWidth / 2 + x + mWidth * -y;
	*(dest + offset) = mCurrentColor;
}

void XEngineRenderer::Clear()
{
	/*int x = -mWidth / 2, y = -mHeight / 2;
	mDevice_.SetColor(255, 0, 0);
	for (int i = x; i < 256; i++) {
		for (int j = y; j < 256; j++) {
			PixelOut(i, j);
		}
	}*/
//	mDevice_.SetColor(255, 255, 255);
	ULONG* dest = (ULONG*)mScreenBits;
	DWORD area = (mWidth * mHeight) * sizeof(ULONG);

	ULONG value = mCurrentColor;

	area /= 4;

	while (area--) {
		*dest++ = value;
	}
	return;
}

VECTOR2D vertices[3] = {
	{25,25},
	{25,50},
	{50,25}
};

void XEngineRenderer::RayFill(VECTOR2D obj)
{
	int p = obj.y;

	
	
}

bool XEngineRenderer::IsInArea(int x, int y)
{
	
	return (abs(x) < (mWidth / 2)) && (abs(y) < mHeight / 2);
}

XEngineRenderer::XEngineRenderer()
{
}

XEngineRenderer::~XEngineRenderer()
{
}





//
//void XEngineRenderer::RayFill(HWND hWnd, HDC mDC, COLORREF bgColor, POINT2D axis) {
//
//	// bgColor = COLOR_BLACK;
//
//	int count = 0;
//
//	COLORREF borderColor;
//
//	borderColor = RGB(0, 0, 0);
//
//
//	
//}
//
//void XEngineRenderer::DrawLine(PARMLINE2D line_) {
//	MoveToEx(mDC, line_.p0.x, line_.p0.y, NULL);
//	LineTo(mDC, line_.p1.x, line_.p1.y);
//}
//
//void XEngineRenderer::DrawGizmos(AXIS Center) {
//	
//	PARMLINE2D horizontal, vertical;
//
//	horizontal.p0 = { 0, mHeight / 2 };
//	horizontal.p1 = { mWidth, mHeight / 2 };
//
//	vertical.p0 = { mWidth / 2, 0 };
//	vertical.p1 = { mWidth / 2 , mHeight };
//
//	
//	DrawLine(horizontal);
//	DrawLine(vertical);
//}
//
//void XEngineRenderer::DrawLineByBresenHam(POINT2D from, POINT2D to, COLORREF color) {
//
//	// 1. x와 y 각각의 변화량을 구한다.
//	int W = from.x - to.x;
//	int H = from.y - to.y;
//
//	int p = 2 * H - W;
//
//	while (from.x <= to.x) {
//		if (p > 0)
//		{
//			SetPixel(mDC, from.x, from.y, color);
//			from.y++;
//			p = p + 2 * H - 2 * W;
//		}
//		else
//		{
//			SetPixel(mDC, from.x, from.y,color);
//			from.y++;
//			p = p + 2 * H;
//		}
//		from.x++;
//	}
//		
//
//}
//
//void XEngineRenderer::Draw2DPlane(PLANE2D plane_)
//{
//	PARMLINE2D E[3];
//	int size = 25;
//
//	E[0] = { {plane_.p0.x ,plane_.p0.y - size},{plane_.p0.x + size,plane_.p0.y + size} };
//	E[1] = { {plane_.p0.x + size,plane_.p0.y + size},{plane_.p0.x - size,plane_.p0.y + size} };
//	E[2] = { {plane_.p0.x - size,plane_.p0.y + size},{plane_.p0.x ,plane_.p0.y - size} };
//	
//	for (int i = 0; i < 3; i++) {
//		DrawLine(E[i]);
//	}
//}
//
//
//void XEngineRenderer::Draw2DSquare(SQUARE2D sqr_) {
//	
//
//}
//
