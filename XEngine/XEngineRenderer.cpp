#include "stdafx.h"
#include "XEngineRenderer.h"

#define DrawBH DrawLineByBresenHam(POINT2D from, POINT2D to);

using namespace align;

ULONG mCurrentColor;

void XEngineRenderer::SetParams() {
	temp.p0 = { mWidth/2,mHeight/2 };

	// 삼각형 버텍스 정의
	//tri_.M[0] = { 100,100 };
	//tri_.M[1] = { 100,150 };
	//tri_.M[2] = { 150,150 };
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
	mDevice_.SetColor(255, 255, 255);

	for (int i = -mWidth; i < mWidth; i++) {
		PixelOut(i, 0);
		PixelOut(0, i);
	}
	
	
	mDevice_.SwapChain();
}

void XEngineRenderer::Release(HWND hWnd)
{
	mDevice_.Release(hWnd);
	this->~XEngineRenderer();
}

void XEngineRenderer::PixelOut(int x, int y)
{
	if (!IsInArea(x, y)) return;

	ULONG* dest = (ULONG*)mScreenBits;
	DWORD offset = mWidth * mHeight / 2 + mWidth / 2 + x + mWidth * -y;
	*(dest + offset) = mCurrentColor;
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
