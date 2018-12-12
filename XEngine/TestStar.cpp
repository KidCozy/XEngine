#include "stdafx.h"
#include "TestStar.h"


TestStar::TestStar()
{
	mPos = VECTOR4D();
	for (int i = 0; i < 3; i++) {
		mPos.M[i] = rand() % 512;
	}

}
TestStar::~TestStar()
{
}

void TestStar::Render() {

}