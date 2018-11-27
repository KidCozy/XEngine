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
// ??? 무슨 라인이요..? //
typedef struct PARMLINE2D_TYP {
	POINT2D p0;  // 시작점
	POINT2D p1; // 끝점
	VECTOR2D v; // 방향 벡터
} PARMLINE2D, *LPPARMLINE2D;

typedef struct PARMLINE3D_TYP {
	POINT3D p0; // 시작점
	POINT3D p1; // 끝점
	VECTOR3D v; // 방향 벡터
} PARMLINE3D, *LPPARMLINE3D;

// 3D Planes
typedef struct PLANE3D_TYP {
	POINT3D p0; // 평면체의 좌표
	VECTOR3D n; // 평면의 노멀 값 (꼭 벡터 단위일 필요는 없음)
} PLANE3D, *LPPLANE3D;


//------------------------------------------------------------//
typedef struct PLANE2D_TYP {
	POINT2D p0;
} PLANE2D, *LPPLANE2D;