#pragma once

#include<iostream>
//-----------------------------���----------------------------//


//
//typedef struct TRIANGLE2D {
//	union {
//		VECTOR2D M[3];
//		struct {
//			VECTOR2D p0, p1, p2;
//		};
//	};
//};

typedef struct SQUARE2D_TYP {
	union {
		int M[4];
		struct {
			int p0, p2, p3, p4;
		};
	};
}SQUARE2D;

//-------------------------������ �����ε�---------------------//



//------------------------------------------------------------//

typedef struct VECTOR2D_TYP {
	union {
		int M[2];
		struct {
			int x;
			int y;
		};
	};
} VECTOR2D, POINT2D, *LPVECTOR2D, *LPPOINT2D;

typedef struct VECTOR3D_TYP {
	union {
		float M[3];
		struct {
			float x, y, z;
		};
	};
} VECTOR3D, POINT3D, *LPVECTOR3D, *LPPOINT3D;

typedef struct VECTOR4D_TYP {
	union {
		float M[4];
		struct {
			float x, y, z, w;
		};
	};
} VECTOR4D, POINT4D, *LPVECTOR4D, *LPPOINT4D;

// Parametric Line //
// ??? ���� �����̿�..? //
typedef struct PARMLINE2D_TYP {
	POINT2D p0;  // ������
	POINT2D p1; // ����
	VECTOR2D v; // ���� ����
} PARMLINE2D, *LPPARMLINE2D;

typedef struct PARMLINE3D_TYP {
	POINT3D p0; // ������
	POINT3D p1; // ����
	VECTOR3D v; // ���� ����
} PARMLINE3D, *LPPARMLINE3D;

// 3D Planes
typedef struct PLANE3D_TYP {
	POINT3D p0; // ���ü�� ��ǥ
	VECTOR3D n; // ����� ��� �� (�� ���� ������ �ʿ�� ����)
} PLANE3D, *LPPLANE3D;

typedef struct PLANE2D_TYP {
	POINT2D p0;
} PLANE2D, *LPPLANE2D;

//------------------------------------------------------------//

typedef struct MATRIX_TYP {
	union {
		float M[16];
		struct {
			float M11_, M12_, M13_, M14_;
			float M21_, M22_, M23_, M24_;
			float M31_, M32_, M33_, M34_;
			float M41_, M42_, M43_, M44_;
		};
	};
} MATRIX, *LPMATRIX, TRANSFORM, *LPTRANSFORM;

//------------------------------------------------------------//
// ��� ��ȯ �Լ�
MATRIX LocalToWorldMatrix(MATRIX local_);

//------------------------------------------------------------//
// ��� ��ȯ �Լ�
void Translate(LPTRANSFORM, VECTOR3D);
void Translate(float, float, float);

//------------------------------------------------------------//
// ��� ���� 

void DrawMatrix(MATRIX mat);