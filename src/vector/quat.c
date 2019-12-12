#include "vector/quat.h"

__m128 quat_set(float w, float x, float y, float z){
	return _mm_set_ps(w, z, y, x);
}

bool quat_equal(__m128 a, __m128 b){
	a = quat_sub(a, b);
	a = quat_abs(a);

	quat tmp = (quat)quat_set1(FLT_EPSILON);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);

	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}

bool quat_equal_eps(__m128 a, __m128 b, float epsilon){
	a = quat_sub(a, b);
	a = quat_abs(a);

	quat tmp = (quat)quat_set1(epsilon);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);

	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}

float quat_len(__m128 a){
	quat tmp = (quat)quat_mul(a, a);
	return sqrtf(tmp.x+tmp.y+tmp.z+tmp.w);
}

__m128 quat_norm(__m128 a){
	quat tmp = (quat)quat_mul(a, a);
	return _mm_div_ps(a, quat_set1(sqrtf(tmp.x+tmp.y+tmp.z+tmp.w)));
}

__m128 quat_conj(__m128 a){
	return quat_mul(a, quat_set(1.f, -1.f, -1.f, -1.f));
}

__m128 quat_inv(__m128 a){
	quat square = (quat)quat_mul(a, a);
	a = quat_mul(a, quat_set(1.f, -1.f, -1.f, -1.f));
	float len = sqrtf(square.x+square.y+square.z+square.w);
	return _mm_div_ps(a, _mm_set1_ps(len));
}

__m128 quat_mul(__m128 a, __m128 b){
	//vector component of the result:

	/*multiply the b vector by the a scalar and the a vector by the b scalar and add the two resulting vectors
	the w component of this result is ignored*/
	quat res = (quat)_mm_add_ps(_mm_mul_ps(_mm_set1_ps(((quat)a).w), b), _mm_mul_ps(_mm_set1_ps(((quat)b).w), a));

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

__m128 quat_rotation(float angle, float x, float y, float z){
	__m128 res = _mm_set_ps(1.f, z, y, x);
	float angleSin = sin(angle);
	float angleCos = cos(angle);
	res = _mm_mul_ps(res, _mm_set_ps(angleCos, angleSin, angleSin, angleSin));
	return res;
}

mat4 quat_toMat(__m128 a){
	mat4 res;
	float x = ((quat)a).x;
	float y = ((quat)a).y;
	float z = ((quat)a).z;
	float w = ((quat)a).w;

	res.mat[0] = _mm_setr_ps(1.f - 2.f*y*y - 2.f*z*z,
		2.f*x*y - 2.f*z*w,
		2.f*x*z + 2.f*y*w,
		0.f);
	res.mat[1] = _mm_setr_ps(2.f*x*y + 2.f*z*w,
		1.f - 2.f*x*x - 2.f*z*z,
		2.f*y*z - 2.f*x*w,
		0.f);
	res.mat[2] = _mm_setr_ps(2.f*x*z - 2.f*y*w,
		2.f*y*z + 2.f*x*w,
		1.f - 2.f*x*x - 2.f*y*y,
		0.f);
	res.mat[3] = _mm_setr_ps(0.f, 0.f, 0.f, 1.f);

	return res;
}
