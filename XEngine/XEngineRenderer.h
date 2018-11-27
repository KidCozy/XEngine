#pragma once
#include"XMath.h"
#include<queue>
#include<vector>

using namespace std;


class XEngineRenderer
{

private:
	HDC mDC;
	HWND mHwnd;
	queue<PLANE2D> renderQueue_;
	vector<PLANE2D> renderList_;
	PLANE2D temp;
public:
	void Init(HWND hWnd, HDC mDC);
	void Render();
	void Release();

	void Draw2DPlane(PLANE2D plane_);

	XEngineRenderer();
	~XEngineRenderer();
};

