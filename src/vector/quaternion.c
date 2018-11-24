#include "vector/quaternion.h"

bool quat_equal(__m128 a, __m128 b){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	quat tmp = (quat)_mm_set1_ps(FLT_EPSILON);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}
bool quat_equal_eps(__m128 a, __m128 b, float epsilon){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	quat tmp = (quat)_mm_set1_ps(epsilon);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.w || (int)tmp.x || (int)tmp.y || (int)tmp.z){
		return false;
	}
	return true;
}
float quat_len(__m128 a){
	quat tmp = (quat)_mm_mul_ps(a, a);
	return sqrtf(tmp.w+tmp.x+tmp.y+tmp.z);
}
__m128 quat_norm(__m128 a){
	quat tmp = (quat)_mm_mul_ps(a, a);
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.w+tmp.x+tmp.y+tmp.z)));
}
__m128 quat_set(float w, float x, float y, float z){
	return _mm_set_ps(z, y, x, w);
}
__m128 quat_mul(__m128 a, __m128 b){
	//vector component of the result
	quat scalar = (quat)_mm_mul_ps(a, b);

	//multiply the b vector by the a scalar and the a vector by the b scalar and add the two resulting vectors
	//the w component of this result is ignored
	quat res = (quat)_mm_add_ps(_mm_mul_ps(_mm_set1_ps(((quat)a).w), b), _mm_mul_ps(_mm_set1_ps(((quat)b).w), a));

	//cross multiplication
	//construct left hand side of vector equation
	//using x as the last component allows this to be done using a single shufps
	__m128 lhs = {((quat)a).x, ((quat)a).y, ((quat)a).z, ((quat)a).x};
	__m128 tmp = {((quat)b).x, ((quat)b).z, ((quat)b).x, ((quat)b).y};
	lhs = _mm_mul_ps(lhs, tmp);

	//construct the right hand side
	tmp = _mm_set_ps(((quat)a).y, ((quat)a).x, ((quat)a).z, ((quat)a).x);
	__m128 rhs = {((quat)b).x, ((quat)b).y, ((quat)b).z, ((quat)b).x};
	rhs = _mm_mul_ps(tmp, rhs);
	res.vec = _mm_add_ps(res.vec, _mm_sub_ps(lhs, rhs));

	//scalar component of the result
	res.w = scalar.w-(scalar.x+scalar.y+scalar.z);
	return res.vec;
}
