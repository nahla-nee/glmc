#include "vector/quaternion_plain.h"

quat quat_set(float w, float x, float y, float z){
	quat res = {w, x, y, z};
	return res;
}
quat quat_set1(float x){
	quat res = {x, x, x, x};
	return res;
}
quat quat_add(quat a, quat b){
	a.w+=b.w;
	a.x+=b.x;
	a.y+=b.y;
	a.z+=b.z;
	return a;
}
quat quat_sub(quat a, quat b){
	a.w-=b.w;
	a.x-=b.x;
	a.y-=b.y;
	a.z-=b.z;
	return a;
}
quat quat_div(quat a, quat b){
	a.w/=b.w;
	a.x/=b.x;
	a.y/=b.y;
	a.z/=b.z;
	return a;
}
quat quat_addScal(quat a, float scalar){
	a.w+=scalar;
	a.x+=scalar;
	a.y+=scalar;
	a.z+=scalar;
	return a;
}
quat quat_subScal(quat a, float scalar){
	a.w-=scalar;
	a.x-=scalar;
	a.y-=scalar;
	a.z-=scalar;
	return a;
}
quat quat_mulScal(quat a, float scalar){
	a.w*=scalar;
	a.x*=scalar;
	a.y*=scalar;
	a.z*=scalar;
	return a;
}
quat quat_divScal(quat a, float scalar){
	a.w/=scalar;
	a.x/=scalar;
	a.y/=scalar;
	a.z/=scalar;
	return a;
}
quat quat_abs(quat a){
	a.w = fabs(a.w);
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	a.z = fabs(a.z);
	return a;
}
quat quat_ceil(quat a){
	a.w = ceilf(a.w);
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	a.z = ceilf(a.z);
	return a;
}
quat quat_floor(quat a){
	a.w = floorf(a.w);
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	a.z = floorf(a.z);
	return a;
}
quat quat_round(quat a){
	a.w = roundf(a.w);
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	a.z = roundf(a.z);
	return a;
}
bool quat_equal(quat a, quat b){
	a.w = fabs(a.w-b.w);
	a.x = fabs(a.x-b.x);
	a.y = fabs(a.y-b.y);
	a.z = fabs(a.z-b.z);
	if(a.w > FLT_EPSILON || a.x > FLT_EPSILON || a.y > FLT_EPSILON || a.z > FLT_EPSILON){
		return false;
	}
	return true;
}
bool quat_equal_eps(quat a, quat b, float epsilon){
	a.w = fabs(a.w-b.w);
	a.x = fabs(a.x-b.x);
	a.y = fabs(a.y-b.y);
	a.z = fabs(a.z-b.z);
	if(a.w > epsilon || a.x > epsilon || a.y > epsilon || a.z > epsilon){
		return false;
	}
	return true;
}
float quat_len(quat a){
	return sqrtf(a.w*a.w+a.x*a.x+a.y*a.y+a.z*a.z);
}
quat quat_norm(quat a){
	float len = sqrtf(a.w*a.w+a.x*a.x+a.y*a.y+a.z*a.z);
	a.w/=len;
	a.x/=len;
	a.y/=len;
	a.z/=len;
	return a;
}
quat quat_mul(quat a, quat b){
	quat res;
	//scalar
	res.w = (a.w*b.w-(a.x*b.x+a.y*b.y+a.z*b.z));

	//vector
	/*result of adding the vector resulting from multiplying vector a by scalar b
	with the result of multiplying vector b by scalar a*/
	res.x = a.w*b.x+b.w*a.x;
	res.y = a.w*b.y+b.w*a.y;
	res.z = a.w*b.z+b.w*a.z;

	//cross multiply a and b and add to res gives the final vector of res
	quat cross = {0.0f, a.y*b.z-a.z*b.y,
		a.z*b.x-a.x*b.z,
		a.x*b.y-a.y*b.x};
	res.x+=cross.x;
	res.y+=cross.y;
	res.z+=cross.z;
	return res;
}
