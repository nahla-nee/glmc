#ifndef GLMC_DEFS
#define GLMC_DEFS

#include <smmintrin.h>

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif


typedef union vec2{
	__m128 vec;
	struct{
		float x, y;
	};
} vec2;

typedef union vec3{
	__m128 vec;
	struct{
		float x, y, z;
	};
	struct{
		float r, g, b;
	};
} vec3;

typedef union vec4{
	__m128 vec;
	struct{
		float x, y, z, w;
	};
	struct{
		float r, g, b, a;
	};
} vec4;

typedef union quat{
	__m128 vec;
	struct{
		float x, y, z, w;
	};
} quat;

typedef union mat2{
	__m128 mat;
	float mat2d[2][2];
	float mat1d[4];
	struct{
		float m0, m1, m2, m3;
	};
} mat2;

//no need for using another sse, its just as fast to use a float
typedef union mat3{
	__m128 mat[2];
	float mat2d[3][3];
	float mat1d[9];
	struct{
		float m0, m1, m2, m3, m4, m5, m6, m7, m8;
	};
} mat3;

typedef union mat4{
	__m128 mat[4];
	float mat2d[4][4];
	float mat1d[16];
	struct{
		float m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15;
	};
} mat4;

#ifdef __cplusplus
}
}
#endif

#endif
