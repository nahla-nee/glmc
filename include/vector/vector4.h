#ifndef GLMC_VECTOR4
#define GLMC_VECTOR4

#include "defs.h"

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <smmintrin.h>
#include "matrix/matrix4.h"

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
