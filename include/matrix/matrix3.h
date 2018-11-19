#ifndef GLMC_MATRIX3
#define GLMC_MATRIX3

#include "../defs.h"

#ifdef __cplusplus
extern "C"{
#endif

mat3 mat3_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
mat3 mat3_set1(float x);
mat3 mat3_add(mat3 a, mat3 b);
mat3 mat3_sub(mat3 a, mat3 b);
mat3 mat3_mul(mat3 a, mat3 b);
mat3 mat3_addScal(mat3 a, float scalar);
mat3 mat3_subScal(mat3 a, float scalar);
mat3 mat3_mulScal(mat3 a, float scalar);
mat3 mat3_divScal(mat3 a, float scalar);
mat3 mat3_identity(void);
mat3 mat3_translate(float x, float y);
mat3 mat3_scale(float x, float y);
mat3 mat3_transpose(mat3 a);
mat3 mat3_swapRow(mat3 a, int R1, int R2);
mat3 mat3_swapCol(mat3 a, int C1, int C2);

#ifdef __cplusplus
}
#endif

#endif
