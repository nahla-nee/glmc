#ifndef GLMC_VECTOR3_PLAIN
#define GLMC_VECTOR3_PLAIN

#include "../defs_plain.h"

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>

float vec3_equal(vec3 a, vec3 b);
float vec3_equal_eps(vec3 a, vec3 b, float epsilon);
float vec3_len(vec3 a);
vec3 vec3_norm(vec3 a);
vec3 vec3_set(float x, float y, float z);
vec3 vec3_set1(float x);
vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_sub(vec3 a, vec3 b);
vec3 vec3_mul(vec3 a, vec3 b);
vec3 vec3_div(vec3 a, vec3 b);
vec3 vec3_addScal(vec3 a, float scalar);
vec3 vec3_subScal(vec3 a, float scalar);
vec3 vec3_mulScal(vec3 a, float scalar);
vec3 vec3_divScal(vec3 a, float scalar);
float vec3_dot(vec3 a, vec3 b);
vec3 vec3_abs(vec3 a);
vec3 vec3_ceil(vec3 a);
vec3 vec3_floor(vec3 a);
vec3 vec3_round(vec3 a);
vec3 vec3_mulMat(vec3 a, mat3 b);

#ifdef __cplusplus
}
#endif

#endif
