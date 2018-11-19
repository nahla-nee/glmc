#include "vector/vector3.h"

bool vec3_equal(__m128 a, __m128 b){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec3 tmp = GLMC_CAST(vec3, _mm_set1_ps(FLT_EPSILON));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z){
		return false;
	}
	return true;
}
bool vec3_equal_eps(__m128 a, __m128 b, float epsilon){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec3 tmp = GLMC_CAST(vec3, _mm_set1_ps(epsilon));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z){
		return false;
	}
	return true;
}
float vec3_len(__m128 a){
	vec3 tmp = GLMC_CAST(vec3, _mm_mul_ps(a, a));
	return sqrtf(tmp.x+tmp.y+tmp.z);
}
__m128 vec3_norm(__m128 a){
	vec3 tmp = GLMC_CAST(vec3, _mm_mul_ps(a, a));
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.x+tmp.y+tmp.z)));
}
float vec3_dot(__m128 a, __m128 b){
	vec3 tmp = GLMC_CAST(vec3, _mm_mul_ps(a, b));
	return (tmp.x+tmp.y+tmp.z);
}
__m128 vec3_set(float x, float y, float z){
	return _mm_set_ps(0.f, z, y, x);
}
__m128 vec3_mulMat(__m128 a, mat3 b){
	vec3 tmp = GLMC_CAST(vec3, a);
	__m128 res = _mm_mul_ps(b.mat[0], _mm_set1_ps(tmp.x));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[1], _mm_set1_ps(tmp.y)));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[2], _mm_set1_ps(tmp.z)));
	return res;
}
