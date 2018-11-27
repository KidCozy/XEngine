#pragma once

typedef struct VECTOR2D_TYP {
	union {
		float M[2];
		struct {
			float x;
			float y;
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


//------------------------------------------------------------//
typedef struct PLANE2D_TYP {
	POINT2D p0;
} PLANE2D, *LPPLANE2D;