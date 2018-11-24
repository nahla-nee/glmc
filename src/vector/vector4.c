#include "vector/vector4.h"

bool vec4_equal(__m128 a, __m128 b){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec4 tmp = (vec4)_mm_set1_ps(FLT_EPSILON);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}
bool vec4_equal_eps(__m128 a, __m128 b, float epsilon){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec4 tmp = (vec4)_mm_set1_ps(epsilon);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}
float vec4_len(__m128 a){
	vec4 tmp = (vec4)_mm_mul_ps(a, a);
	return sqrtf(tmp.x+tmp.y+tmp.z+tmp.w);
}
__m128 vec4_norm(__m128 a){
	vec4 tmp = (vec4)_mm_mul_ps(a, a);
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.x+tmp.y+tmp.z+tmp.w)));
}
float vec4_dot(__m128 a, __m128 b){
	vec4 tmp = (vec4)_mm_mul_ps(a, b);
	return (tmp.x+tmp.y+tmp.z+tmp.w);
}
__m128 vec4_set(float x, float y, float z, float w){
	return _mm_set_ps(w, z, y, x);
}
__m128 vec4_mulMat(__m128 a, mat4 b){
	vec4 tmp = (vec4)a;
	__m128 res = _mm_mul_ps(b.mat[0], _mm_set1_ps(tmp.x));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[1], _mm_set1_ps(tmp.y)));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[2], _mm_set1_ps(tmp.z)));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[3], _mm_set1_ps(tmp.w)));
	return res;
}
