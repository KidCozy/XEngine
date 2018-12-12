#pragma once
#include"X3DDevice.h"
#include"XMath.h"
#include"PrimeCamera.h"
#include"PrimeEngine.h"
#include"TestStar.h"
#include<Windows.h>

using namespace std;


namespace align {
	enum AXIS {
		CENTER,
		LEFT,
		RIGHT,
		TOP,
		BOTTOM,
	};
}

using namespace align;

class XEngineRenderer
{

private:

	X3DDevice mDevice_;
	
	RECT mRect;

public:

	void SetParams();
	void Init(HWND hWnd);
	void Render();
	void Release(HWND hWnd);

	//Primitive
	void SetColor(BYTE R, BYTE G, BYTE B);
	
	void PixelOut(int x, int y);
	void Clear();

	void RayFill();

	void DrawStar(TestStar* star);

	
	void Line(VECTOR2D start, VECTOR2D dest);
	bool DrawLine(VECTOR2D start, VECTOR2D dest);
	void LineDraw(VECTOR2D start, VECTOR2D dest);
	void Draw2DPlane(PLANE2D plane_);
	void DrawLineByBresenHam(POINT2D from, POINT2D to, COLORREF color);

	void ShowPoints(VECTOR2D pnt) {

		wchar_t wszText[512] = { 0 };
		swprintf(wszText, 512, L"(%d, %d)", pnt.x, pnt.y);
		::TextOut(mDevice_.PeekDC(), pnt.x+(mWidth/2), (-pnt.y+(mHeight/2)), wszText, wcslen(wszText));
	}

	void ShowCurrentPoints(VECTOR2D pnt, int offset, const wchar_t* descrpt) {
		wchar_t wszText[512] = { 0 };
		swprintf(wszText, 512, L"%s : (%d, %d)", descrpt ,pnt.x, pnt.y);
		::TextOut(mDevice_.PeekDC(), 0, 0+offset, wszText, wcslen(wszText));
	}


	void Draw2DSquare(SQUARE2D sqr_);

	void Translate(VECTOR3D offset_);
	void Translate(float x, float y, float z);

	

	void DrawGizmos(AXIS Center);
	

	bool IsInArea(int x, int y);

	XEngineRenderer();
	XEngineRenderer(HWND hWnd);
	~XEngineRenderer();


// ��Ÿ ����׿� ���� ����
private:
	PLANE2D temp;

};

