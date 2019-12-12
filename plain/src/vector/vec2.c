#include "vector/vec2.h"

float vec2_equal(vec2 a, vec2 b){
	a.x = fabs(a.x-b.x);
	a.y = fabs(a.y-b.y);
	if(a.x > FLT_EPSILON || a.y > FLT_EPSILON){
		return false;
	}
	return true;
}
float vec2_equal_eps(vec2 a, vec2 b, float epsilon){
	a.x = fabs(a.x-b.x);
	a.y = fabs(a.y-b.y);
	if(a.x > epsilon || a.y > epsilon){
		return false;
	}
	return true;
}
float vec2_len(vec2 a){
	return sqrtf(a.x*a.x+a.y*a.y);
}
vec2 vec2_norm(vec2 a){
	float len = sqrtf(a.x*a.x+a.y*a.y);
	a.x /= len;
	a.y /= len;
	return a;
}
vec2 vec2_set(float x, float y){
	vec2 res = {x, y};
	return res;
}
vec2 vec2_set1(float x){
	vec2 res = {x, x};
	return res;
}
vec2 vec2_add(vec2 a, vec2 b){
	a.x += b.x;
	a.y += b.y;
	return a;
}
vec2 vec2_sub(vec2 a, vec2 b){
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
vec2 vec2_mul(vec2 a, vec2 b){
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
vec2 vec2_div(vec2 a, vec2 b){
	a.x /= b.x;
	a.y /= b.y;
	return a;
}
vec2 vec2_addScal(vec2 a, float scalar){
	a.x += scalar;
	a.y += scalar;
	return a;
}
vec2 vec2_subScal(vec2 a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	return a;
}
vec2 vec2_mulScal(vec2 a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	return a;
}
vec2 vec2_divScal(vec2 a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	return a;
}
float vec2_dot(vec2 a, vec2 b){
	return a.x*b.x+a.y*b.y;
}
vec2 vec2_abs(vec2 a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	return a;
}
vec2 vec2_ceil(vec2 a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	return a;
}
vec2 vec2_floor(vec2 a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	return a;
}
vec2 vec2_round(vec2 a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	return a;
}
vec2 vec2_mulMat(vec2 a, mat2 b){
	vec2 res;

	res.vec[0] = a.x*b.m0+a.y*b.m2;
	res.vec[1] = a.x*b.m1+a.y*b.m3;

	return res;
}
