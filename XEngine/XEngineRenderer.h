#pragma once

#include"XMath.h"

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
	HDC mDC;
	HWND mHwnd;
	queue<PLANE2D> renderQueue_;
	vector<PLANE2D> renderList_;
	PLANE2D temp;
	RECT mRect;

	int mWidth;
	int mHeight;

public:

	void SetParams();
	void Init(HDC DC);
	void Render();
	void Release();


	void RayFill(HWND hWnd, HDC mDC, COLORREF bgColor, POINT2D y);

	void DrawLine(PARMLINE2D line_);
	void Draw2DPlane(PLANE2D plane_);
	void DrawLineByBresenHam(POINT2D from, POINT2D to);
	void Draw2DTriangle(TRIANGLE2D tri_);
	void Draw2DSquare(SQUARE2D sqr_);

	void Translate(VECTOR3D offset_);
	void Translate(float x, float y, float z);


	void DrawGizmos(AXIS Center);
	void SwapChain();

	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }
	
	
	XEngineRenderer();
	XEngineRenderer(HWND hWnd);
	~XEngineRenderer();
};

