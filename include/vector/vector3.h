#ifndef GLMC_VECTOR3
#define GLMC_VECTOR3

#include "../defs.h"
#include "vector.h"

#define vec3_set1(x) vec_set1(x)
#define vec3_add(a, b) vec_add(a, b)
#define vec3_sub(a, b) vec_sub(__m128 a, __m128 b)
#define vec3_mul(a, b) vec_mul(__m128 a, __m128 b)
#define vec3_div(a, b) vec_div(__m128 a, __m128 b)
#define vec3_addScal(a, scalar) vec_addScal(__m128 a, float scalar)
#define vec3_subScal(a, scalar) vec_subScal(__m128 a, float scalar)
#define vec3_mulScal(a, scalar) vec_mulScal(__m128 a, float scalar)
#define vec3_divScal(a, scalar) vec_divScal(__m128 a, float scalar)
#define vec3_abs(a) vec_abs(__m128 a)
#define vec3_ceil(a) vec_ceil(__m128 a)
#define vec3_floor(a) vec_floor(__m128 a)
#define vec3_round(a) vec_round(__m128 a)

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <smmintrin.h>
#include "../matrix/matrix3.h"

bool vec3_equal(__m128 a, __m128 b);
bool vec3_equal_eps(__m128 a, __m128 b, float epsilon);
float vec3_len(__m128 a);
__m128 vec3_norm(__m128 a);
float vec3_dot(__m128 a, __m128 b);
__m128 vec3_set(float x, float y, float z);
__m128 vec3_mulMat(__m128 a, mat3 b);

#ifdef __cplusplus
}
#endif

#endif
