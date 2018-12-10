#pragma once
#include"X3DDevice.h"
#include"XMath.h"
#include"PrimeEngine.h"
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

	void RayFill(VECTOR2D obj);

	void DrawLine(PARMLINE2D line_);
	void Draw2DPlane(PLANE2D plane_);
	void DrawLineByBresenHam(POINT2D from, POINT2D to, COLORREF color);

	void Draw2DSquare(SQUARE2D sqr_);

	void Translate(VECTOR3D offset_);
	void Translate(float x, float y, float z);

	

	void DrawGizmos(AXIS Center);


	bool IsInArea(int x, int y);

	XEngineRenderer();
	XEngineRenderer(HWND hWnd);
	~XEngineRenderer();


// 기타 디버그용 도형 선언
private:
	PLANE2D temp;

};

