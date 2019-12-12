#include "vector/vec2.h"

__m128 vec2_set(float x, float y){
	return _mm_set_ps(0.f, 0.f, y, x);
}

bool vec2_equalEps(__m128 a, __m128 b, float epsilon){
	a = vec2_sub(a, b);
	a = vec2_abs(a);

	vec2 tmp = (vec2)vec2_set1(epsilon);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);

	if((int)tmp.x || (int)tmp.y){
		return false;
	}
	return true;
}

bool vec2_equal(__m128 a, __m128 b){
	return vec2_equalEps(a, b, FLT_EPSILON);
}

float vec2_len(__m128 a){
	vec2 tmp = (vec2)vec2_mul(a, a);
	return sqrtf(tmp.x+tmp.y);
}

__m128 vec2_norm(__m128 a){
	vec2 tmp = (vec2)vec2_mul(a, a);
	return _mm_div_ps(a, vec2_set1(sqrtf(tmp.x+tmp.y)));
}

float vec2_dot(__m128 a, __m128 b){
	vec2 tmp = (vec2)vec2_mul(a, b);
	return (tmp.x + tmp.y);
}

__m128 vec2_mulMat(__m128 a, mat2 b){
	vec2 vec = (vec2)a;
	__m128 res = vec2_mul(b.mat, vec2_set(vec.y, vec.y, vec.x, vec.x));
	return _mm_add_ps(res, _mm_movehl_ps(res, res));
}
