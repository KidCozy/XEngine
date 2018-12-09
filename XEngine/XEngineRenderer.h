#pragma once
#include"X3DDevice.h"
#include"XMath.h"
#include"PrimeEngine.h"
#include<queue>
#include<vector>
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

	queue<PLANE2D> renderQueue_;
	vector<PLANE2D> renderList_;
	
	RECT mRect;

public:

	void SetParams();
	void Init(HWND hWnd);
	void Render();
	void Release(HWND hWnd);

	//Primitive
	void SetColor(BYTE R, BYTE G, BYTE B);
	
	void PixelOut(int x, int y);

	void RayFill(HWND hWnd, HDC mDC, COLORREF bgColor, POINT2D y);

	void DrawLine(PARMLINE2D line_);
	void Draw2DPlane(PLANE2D plane_);
	void DrawLineByBresenHam(POINT2D from, POINT2D to, COLORREF color);

	void Draw2DSquare(SQUARE2D sqr_);

	void Translate(VECTOR3D offset_);
	void Translate(float x, float y, float z);

	

	void DrawGizmos(AXIS Center);
	void SwapChain();


	bool IsInArea(int x, int y);

	XEngineRenderer();
	XEngineRenderer(HWND hWnd);
	~XEngineRenderer();


// ��Ÿ ����׿� ���� ����
private:
	PLANE2D temp;

};

