#ifndef LIBGLMC_MAT2_PLAIN
#define LIBGLMC_MAT2_PLAIN

#include "matDefs.h"

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

mat2 mat2_set(float m0, float m1, float m2, float m3);
mat2 mat2_set1(float x);
mat2 mat2_add(mat2 a, mat2 b);
mat2 mat2_sub(mat2 a, mat2 b);
mat2 mat2_mul(mat2 a, mat2 b);
mat2 mat2_addScal(mat2 a, float scalar);
mat2 mat2_subScal(mat2 a, float scalar);
mat2 mat2_mulScal(mat2 a, float scalar);
mat2 mat2_divScal(mat2 a, float scalar);
mat2 mat2_identity(void);
mat2 mat2_translate(float x);
mat2 mat2_scale(float x);
mat2 mat2_transpose(mat2 a);
mat2 mat2_swapRow(mat2 a);
mat2 mat2_swapCol(mat2 a);


#ifdef __cplusplus
}
}
#endif

#endif
