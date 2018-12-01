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
	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}
float quat_len(__m128 a){
	quat tmp = (quat)_mm_mul_ps(a, a);
	return sqrtf(tmp.x+tmp.y+tmp.z+tmp.w);
}
__m128 quat_norm(__m128 a){
	quat tmp = (quat)_mm_mul_ps(a, a);
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.x+tmp.y+tmp.z+tmp.w)));
}
__m128 quat_set(float w, float x, float y, float z){
	return _mm_set_ps(w, z, y, x);
}
__m128 quat_conj(__m128 a){
	return _mm_mul_ps(a, _mm_set_ps(1.f, -1.f, -1.f, -1.f));
}
__m128 quat_inv(__m128 a){
	quat square = (quat)_mm_mul_ps(a, a);
	a = _mm_mul_ps(a, _mm_set_ps(1.f, -1.f, -1.f, -1.f));
	float len = sqrtf(square.x+square.y+square.z+square.w);
	return _mm_div_ps(a, _mm_set1_ps(len));
}
__m128 quat_mul(__m128 a, __m128 b){
	//vector component of the result

	//multiply the b vector by the a scalar and the a vector by the b scalar and add the two resulting vectors
	//the w component of this result is ignored
	quat res = (quat)_mm_add_ps(_mm_mul_ps(_mm_set1_ps(((quat)a).w), b), _mm_mul_ps(_mm_set1_ps(((quat)b).w), a));

	//cross multiplication
	//construct left hand side of vector equation
	//using x as the last component allows this to be done using a single shufps
	__m128 lhs = {((quat)a).y, ((quat)a).z, ((quat)a).x, ((quat)a).x};
	__m128 tmp = {((quat)b).z, ((quat)b).x, ((quat)b).y, ((quat)b).x};
	lhs = _mm_mul_ps(lhs, tmp);

	//construct the right hand side
	tmp = _mm_set_ps(((quat)a).x, ((quat)a).y, ((quat)a).x, ((quat)a).z);
	__m128 rhs = {((quat)b).y, ((quat)b).z, ((quat)b).x, ((quat)b).x};
	rhs = _mm_mul_ps(tmp, rhs);
	res.vec = _mm_add_ps(res.vec, _mm_sub_ps(lhs, rhs));

	//scalar component of the result
	quat scalar = (quat)_mm_mul_ps(a, b);
	res.w = scalar.w-(scalar.x+scalar.y+scalar.z);
	return res.vec;
}
__m128 quat_mulReal(__m128 a, __m128 b){
	//x, y, and z should be 0 when calling this function so mul doesnt mess up anything
	return _mm_mul_ps(a, b);
}
__m128 quat_mulPure(__m128 a, __m128 b){
	quat res;

	//vector part

	//cross multiplication
	//construct left hand side of vector equation
	//using x as the last component allows this to be done using a single shufps
	__m128 lhs = {((quat)a).y, ((quat)a).z, ((quat)a).x, ((quat)a).x};
	__m128 tmp = {((quat)b).z, ((quat)b).x, ((quat)b).y, ((quat)b).x};
	lhs = _mm_mul_ps(lhs, tmp);

	//construct the right hand side
	tmp = _mm_set_ps(((quat)a).x, ((quat)a).y, ((quat)a).x, ((quat)a).z);
	__m128 rhs = {((quat)b).y, ((quat)b).z, ((quat)b).x, ((quat)b).x};
	rhs = _mm_mul_ps(tmp, rhs);
	res.vec = _mm_add_ps(res.vec, _mm_sub_ps(lhs, rhs));

	//scalar part
	quat scalar = (quat)_mm_mul_ps(a, b);
	res.w = scalar.w-(scalar.x+scalar.y+scalar.z);
	return res.vec;
}
__m128 quat_div(__m128 a, __m128 b){
	quat square = (quat)_mm_mul_ps(a, a);
	a = _mm_mul_ps(a, _mm_set_ps(1.f, -1.f, -1.f, -1.f));
	float len = sqrtf(square.x+square.y+square.z+square.w);
	b = _mm_div_ps(b, _mm_set1_ps(len));

	//vector component of the result
	quat res = (quat)_mm_add_ps(_mm_mul_ps(_mm_set1_ps(((quat)a).w), b), _mm_mul_ps(_mm_set1_ps(((quat)b).w), a));

	//cross multiplication
	//construct left hand side of vector equation
	//using x as the last component allows this to be done using a single shufps
	__m128 lhs = {((quat)a).y, ((quat)a).z, ((quat)a).x, ((quat)a).x};
	__m128 tmp = {((quat)b).z, ((quat)b).x, ((quat)b).y, ((quat)b).x};
	lhs = _mm_mul_ps(lhs, tmp);

	//construct the right hand side
	tmp = _mm_set_ps(((quat)a).x, ((quat)a).y, ((quat)a).x, ((quat)a).z);
	__m128 rhs = {((quat)b).y, ((quat)b).z, ((quat)b).x, ((quat)b).x};
	rhs = _mm_mul_ps(tmp, rhs);
	res.vec = _mm_add_ps(res.vec, _mm_sub_ps(lhs, rhs));

	//scalar component of the result
	quat scalar = (quat)_mm_mul_ps(a, b);
	res.w = scalar.w-(scalar.x+scalar.y+scalar.z);
	return res.vec;
}
