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
		float m0, m1, m2, m3;
	};
} mat2;

typedef union mat3{
	float mat1d[9];
	float mat2d[3][3];
	struct{
		float m0, m1, m2, m3, m4, m5, m6, m7, m8;
	};
} mat3;

typedef union mat4{
	float mat1d[16];
	float mat2d[4][4];
	struct{
		float m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15;
	};
} mat4;

#ifdef __cplusplus
}
}
#endif

#endif
