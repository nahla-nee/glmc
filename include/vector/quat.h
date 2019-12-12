#ifndef LIBGLMC_QUAT_SIMD
#define LIBGLMC_QUAT_SIMD

#include "vecDefs.h"
#include "vec.h"
#include "matrix/matDefs.h"

#include <stdbool.h>
#include <math.h>
#include <float.h>

#define quat_set1(x) vec_set1(x)
#define quat_add(a, b) vec_add(a, b)
#define quat_sub(a, b) vec_sub(__m128 a, __m128 b)
#define quat_addScal(a, scalar) vec_addScal(__m128 a, float scalar)
#define quat_subScal(a, scalar) vec_subScal(__m128 a, float scalar)
#define quat_mulScal(a, scalar) vec_mulScal(__m128 a, float scalar)
#define quat_divScal(a, scalar) vec_divScal(__m128 a, float scalar)
#define quat_abs(a) vec_abs(__m128 a)
#define quat_ceil(a) vec_ceil(__m128 a)
#define quat_floor(a) vec_floor(__m128 a)
#define quat_round(a) vec_round(__m128 a)

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

__m128 quat_set(float x, float y, float z, float w);
bool quat_equal(__m128 a, __m128 b);
bool quat_equal_eps(__m128 a, __m128 b, float epsilon);
float quat_len(__m128 a);
__m128 quat_norm(__m128 a);
__m128 quat_conj(__m128 a);
__m128 quat_inv(__m128 a);
__m128 quat_mul(__m128 a, __m128 b);
__m128 quat_mulReal(__m128 a, __m128 b);
__m128 quat_mulPure(__m128 a, __m128 b);
__m128 quat_div(__m128 a, __m128 b);
__m128 quat_rotation(float angle, float x, float y, float z);
mat4 quat_toMat(__m128 a);

#ifdef __cplusplus
}
}
#endif

#endif
