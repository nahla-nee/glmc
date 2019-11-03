#ifndef LIBGLMC_VEC2_SIMD
#define LIBGLMC_VEC2_SIMD

#include "vecDefs.h"
#include "vec.h"
#include "matrix/matDefs.h"

#include <stdbool.h>
#include <math.h>
#include <float.h>

#define vec2_set1(x) vec_set1(x)
#define vec2_add(a, b) vec_add(a, b)
#define vec2_sub(a, b) vec_sub(a, b)
#define vec2_mul(a, b) vec_mul(a, b)
#define vec2_div(a, b) vec_div(a, b)
#define vec2_addScal(a, scalar) vec_addScal(a, scalar)
#define vec2_subScal(a, scalar) vec_subScal(a, scalar)
#define vec2_mulScal(a, scalar) vec_mulScal(a, scalar)
#define vec2_divScal(a, scalar) vec_divScal(a, scalar)
#define vec2_abs(a) vec_abs(a)
#define vec2_ceil(a) vec_ceil(a)
#define vec2_floor(a) vec_floor(a)
#define vec2_round(a) vec_round(a)

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

bool vec2_equal(__m128 a, __m128 b);
bool vec2_equal_eps(__m128 a, __m128 b, float epsilon);
float vec2_len(__m128 a);
__m128 vec2_norm(__m128 a);
float vec2_dot(__m128 a, __m128 b);
__m128 vec2_set(float x, float y);
__m128 vec2_mulMat(__m128 a, mat2 b);

#ifdef __cplusplus
}
}
#endif

#endif
