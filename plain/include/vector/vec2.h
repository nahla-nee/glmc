#ifndef LIBGLMC_VEC2_PLAIN
#define LIBGLMC_VEC2_PLAIN

#include "vecDefs.h"
#include "matrix/matDefs.h"

#include <stdbool.h>
#include <math.h>
#include <float.h>

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

float vec2_equal(vec2 a, vec2 b);
float vec2_equal_eps(vec2 a, vec2 b, float epsilon);
float vec2_len(vec2 a);
vec2 vec2_norm(vec2 a);
vec2 vec2_set(float x, float y);
vec2 vec2_set1(float x);
vec2 vec2_add(vec2 a, vec2 b);
vec2 vec2_sub(vec2 a, vec2 b);
vec2 vec2_mul(vec2 a, vec2 b);
vec2 vec2_div(vec2 a, vec2 b);
vec2 vec2_addScal(vec2 a, float scalar);
vec2 vec2_subScal(vec2 a, float scalar);
vec2 vec2_mulScal(vec2 a, float scalar);
vec2 vec2_divScal(vec2 a, float scalar);
float vec2_dot(vec2 a, vec2 b);
vec2 vec2_abs(vec2 a);
vec2 vec2_ceil(vec2 a);
vec2 vec2_floor(vec2 a);
vec2 vec2_round(vec2 a);
vec2 vec2_mulMat(vec2 a, mat2 b);

#ifdef __cplusplus
}
}
#endif

#endif
