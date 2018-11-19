#ifndef GLMC_VECTOR4_PLAIN
#define GLMC_VECTOR4_PLAIN

#include "defs_plain.h"

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include "matrix/matrix4_plain.h"

float vec4_equal(vec4 a, vec4 b);
float vec4_equal_eps(vec4 a, vec4 b, float epsilon);
float vec4_len(vec4 a);
vec4 vec4_norm(vec4 a);
vec4 vec4_set(float x, float y, float z, float w);
vec4 vec4_set1(float x);
vec4 vec4_add(vec4 a, vec4 b);
vec4 vec4_sub(vec4 a, vec4 b);
vec4 vec4_mul(vec4 a, vec4 b);
vec4 vec4_div(vec4 a, vec4 b);
vec4 vec4_addScal(vec4 a, float scalar);
vec4 vec4_subScal(vec4 a, float scalar);
vec4 vec4_mulScal(vec4 a, float scalar);
vec4 vec4_divScal(vec4 a, float scalar);
float vec4_dot(vec4 a, vec4 b);
vec4 vec4_abs(vec4 a);
vec4 vec4_ceil(vec4 a);
vec4 vec4_floor(vec4 a);
vec4 vec4_round(vec4 a);
vec4 vec4_mulMat(vec4 a, mat4 b);

#ifdef __cplusplus
}
#endif

#endif