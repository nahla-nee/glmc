#include "quat.h"

bool quat_equal(__m128 a, __m128 b){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	quat tmp = GLMC_CAST(quat, _mm_set1_ps(FLT_EPSILON));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}
bool quat_equal_eps(__m128 a, __m128 b, float epsilon){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	quat tmp = GLMC_CAST(quat, _mm_set1_ps(epsilon));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.w || (int)tmp.x || (int)tmp.y || (int)tmp.z){
		return false;
	}
	return true;
}
float quat_len(__m128 a){
	quat tmp = GLMC_CAST(quat, _mm_mul_ps(a, a));
	return sqrtf(tmp.w+tmp.x+tmp.y+tmp.z);
}
__m128 quat_norm(__m128 a){
	quat tmp = GLMC_CAST(quat, _mm_mul_ps(a, a));
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.w+tmp.x+tmp.y+tmp.z)));
}
__m128 quat_set(float w, float x, float y, float z){
	return _mm_set_ps(z, y, x, w);
}
__m128 quat_mul(__m128 a, __m128 b){
}
