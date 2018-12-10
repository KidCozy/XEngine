#pragma once
#include"XMath.h"
class PrimeCamera
{
private:
	MATRIX mMat;
	

public:
	void TransformInMatrix();
	void Resterize();

	PrimeCamera();
	~PrimeCamera();
};

