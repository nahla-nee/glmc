#ifndef GLMC_VECTOR3
#define GLMC_VECTOR3

#include "../defs.h"

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
