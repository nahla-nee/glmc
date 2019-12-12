#include "vector/vec3.h"

__m128 vec3_set(float x, float y, float z){
	return _mm_set_ps(0.f, z, y, x);
}

bool vec3_equal(__m128 a, __m128 b){
	a = vec3_add(a, b);
	a = vec3_abs(a);

	vec3 tmp = (vec3)vec3_set1(FLT_EPSILON);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);

	if((int)tmp.x || (int)tmp.y || (int)tmp.z){
		return false;
	}
	return true;
}

bool vec3_equal_eps(__m128 a, __m128 b, float epsilon){
	a = vec3_add(a, b);
	a = vec3_abs(a);

	vec3 tmp = (vec3)vec3_set1(epsilon);
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);

	if((int)tmp.x || (int)tmp.y || (int)tmp.z){
		return false;
	}
	return true;
}

float vec3_len(__m128 a){
	vec3 tmp = (vec3)vec3_mul(a, a);
	return sqrtf(tmp.x+tmp.y+tmp.z);
}

__m128 vec3_norm(__m128 a){
	vec3 tmp = (vec3)vec3_mul(a, a);
	return _mm_div_ps(a, vec3_set1(sqrtf(tmp.x+tmp.y+tmp.z)));
}

float vec3_dot(__m128 a, __m128 b){
	vec3 tmp = (vec3)vec3_mul(a, b);
	return (tmp.x+tmp.y+tmp.z);
}

__m128 vec3_cross(__m128 a, __m128 b){
	//construct left hand side of vector equation
	//using x as the last component allows this to be done using a single shufps
	__m128 tmp = {((vec3)a).y, ((vec3)a).z, ((vec3)a).x, ((vec3)a).x};
	__m128 lhs = {((vec3)b).z, ((vec3)b).x, ((vec3)b).y, ((vec3)b).x};
	lhs = _mm_mul_ps(lhs, tmp);

	//construct the right hand side
	tmp = _mm_set_ps(((vec3)a).x, ((vec3)a).y, ((vec3)a).x, ((vec3)a).z);
	__m128 rhs = {((vec3)b).y, ((vec3)b).z, ((vec3)b).x, ((vec3)b).x};
	rhs = _mm_mul_ps(tmp, rhs);
	return _mm_sub_ps(lhs, rhs);
}

__m128 vec3_mulMat(__m128 a, mat3 b){
	vec3 tmp = (vec3)a;
	__m128 res = _mm_mul_ps(b.mat[0], _mm_set1_ps(tmp.x));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[1], _mm_set1_ps(tmp.y)));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[2], _mm_set1_ps(tmp.z)));
	return res;
}
