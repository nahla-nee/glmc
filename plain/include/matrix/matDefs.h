#ifndef LIBGLMC_MATDEFS_PLAIN
#define LIBGLMC_MATDEFS_PLAIN

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

typedef union mat2{
	float mat1d[4];
	float mat2d[2][2];
	struct{
		float m11, m12, m21, m22;
	};
} mat2;

typedef union mat3{
	float mat1d[9];
	float mat2d[3][3];
	struct{
		float m11, m12, m13, m21, m22, m23, m31, m32, m33;
	};
} mat3;

typedef union mat4{
	float mat1d[16];
	float mat2d[4][4];
	struct{
		float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
	};
} mat4;

#ifdef __cplusplus
}
}
#endif

#endif
