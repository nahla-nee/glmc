#ifndef GLMC_VECTOR2
#define GLMC_VECTOR2

#include "../defs.h"
#include "vector.h"

#define vec2_set1(x) vec_set1(x)
#define vec2_add(a, b) vec_add(a, b)
#define vec2_sub(a, b) vec_sub(__m128 a, __m128 b)
#define vec2_mul(a, b) vec_mul(__m128 a, __m128 b)
#define vec2_div(a, b) vec_div(__m128 a, __m128 b)
#define vec2_addScal(a, scalar) vec_addScal(__m128 a, float scalar)
#define vec2_subScal(a, scalar) vec_subScal(__m128 a, float scalar)
#define vec2_mulScal(a, scalar) vec_mulScal(__m128 a, float scalar)
#define vec2_divScal(a, scalar) vec_divScal(__m128 a, float scalar)
#define vec2_abs(a) vec_abs(__m128 a)
#define vec2_ceil(a) vec_ceil(__m128 a)
#define vec2_floor(a) vec_floor(__m128 a)
#define vec2_round(a) vec_round(__m128 a)

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <smmintrin.h>
#include "../matrix/matrix2.h"

bool vec2_equal(__m128 a, __m128 b);
bool vec2_equal_eps(__m128 a, __m128 b, float epsilon);
float vec2_len(__m128 a);
__m128 vec2_norm(__m128 a);
float vec2_dot(__m128 a, __m128 b);
__m128 vec2_set(float x, float y);
__m128 vec2_mulMat(__m128 a, mat2 b);

#ifdef __cplusplus
}
#endif

#endif
