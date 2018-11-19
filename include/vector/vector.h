#ifndef GLMC_VECTOR
#define GLMC_VECTOR

#ifdef __cplusplus
extern "C"{
#endif

#include <smmintrin.h>

__m128 vec_set1(float x);
__m128 vec_add(__m128 a, __m128 b);
__m128 vec_sub(__m128 a, __m128 b);
__m128 vec_mul(__m128 a, __m128 b);
__m128 vec_div(__m128 a, __m128 b);
__m128 vec_addScal(__m128 a, float scalar);
__m128 vec_subScal(__m128 a, float scalar);
__m128 vec_mulScal(__m128 a, float scalar);
__m128 vec_divScal(__m128 a, float scalar);
__m128 vec_abs(__m128 a);
__m128 vec_ceil(__m128 a);
__m128 vec_floor(__m128 a);
__m128 vec_round(__m128 a);

#ifdef __cplusplus
}
#endif

#endif
