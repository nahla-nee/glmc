#ifndef GLMC_VECTOR4
#define GLMC_VECTOR4

#include "../defs.h"
#include "vector.h"

#define vec4_set1(x) vec_set1(x)
#define vec4_add(a, b) vec_add(a, b)
#define vec4_sub(a, b) vec_sub(a, b)
#define vec4_mul(a, b) vec_mul(a, b)
#define vec4_div(a, b) vec_div(a, b)
#define vec4_addScal(a, scalar) vec_addScal(a, scalar)
#define vec4_subScal(a, scalar) vec_subScal(a, scalar)
#define vec4_mulScal(a, scalar) vec_mulScal(a, scalar)
#define vec4_divScal(a, scalar) vec_divScal(a, scalar)
#define vec4_abs(a) vec_abs(a)
#define vec4_ceil(a) vec_ceil(a)
#define vec4_floor(a) vec_floor(a)
#define vec4_round(a) vec_round(a)

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <smmintrin.h>

bool vec4_equal(__m128 a, __m128 b);
bool vec4_equal_eps(__m128 a, __m128 b, float epsilon);
float vec4_len(__m128 a);
__m128 vec4_norm(__m128 a);
float vec4_dot(__m128 a, __m128 b);
__m128 vec4_set(float x, float y, float z, float w);
__m128 vec4_mulMat(__m128 a, mat4 b);

#ifdef __cplusplus
}
#endif

#endif
