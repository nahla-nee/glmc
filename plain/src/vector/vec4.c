#include "vector/vec4.h"

float vec4_equal(vec4 a, vec4 b){
	a.x = fabs(a.x-b.x);
	a.y = fabs(a.y-b.y);
	a.z = fabs(a.z-b.z);
	a.w = fabs(a.w-b.w);
	if(a.x > FLT_EPSILON || a.y > FLT_EPSILON || a.z > FLT_EPSILON || a.w > FLT_EPSILON){
		return false;
	}
	return true;
}
float vec4_equal_eps(vec4 a, vec4 b, float epsilon){
	a.x = fabs(a.x-b.x);
	a.y = fabs(a.y-b.y);
	a.z = fabs(a.z-b.z);
	a.w = fabs(a.w-b.w);
	if(a.x > epsilon || a.y > epsilon || a.z > epsilon || a.w > epsilon){
		return false;
	}
	return true;
}
float vec4_len(vec4 a){
	return sqrtf(a.x*a.x+a.y*a.y+a.z*a.z+a.w*a.w);
}
vec4 vec4_norm(vec4 a){
	float len = sqrtf(a.x*a.x+a.y*a.y+a.z*a.z+a.w*a.w);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	a.w /= len;
	return a;
}
vec4 vec4_set(float x, float y, float z, float w){
	vec4 res = {x, y, z, w};
	return res;
}
vec4 vec4_set1(float x){
	vec4 res = {x, x, x, x};
	return res;
}
vec4 vec4_add(vec4 a, vec4 b){
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
vec4 vec4_sub(vec4 a, vec4 b){
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
vec4 vec4_mul(vec4 a, vec4 b){
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
vec4 vec4_div(vec4 a, vec4 b){
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}
vec4 vec4_addScal(vec4 a, float scalar){
	a.x += scalar;
	a.y += scalar;
	a.z += scalar;
	a.w += scalar;
	return a;
}
vec4 vec4_subScal(vec4 a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	a.z -= scalar;
	a.w -= scalar;
	return a;
}
vec4 vec4_mulScal(vec4 a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	a.w *= scalar;
	return a;
}
vec4 vec4_divScal(vec4 a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	a.z /= scalar;
	a.w /= scalar;
	return a;
}
float vec4_dot(vec4 a, vec4 b){
	return (a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w);
}
vec4 vec4_abs(vec4 a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	a.z = fabs(a.z);
	a.w = fabs(a.w);
	return a;
}
vec4 vec4_ceil(vec4 a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	a.z = ceilf(a.z);
	a.w = ceilf(a.w);
	return a;
}
vec4 vec4_floor(vec4 a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	a.z = floorf(a.z);
	a.w = floorf(a.w);
	return a;
}
vec4 vec4_round(vec4 a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	a.z = roundf(a.z);
	a.w = roundf(a.w);
	return a;
}
vec4 vec4_mulMat(vec4 a, mat4 b){
	vec4 res;

	res.vec[0] = a.x*b.m0+a.y*b.m4+a.z*b.m8+a.w*b.m12;
	res.vec[1] = a.x*b.m1+a.y*b.m5+a.z*b.m9+a.w*b.m13;
	res.vec[2] = a.x*b.m2+a.y*b.m6+a.z*b.m10+a.w*b.m14;
	res.vec[3] = a.x*b.m3+a.y*b.m7+a.z*b.m11+a.w*b.m15;

	return res;
}
