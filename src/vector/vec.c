#include "vector/vec.h"

__m128 vec_set1(float x){
	return _mm_set1_ps(x);
}

__m128 vec_add(__m128 a, __m128 b){
	return _mm_add_ps(a, b);
}

__m128 vec_sub(__m128 a, __m128 b){
	return _mm_sub_ps(a, b);
}

__m128 vec_mul(__m128 a, __m128 b){
	return _mm_mul_ps(a, b);
}

__m128 vec_div(__m128 a, __m128 b){
	return _mm_div_ps(a, b);
}

__m128 vec_addScal(__m128 a, float scalar){
	return _mm_add_ps(a, _mm_set1_ps(scalar));
}

__m128 vec_subScal(__m128 a, float scalar){
	return _mm_sub_ps(a, _mm_set1_ps(scalar));
}

__m128 vec_mulScal(__m128 a, float scalar){
	return _mm_mul_ps(a, _mm_set1_ps(scalar));
}

__m128 vec_divScal(__m128 a, float scalar){
	return _mm_div_ps(a, _mm_set1_ps(scalar));
}

__m128 vec_abs(__m128 a){
	return _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
}

__m128 vec_ceil(__m128 a){
	return _mm_ceil_ps(a);
}

__m128 vec_floor(__m128 a){
	return _mm_floor_ps(a);
}

__m128 vec_round(__m128 a){
	return _mm_round_ps(a, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}

