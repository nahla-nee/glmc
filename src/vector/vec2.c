#include "vector/vec2.h"

bool vec2_equal(__m128 a, __m128 b){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec2 tmp = (vec2)_mm_set1_ps(FLT_EPSILON);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y){
		return false;
	}
	return true;
}
bool vec2_equal_eps(__m128 a, __m128 b, float epsilon){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec2 tmp = (vec2)_mm_set1_ps(epsilon);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y){
		return false;
	}
	return true;
}
float vec2_len(__m128 a){
	vec2 tmp = (vec2)_mm_mul_ps(a, a);
	return sqrtf(tmp.x+tmp.y);
}
__m128 vec2_norm(__m128 a){
	vec2 tmp = (vec2)_mm_mul_ps(a, a);
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.x+tmp.y)));
}
float vec2_dot(__m128 a, __m128 b){
	vec2 tmp = (vec2)_mm_mul_ps(a, b);
	return (tmp.x + tmp.y);
}
__m128 vec2_set(float x, float y){
	return _mm_set_ps(0.f, 0.f, y, x);
}
__m128 vec2_mulMat(__m128 a, mat2 b){
	vec2 vec = (vec2)a;
	__m128 res = _mm_mul_ps(b.mat, _mm_set_ps(vec.y, vec.y, vec.x, vec.x));
	return _mm_add_ps(res, _mm_movehl_ps(res, res));
}
