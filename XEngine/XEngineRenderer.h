#pragma once
#include"XMath.h"
#include<queue>
#include<vector>

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

	LPPLANE2D pTemp;

	void SetParams();
	void Init(HWND hWnd, HDC mDC);
	void Render();
	void Release();


	void DrawLine(PARMLINE2D line_);
	void Draw2DPlane(PLANE2D plane_);
	
	void DrawGizmos(AXIS Center);
	XEngineRenderer();
	~XEngineRenderer();
};

