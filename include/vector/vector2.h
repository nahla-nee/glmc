#ifndef GLMC_VECTOR2
#define GLMC_VECTOR2

#include "../defs.h"

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <smmintrin.h>
#include "matrix/matrix2.h"

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
