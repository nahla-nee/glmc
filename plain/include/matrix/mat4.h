#ifndef LIBGLMC_MAT4_PLAIN
#define LIBGLMC_MAT4_PLAIN

#include "matDefs.h"

#include "vector/vecDefs.h"
#include "vector/vec3.h"

#include <math.h>

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

mat4 mat4_set(float m0, float m1, float m2, float m3, float m4, float m5,
	float m6, float m7, float m8, float m9, float m10, float m11, float m12,
	float m13, float m14, float m15);
mat4 mat4_set1(float x);

mat4 mat4_add(mat4 a, mat4 b);
mat4 mat4_sub(mat4 a, mat4 b);
mat4 mat4_mul(mat4 a, mat4 b);

mat4 mat4_addScal(mat4 a, float scalar);
mat4 mat4_subScal(mat4 a, float scalar);
mat4 mat4_mulScal(mat4 a, float scalar);
mat4 mat4_divScal(mat4 a, float scalar);

mat4 mat4_identity(void);

mat4 mat4_translate(float x, float y, float z);
mat4 mat4_scale(float x, float y, float z);

mat4 mat4_transScale1(float x, float y, float z, float scale);
mat4 mat4_transScale(float x, float y, float z, float xscale, float yscale, float zscale);

mat4 mat4_perspective(float fov, float aspect, float near, float far);
mat4 mat4_ortho(float left, float right, float top, float bottom, float near, float far);
mat4 mat4_lookAt(vec3 position, vec3 target, vec3 up);
mat4 mat4_lookAtFast(vec3 position, vec3 forward, vec3 up, vec3 right);

mat4 mat4_transpose(mat4 a);
mat4 mat4_swapRow(mat4 a, int R1, int R2);
mat4 mat4_swapCol(mat4 a, int C1, int C2);

#ifdef __cplusplus
}
}
#endif

#endif
