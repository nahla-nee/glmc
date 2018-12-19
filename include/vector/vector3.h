#ifndef GLMC_VECTOR3
#define GLMC_VECTOR3

#include "../defs.h"
#include "vector.h"

#include <stdbool.h>
#include <math.h>
#include <float.h>

#define vec3_set1(x) vec_set1(x)
#define vec3_add(a, b) vec_add(a, b)
#define vec3_sub(a, b) vec_sub(a, b)
#define vec3_mul(a, b) vec_mul(a, b)
#define vec3_div(a, b) vec_div(a, b)
#define vec3_addScal(a, scalar) vec_addScal(a, scalar)
#define vec3_subScal(a, scalar) vec_subScal(a, scalar)
#define vec3_mulScal(a, scalar) vec_mulScal(a, scalar)
#define vec3_divScal(a, scalar) vec_divScal(a, scalar)
#define vec3_abs(a) vec_abs(a)
#define vec3_ceil(a) vec_ceil(a)
#define vec3_floor(a) vec_floor(a)
#define vec3_round(a) vec_round(a)

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

bool vec3_equal(__m128 a, __m128 b);
bool vec3_equal_eps(__m128 a, __m128 b, float epsilon);
float vec3_len(__m128 a);
__m128 vec3_norm(__m128 a);
float vec3_dot(__m128 a, __m128 b);
__m128 vec3_cross(__m128 a, __m128 b);
__m128 vec3_set(float x, float y, float z);
__m128 vec3_mulMat(__m128 a, mat3 b);

#ifdef __cplusplus
}
}
#endif

#endif
