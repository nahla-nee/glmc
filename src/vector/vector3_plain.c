#include "vector/vector3_plain.h"

float vec3_equal(vec3 a, vec3 b){
	a.x = fabs(a.x-b.x);
	a.y = fabs(a.y-b.y);
	a.z = fabs(a.z-b.z);
	if(a.x > FLT_EPSILON || a.y > FLT_EPSILON || a.z > FLT_EPSILON){
		return false;
	}
	return true;
}
float vec3_equal_eps(vec3 a, vec3 b, float epsilon){
	a.x = fabs(a.x-b.x);
	a.y = fabs(a.y-b.y);
	a.z = fabs(a.z-b.z);
	if(a.x > epsilon || a.y > epsilon || a.z > epsilon){
		return false;
	}
	return true;
}
float vec3_len(vec3 a){
	return sqrtf(a.x*a.x+a.y*a.y+a.z*a.z);
}
vec3 vec3_norm(vec3 a){
	float len = sqrtf(a.x*a.x+a.y*a.y+a.z*a.z);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return a;
}
vec3 vec3_set(float x, float y, float z){
	vec3 res = {x, y, z};
	return res;
}
vec3 vec3_set1(float x){
	vec3 res = {x, x, x};
	return res;
}
vec3 vec3_add(vec3 a, vec3 b){
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
vec3 vec3_sub(vec3 a, vec3 b){
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
vec3 vec3_mul(vec3 a, vec3 b){
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
vec3 vec3_div(vec3 a, vec3 b){
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}
vec3 vec3_addScal(vec3 a, float scalar){
	a.x += scalar;
	a.y += scalar;
	a.z += scalar;
	return a;
}
vec3 vec3_subScal(vec3 a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	a.z -= scalar;
	return a;
}
vec3 vec3_mulScal(vec3 a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	return a;
}
vec3 vec3_divScal(vec3 a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	a.z /= scalar;
	return a;
}
float vec3_dot(vec3 a, vec3 b){
	return (a.x*b.x+a.y*b.y+a.z*b.z);
}
vec3 vec3_cross(vec3 a, vec3 b){
	return (vec3){a.y*b.z-a.z*b.y,
		a.z*b.x-a.x*b.z,
		a.x*b.y-a.y*b.x};
}
vec3 vec3_abs(vec3 a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	a.z = fabs(a.z);
	return a;
}
vec3 vec3_ceil(vec3 a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	a.z = ceilf(a.z);
	return a;
}
vec3 vec3_floor(vec3 a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	a.z = floorf(a.z);
	return a;
}
vec3 vec3_round(vec3 a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	a.z = roundf(a.z);
	return a;
}
vec3 vec3_mulMat(vec3 a, mat3 b){
	vec3 res;

	res.vec[0] = a.x*b.m11+a.y*b.m21+a.z*b.m31;
	res.vec[1] = a.x*b.m12+a.y*b.m22+a.z*b.m32;
	res.vec[2] = a.x*b.m13+a.y*b.m23+a.z*b.m33;

	return res;
}
