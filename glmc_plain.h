#ifndef __GLMC_PLAIN_H__
#define __GLMC_PLAIN_H__

//non SSE version of glmc!
//you really shouldn't use this, literally every CPU supports SSE

#ifdef __cplusplus
extern "C"{
#endif

#include <math.h>

typedef union vec2_plain{
	float vec[2];
	struct{
		float x, y;
	};
} vec2_plain;

typedef union vec3_plain{
	float vec[3];
	struct{
		float x, y, z;
	};
	struct{
		float r, g, b;
	}
} vec3_plain;

typedef union vec4_plain{
	float vec[4];
	struct{
		float x, y, z, w;
	};
	struct{
		float r, g, b, a;
	}
} vec4_plain;

typedef union mat4_plain{
	float mat[16];
	float mat2D[4][4];
	struct{
		float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
	};
} mat4_plain;

typedef union mat3_plain{
	float mat[9];
	float mat2D[3][3];
	struct{
		float m11, m12, m13, m21, m22, m23, m31, m32, m33;
	};
} mat3_plain;

typedef union mat2_plain{
	float mat[4];
	float mat2D[2][2];
	struct{
		float m11, m12, m21, m22;
	};
} mat2_plain;

//its nicer to have the w be the first member of a quaternion, i could just typedef a vec4 to be a quaternion
//but am i gonna?
typedef union quaternion{
	float quat[4];
	struct{
		float w, x, y, z;
	};
} quaternion;

static inline float vec2_plain_len(vec2_plain a){
	return sqrtf(a.x*a.x+a.y*a.y);
}
static inline vec2_plain vec2_plain_norm(vec2_plain a){
	float len = sqrtf(a.x*a.x+a.y*a.y);
	a.x /= len;
	a.y /= len;
	return a;
}
static inline vec2_plain vec2_plain_set(float x, float y){
	vec2_plain res = {x, y, 0.0f, 0.0f};
	return res;
}
static inline vec2_plain vec2_plain_set1(float x){
	vec2_plain res = {x, x, 0.0f, 0.0f};
	return res;
}
static inline vec2_plain vec2_plain_add(vec2_plain a, vec2_plain b){
	a.x += b.x;
	a.y += b.y;
	return a;
}
static inline vec2_plain vec2_plain_sub(vec2_plain a, vec2_plain b){
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
static inline vec2_plain vec2_plain_mul(vec2_plain a, vec2_plain b){
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
static inline vec2_plain vec2_plain_div(vec2_plain a, vec2_plain b){
	a.x /= b.x;
	a.y /= b.y;
	return a;
}
static inline vec2_plain vec2_plain_addScal(vec2_plain a, float scalar){
	a.x += scalar;
	a.y += scalar;
	return a;
}
static inline vec2_plain vec2_plain_subScal(vec2_plain a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	return a;
}
static inline vec2_plain vec2_plain_mulScal(vec2_plain a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	return a;
}
static inline vec2_plain vec2_plain_divScal(vec2_plain a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	return a;
}
static inline float vec2_plain_dot(vec2_plain a, vec2_plain b){
	return a.x*b.x+a.y*b.y;
}
static inline vec2_plain vec2_plain_abs(vec2_plain a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	return a;
}
static inline vec2_plain vec2_plain_ceil(vec2_plain a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	return a;
}
static inline vec2_plain vec2_plain_floor(vec2_plain a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	return a;
}
static inline vec2_plain vec2_plain_round(vec2_plain a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	return a;
}
static inline vec2_plain vec2_plain_mulMat(vec2_plain a, mat2_plain b){
	vec2_plain res;

	res.vec[0] = a.x*b.m11+a.y*b.m21+a.z*b.m31;
	res.vec[1] = a.x*b.m12+a.y*b.m22+a.z*b.m32;
	res.vec[2] = a.x*b.m13+a.y*b.m23+a.z*b.m33;

	return res;
}

//vec3 functions
static inline float vec3_plain_len(vec3_plain a){
	return sqrtf(a.x*a.x+a.y*a.y+a.z*a.z);
}
static inline vec3_plain vec3_plain_norm(vec3_plain a){
	float len = sqrtf(a.x*a.x+a.y*a.y+a.z*a.z);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return a;
}
static inline vec3_plain vec3_plain_set(float x, float y, float z){
	vec3_plain res = {x, y, z, 0.0f};
	return res;
}
static inline vec3_plain vec3_plain_set1(float x){
	vec3_plain res = {x, x, x, 0.0f};
	return res;
}
static inline vec3_plain vec3_plain_add(vec3_plain a, vec3_plain b){
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
static inline vec3_plain vec3_plain_sub(vec3_plain a, vec3_plain b){
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
static inline vec3_plain vec3_plain_mul(vec3_plain a, vec3_plain b){
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
static inline vec3_plain vec3_plain_div(vec3_plain a, vec3_plain b){
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}
static inline vec3_plain vec3_plain_addScal(vec3_plain a, float scalar){
	a.x += scalar;
	a.y += scalar;
	a.z += scalar;
	return a;
}
static inline vec3_plain vec3_plain_subScal(vec3_plain a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	a.z -= scalar;
	return a;
}
static inline vec3_plain vec3_plain_mulScal(vec3_plain a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	return a;
}
static inline vec3_plain vec3_plain_divScal(vec3_plain a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	a.z /= scalar;
	return a;
}
static inline float vec3_plain_dot(vec3_plain a, vec3_plain b){
	return (a.x*b.x+a.y*b.y+a.z*b.z);
}
static inline vec3_plain vec3_plain_abs(vec3_plain a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	a.z = fabs(a.z);
	return a;
}
static inline vec3_plain vec3_plain_ceil(vec3_plain a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	a.z = ceilf(a.z);
	return a;
}
static inline vec3_plain vec3_plain_floor(vec3_plain a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	a.z = floorf(a.z);
	return a;
}
static inline vec3_plain vec3_plain_round(vec3_plain a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	a.z = roundf(a.z);
	return a;
}
static inline vec3_plain vec3_plain_mulMat(vec3_plain a, mat3_plain b){
	vec3_plain res;

	res.vec[0] = a.x*b.m11+a.y*b.m21+a.z*b.m31;
	res.vec[1] = a.x*b.m12+a.y*b.m22+a.z*b.m32;
	res.vec[2] = a.x*b.m13+a.y*b.m23+a.z*b.m33;

	return res;
}

//vec4 functions
static inline float vec4_plain_len(vec4_plain a){
	return sqrtf(a.x*a.x+a.y*a.y+a.z*a.z+a.w*a.w);
}
static inline vec4_plain vec4_plain_norm(vec4_plain a){
	float len = sqrtf(a.x*a.x+a.y*a.y+a.z*a.z+a.w*a.w);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	a.w /= len;
	return a;
}
static inline vec4_plain vec4_plain_set(float x, float y, float z, float w){
	vec4_plain res = {x, y, z, w};
	return res;
}
static inline vec4_plain vec4_plain_set1(float x){
	vec4_plain res = {x, x, x, x};
	return res;
}
static inline vec4_plain vec4_plain_add(vec4_plain a, vec4_plain b){
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
static inline vec4_plain vec4_plain_sub(vec4_plain a, vec4_plain b){
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
static inline vec4_plain vec4_plain_mul(vec4_plain a, vec4_plain b){
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
static inline vec4_plain vec4_plain_div(vec4_plain a, vec4_plain b){
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}
static inline vec4_plain vec4_plain_addScal(vec4_plain a, float scalar){
	a.x += scalar;
	a.y += scalar;
	a.z += scalar;
	a.w += scalar;
	return a;
}
static inline vec4_plain vec4_plain_subScal(vec4_plain a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	a.z -= scalar;
	a.w -= scalar;
	return a;
}
static inline vec4_plain vec4_plain_mulScal(vec4_plain a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	a.w *= scalar;
	return a;
}
static inline vec4_plain vec4_plain_divScal(vec4_plain a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	a.z /= scalar;
	a.w /= scalar;
	return a;
}
static inline float vec4_plain_dot(vec4_plain a, vec4_plain b){
	return (a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w);
}
static inline vec4_plain vec4_plain_abs(vec4_plain a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	a.z = fabs(a.z);
	a.w = fabs(a.w);
	return a;
}
static inline vec4_plain vec4_plain_ceil(vec4_plain a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	a.z = ceilf(a.z);
	a.w = ceilf(a.w);
	return a;
}
static inline vec4_plain vec4_plain_floor(vec4_plain a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	a.z = floorf(a.z);
	a.w = floorf(a.w);
	return a;
}
static inline vec4_plain vec4_plain_round(vec4_plain a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	a.z = roundf(a.z);
	a.w = roundf(a.w);
	return a;
}
static inline vec4_plain vec4_plain_mulMat(vec4_plain a, mat4_plain b){
	vec4_plain res;

	res.vec[0] = a.x*b.m11+a.y*b.m21+a.z*b.m31+a.w*b.m41;
	res.vec[1] = a.x*b.m12+a.y*b.m22+a.z*b.m32+a.w*b.m42;
	res.vec[2] = a.x*b.m13+a.y*b.m23+a.z*b.m33+a.w*b.m43;
	res.vec[3] = a.x*b.m14+a.y*b.m24+a.z*b.m34+a.w*b.m44;

	return res;
}

static inline mat4_plain mat4_plain_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15){
	mat4_plain a = {m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15};
	return a;
}
static inline mat4_plain mat4_plain_set1(float x){
	mat4_plain a = {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x};
	return a;
}
static inline mat4_plain mat4_plain_add(mat4_plain a, mat4_plain b){
	a.mat[0] = a.mat[0]+b.mat[0];
	a.mat[1] = a.mat[1]+b.mat[1];
	a.mat[2] = a.mat[2]+b.mat[2];
	a.mat[3] = a.mat[3]+b.mat[3];
	a.mat[4] = a.mat[4]+b.mat[4];
	a.mat[5] = a.mat[5]+b.mat[5];
	a.mat[6] = a.mat[6]+b.mat[6];
	a.mat[7] = a.mat[7]+b.mat[7];
	a.mat[8] = a.mat[8]+b.mat[8];
	a.mat[9] = a.mat[9]+b.mat[9];
	a.mat[10] = a.mat[10]+b.mat[10];
	a.mat[11] = a.mat[11]+b.mat[11];
	a.mat[12] = a.mat[12]+b.mat[12];
	a.mat[13] = a.mat[13]+b.mat[13];
	a.mat[14] = a.mat[14]+b.mat[14];
	a.mat[15] = a.mat[15]+b.mat[15];
	return a;
}
static inline mat4_plain mat4_plain_sub(mat4_plain a, mat4_plain b){
	a.mat[0] = a.mat[0]-b.mat[0];
	a.mat[1] = a.mat[1]-b.mat[1];
	a.mat[2] = a.mat[2]-b.mat[2];
	a.mat[3] = a.mat[3]-b.mat[3];
	a.mat[4] = a.mat[4]-b.mat[4];
	a.mat[5] = a.mat[5]-b.mat[5];
	a.mat[6] = a.mat[6]-b.mat[6];
	a.mat[7] = a.mat[7]-b.mat[7];
	a.mat[8] = a.mat[8]-b.mat[8];
	a.mat[9] = a.mat[9]-b.mat[9];
	a.mat[10] = a.mat[10]-b.mat[10];
	a.mat[11] = a.mat[11]-b.mat[11];
	a.mat[12] = a.mat[12]-b.mat[12];
	a.mat[13] = a.mat[13]-b.mat[13];
	a.mat[14] = a.mat[14]-b.mat[14];
	a.mat[15] = a.mat[15]-b.mat[15];
	return a;
}
static inline mat4_plain mat4_plain_mul(mat4_plain a, mat4_plain b){
	mat4_plain res;
	res.mat[0] = a.m11*b.m11+a.m21*b.m12+a.m31*b.m13+a.m41*b.m14;
	res.mat[1] = a.m12*b.m11+a.m22*b.m12+a.m32*b.m13+a.m42*b.m14;
	res.mat[2] = a.m13*b.m11+a.m23*b.m12+a.m33*b.m13+a.m43*b.m14;
	res.mat[3] = a.m14*b.m11+a.m24*b.m12+a.m34*b.m13+a.m44*b.m14;

	res.mat[4] = a.m11*b.m21+a.m21*b.m22+a.m31*b.m23+a.m41*b.m24;
	res.mat[5] = a.m12*b.m21+a.m22*b.m22+a.m32*b.m23+a.m42*b.m24;
	res.mat[6] = a.m13*b.m21+a.m23*b.m22+a.m33*b.m23+a.m43*b.m24;
	res.mat[7] = a.m14*b.m21+a.m24*b.m22+a.m34*b.m23+a.m44*b.m24;

	res.mat[8] = a.m11*b.m31+a.m21*b.m32+a.m31*b.m33+a.m41*b.m34;
	res.mat[9] = a.m12*b.m31+a.m22*b.m32+a.m32*b.m33+a.m42*b.m34;
	res.mat[10] = a.m13*b.m31+a.m23*b.m32+a.m33*b.m33+a.m43*b.m34;
	res.mat[11] = a.m14*b.m31+a.m24*b.m32+a.m34*b.m33+a.m44*b.m34;

	res.mat[12] = a.m11*b.m41+a.m21*b.m42+a.m31*b.m43+a.m41*b.m44;
	res.mat[13] = a.m12*b.m41+a.m22*b.m42+a.m32*b.m43+a.m42*b.m44;
	res.mat[14] = a.m13*b.m41+a.m23*b.m42+a.m33*b.m43+a.m43*b.m44;
	res.mat[15] = a.m14*b.m41+a.m24*b.m42+a.m34*b.m43+a.m44*b.m44;
	return a;
}
static inline mat4_plain mat4_plain_addScal(mat4_plain a, float scalar){
	mat4_plain scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.mat[0] = a.mat[0]+scal.mat[0];
	a.mat[1] = a.mat[1]+scal.mat[1];
	a.mat[2] = a.mat[2]+scal.mat[2];
	a.mat[3] = a.mat[3]+scal.mat[3];
	a.mat[4] = a.mat[4]+scal.mat[4];
	a.mat[5] = a.mat[5]+scal.mat[5];
	a.mat[6] = a.mat[6]+scal.mat[6];
	a.mat[7] = a.mat[7]+scal.mat[7];
	a.mat[8] = a.mat[8]+scal.mat[8];
	a.mat[9] = a.mat[9]+scal.mat[9];
	a.mat[10] = a.mat[10]+scal.mat[10];
	a.mat[11] = a.mat[11]+scal.mat[11];
	a.mat[12] = a.mat[12]+scal.mat[12];
	a.mat[13] = a.mat[13]+scal.mat[13];
	a.mat[14] = a.mat[14]+scal.mat[14];
	a.mat[15] = a.mat[15]+scal.mat[15];
	return a;
}
static inline mat4_plain mat4_plain_subScal(mat4_plain a, float scalar){
	mat4_plain scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.mat[0] = a.mat[0]-scal.mat[0];
	a.mat[1] = a.mat[1]-scal.mat[1];
	a.mat[2] = a.mat[2]-scal.mat[2];
	a.mat[3] = a.mat[3]-scal.mat[3];
	a.mat[4] = a.mat[4]-scal.mat[4];
	a.mat[5] = a.mat[5]-scal.mat[5];
	a.mat[6] = a.mat[6]-scal.mat[6];
	a.mat[7] = a.mat[7]-scal.mat[7];
	a.mat[8] = a.mat[8]-scal.mat[8];
	a.mat[9] = a.mat[9]-scal.mat[9];
	a.mat[10] = a.mat[10]-scal.mat[10];
	a.mat[11] = a.mat[11]-scal.mat[11];
	a.mat[12] = a.mat[12]-scal.mat[12];
	a.mat[13] = a.mat[13]-scal.mat[13];
	a.mat[14] = a.mat[14]-scal.mat[14];
	a.mat[15] = a.mat[15]-scal.mat[15];
	return a;
}
static inline mat4_plain mat4_plain_mulScal(mat4_plain a, float scalar){
	mat4_plain scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.mat[0] = a.mat[0]*scal.mat[0];
	a.mat[1] = a.mat[1]*scal.mat[1];
	a.mat[2] = a.mat[2]*scal.mat[2];
	a.mat[3] = a.mat[3]*scal.mat[3];
	a.mat[4] = a.mat[4]*scal.mat[4];
	a.mat[5] = a.mat[5]*scal.mat[5];
	a.mat[6] = a.mat[6]*scal.mat[6];
	a.mat[7] = a.mat[7]*scal.mat[7];
	a.mat[8] = a.mat[8]*scal.mat[8];
	a.mat[9] = a.mat[9]*scal.mat[9];
	a.mat[10] = a.mat[10]*scal.mat[10];
	a.mat[11] = a.mat[11]*scal.mat[11];
	a.mat[12] = a.mat[12]*scal.mat[12];
	a.mat[13] = a.mat[13]*scal.mat[13];
	a.mat[14] = a.mat[14]*scal.mat[14];
	a.mat[15] = a.mat[15]*scal.mat[15];
	return a;
}
static inline mat4_plain mat4_plain_divScal(mat4_plain a, float scalar){
	mat4_plain scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.mat[0] = a.mat[0]/scal.mat[0];
	a.mat[1] = a.mat[1]/scal.mat[1];
	a.mat[2] = a.mat[2]/scal.mat[2];
	a.mat[3] = a.mat[3]/scal.mat[3];
	a.mat[4] = a.mat[4]/scal.mat[4];
	a.mat[5] = a.mat[5]/scal.mat[5];
	a.mat[6] = a.mat[6]/scal.mat[6];
	a.mat[7] = a.mat[7]/scal.mat[7];
	a.mat[8] = a.mat[8]/scal.mat[8];
	a.mat[9] = a.mat[9]/scal.mat[9];
	a.mat[10] = a.mat[10]/scal.mat[10];
	a.mat[11] = a.mat[11]/scal.mat[11];
	a.mat[12] = a.mat[12]/scal.mat[12];
	a.mat[13] = a.mat[13]/scal.mat[13];
	a.mat[14] = a.mat[14]/scal.mat[14];
	a.mat[15] = a.mat[15]/scal.mat[15];
	return a;
}
static inline mat4_plain mat4_plain_identity(void){
	mat4_plain a = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	return a;
}
static inline mat4_plain mat4_plain_translate(float x, float y, float z){
	mat4_plain a = {1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		x, y, z, 1.f};
	return a;
}
static inline mat4_plain mat4_plain_scale(float x, float y, float z){
	mat4_plain a = {x, 0.0f, 0.0f, 0.0f,
		0.0f, y, 0.0f, 0.0f,
		0.0f, 0.0f, z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.f};
	return a;
}
static inline mat4_plain mat4_plain_transpose(mat4_plain a){
	//way faster to just use another matrix instead of a bunch of subtitutions
	mat4_plain res = {a.m11, a.m21, a.m31, a.m41,
		a.m12, a.m22, a.m32, a.m42,
		a.m13, a.m23, a.m33, a.m34,
		a.m14, a.m24, a.m34, a.m44};
	return res;
}
static inline mat4_plain mat4_plain_swapRow(mat4_plain a, int R1, int R2){
	float tmp[4] = {a.mat2D[0][R1], a.mat2D[1][R1], a.mat2D[2][R1], a.mat2D[3][R1]};

	a.mat2D[0][R1] = a.mat2D[0][R2];
	a.mat2D[1][R1] = a.mat2D[1][R2];
	a.mat2D[2][R1] = a.mat2D[2][R2];
	a.mat2D[3][R1] = a.mat2D[3][R2];

	a.mat2D[0][R2] = tmp[0];
	a.mat2D[1][R2] = tmp[1];
	a.mat2D[2][R2] = tmp[2];
	a.mat2D[3][R2] = tmp[3];

	return a;
}
static inline mat4_plain mat4_plain_swapCol(mat4_plain a, int C1, int C2){
	float tmp = a.mat2D[C1][0];
	a.mat2D[C1][0] = a.mat2D[C2][0];
	a.mat2D[C2][0] = tmp;

	tmp = a.mat2D[C1][1];
	a.mat2D[C1][1] = a.mat2D[C2][1];
	a.mat2D[C2][1] = tmp;

	tmp = a.mat2D[C1][2];
	a.mat2D[C1][2] = a.mat2D[C1][2];
	a.mat2D[C1][2] = tmp;

	tmp = a.mat2D[C1][3];
	a.mat2D[C1][3] = a.mat2D[C1][3];
	a.mat2D[C1][3] = tmp;

	return a;
}

static inline mat3_plain mat3_plain_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8){
	mat3_plain res = {m0, m1, m2, m3, m4, m5, m6, m7, m8};
	return res;
}
static inline mat3_plain mat3_plain_set1(float x){
	mat3_plain res = {x, x, x, x, x, x, x, x, x};
	return res;
}
static inline mat3_plain mat3_plain_add(mat3_plain a, mat3_plain b){
	a.mat[0] = a.mat[0]+b.mat[0];
	a.mat[1] = a.mat[1]+b.mat[1];
	a.mat[2] = a.mat[2]+b.mat[2];
	a.mat[3] = a.mat[3]+b.mat[3];
	a.mat[4] = a.mat[4]+b.mat[4];
	a.mat[5] = a.mat[5]+b.mat[5];
	a.mat[6] = a.mat[6]+b.mat[6];
	a.mat[7] = a.mat[7]+b.mat[7];
	a.mat[8] = a.mat[8]+b.mat[8];
	return a;
}
static inline mat3_plain mat3_plain_sub(mat3_plain a, mat3_plain b){
	a.mat[0] = a.mat[0]-b.mat[0];
	a.mat[1] = a.mat[1]-b.mat[1];
	a.mat[2] = a.mat[2]-b.mat[2];
	a.mat[3] = a.mat[3]-b.mat[3];
	a.mat[4] = a.mat[4]-b.mat[4];
	a.mat[5] = a.mat[5]-b.mat[5];
	a.mat[6] = a.mat[6]-b.mat[6];
	a.mat[7] = a.mat[7]-b.mat[7];
	a.mat[8] = a.mat[8]-b.mat[8];
	return a;
}
static inline mat3_plain mat3_plain_mul(mat3_plain a, mat3_plain b){
	mat3_plain res;

	res.mat[0] = a.m11*b.m11+a.m21*b.m12+a.m31*b.m13;
	res.mat[1] = a.m12*b.m11+a.m22*b.m12+a.m32*b.m13;
	res.mat[2] = a.m13*b.m11+a.m23*b.m12+a.m33*b.m13;

	res.mat[3] = a.m11*b.m21+a.m21*b.m22+a.m31*b.m23;
	res.mat[4] = a.m12*b.m21+a.m22*b.m22+a.m32*b.m23;
	res.mat[5] = a.m13*b.m21+a.m23*b.m22+a.m33*b.m23;

	res.mat[6] = a.m11*b.m31+a.m21*b.m32+a.m31*b.m33;
	res.mat[7] = a.m12*b.m31+a.m22*b.m32+a.m32*b.m33;
	res.mat[8] = a.m13*b.m31+a.m23*b.m32+a.m33*b.m33;

	return res;
}
static inline mat3_plain mat3_plain_addScal(mat3_plain a, float scalar){
	a.mat[0] = a.mat[0]+scalar;
	a.mat[1] = a.mat[1]+scalar;
	a.mat[2] = a.mat[2]+scalar;
	a.mat[3] = a.mat[3]+scalar;
	a.mat[4] = a.mat[4]+scalar;
	a.mat[5] = a.mat[5]+scalar;
	a.mat[6] = a.mat[6]+scalar;
	a.mat[7] = a.mat[7]+scalar;
	a.mat[8] = a.mat[8]+scalar;
	return a;
}
static inline mat3_plain mat3_plain_subScal(mat3_plain a, float scalar){
	a.mat[0] = a.mat[0]-scalar;
	a.mat[1] = a.mat[1]-scalar;
	a.mat[2] = a.mat[2]-scalar;
	a.mat[3] = a.mat[3]-scalar;
	a.mat[4] = a.mat[4]-scalar;
	a.mat[5] = a.mat[5]-scalar;
	a.mat[6] = a.mat[6]-scalar;
	a.mat[7] = a.mat[7]-scalar;
	a.mat[8] = a.mat[8]-scalar;
	return a;
}
static inline mat3_plain mat3_plain_mulScal(mat3_plain a, float scalar){
	a.mat[0] = a.mat[0]*scalar;
	a.mat[1] = a.mat[1]*scalar;
	a.mat[2] = a.mat[2]*scalar;
	a.mat[3] = a.mat[3]*scalar;
	a.mat[4] = a.mat[4]*scalar;
	a.mat[5] = a.mat[5]*scalar;
	a.mat[6] = a.mat[6]*scalar;
	a.mat[7] = a.mat[7]*scalar;
	a.mat[8] = a.mat[8]*scalar;
	return a;
}
static inline mat3_plain mat3_plain_divScal(mat3_plain a, float scalar){
	a.mat[0] = a.mat[0]/scalar;
	a.mat[1] = a.mat[1]/scalar;
	a.mat[2] = a.mat[2]/scalar;
	a.mat[3] = a.mat[3]/scalar;
	a.mat[4] = a.mat[4]/scalar;
	a.mat[5] = a.mat[5]/scalar;
	a.mat[6] = a.mat[6]/scalar;
	a.mat[7] = a.mat[7]/scalar;
	a.mat[8] = a.mat[8]/scalar;
	return a;
}
static inline mat3_plain mat3_plain_identity(void){
	mat3_plain res = {1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 0.f, 1.f};
	return res;
}
static inline mat3_plain mat3_plain_translate(float x, float y){
	mat3_plain res = {1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		y, x, 1.f};
	return res;
}
static inline mat3_plain mat3_plain_scale(float x, float y){
	mat3_plain res = {x, 0.f, 0.f,
		0.f, y, 0.f,
		0.f, 0.f, 1.f};
	return res;
}
static inline mat3_plain mat3_plain_transpose(mat3_plain a){
	mat3_plain res = {a.m11, a.m21, a.m31,
		a.m12, a.m22, a.m32,
		a.m13, a.m23, a.m33};
	return res;
}
static inline mat3_plain mat3_plain_swapRow(mat3_plain a, int R1, int R2){
	float tmp[3] = {a.mat2D[0][R1], a.mat2D[1][R1], a.mat2D[2][R1]};

	a.mat2D[0][R1] = a.mat2D[0][R2];
	a.mat2D[1][R1] = a.mat2D[1][R2];
	a.mat2D[2][R1] = a.mat2D[2][R2];

	a.mat2D[0][R2] = tmp[0];
	a.mat2D[1][R2] = tmp[1];
	a.mat2D[2][R2] = tmp[2];
	
	return a;
}
static inline mat3_plain mat3_plain_swapCol(mat3_plain a, int C1, int C2){
	float tmp[3] = {a.mat2D[C1][0], a.mat2D[C1][1], a.mat2D[C1][2]};

	a.mat2D[C1][0] = a.mat2D[C2][0];
	a.mat2D[C1][1] = a.mat2D[C2][1];
	a.mat2D[C1][2] = a.mat2D[C2][2];

	a.mat2D[C2][0] = tmp[0];
	a.mat2D[C2][1] = tmp[1];
	a.mat2D[C2][2] = tmp[2];
	
	return a;
}

static inline mat2_plain mat2_plain_set(float m0, float m1, float m2, float m3){
	mat2_plain res = {m0, m1, m2, m3};
	return res;
}
static inline mat2_plain mat2_plain_set1(float x){
	mat2_plain res = {m0, m1, m2, m3};
	return res;
}
static inline mat2_plain mat2_plain_add(mat2_plain a, mat2_plain b){
	a.mat[0] += b.mat[0];
	a.mat[0] += b.mat[0];
	a.mat[0] += b.mat[0];
	a.mat[0] += b.mat[0];
	return a;
}
static inline mat2_plain mat2_plain_sub(mat2_plain a, mat2_plain b){
	a.mat[0] -= b.mat[0];
	a.mat[0] -= b.mat[0];
	a.mat[0] -= b.mat[0];
	a.mat[0] -= b.mat[0];
	return a;
}
static inline mat2_plain mat2_plain_mul(mat2_plain a, mat2_plain b){
	mat2 res;

	res.mat[0] = a.m11*b.m11+a.m21*b.m12;
	res.mat[1] = a.m12*b.m11+a.m22*b.m12;

	res.mat[2] = a.m11*b.m21+a.m21*b.m22;
	res.mat[3] = a.m12*b.m21+a.m22*b.m22;

	return res;
}
static inline mat2_plain mat2_plain_addScal(mat2_plain a, float scalar){
	a.mat[0] += scalar;
	a.mat[0] += scalar;
	a.mat[0] += scalar;
	a.mat[0] += scalar;
	return a;
}
static inline mat2_plain mat2_plain_subScal(mat2_plain a, float scalar){
	a.mat[0] -= scalar;
	a.mat[0] -= scalar;
	a.mat[0] -= scalar;
	a.mat[0] -= scalar;
	return a;
}
static inline mat2_plain mat2_plain_mulScal(mat2_plain a, float scalar){
	a.mat[0] *= scalar;
	a.mat[0] *= scalar;
	a.mat[0] *= scalar;
	a.mat[0] *= scalar;
	return a;
}
static inline mat2_plain mat2_plain_divScal(mat2_plain a, float scalar){
	a.mat[0] /= scalar;
	a.mat[0] /= scalar;
	a.mat[0] /= scalar;
	a.mat[0] /= scalar;
	return a;
}
static inline mat2_plain mat2_plain_identity(void){
	mat2_plain res = {1.f, 0.f, 0.f, 1.f};
}
static inline mat2_plain mat2_plain_translate(float x){
	mat2_plain res = {1.f, 1.f, x, 1.f};
	return res;
}
static inline mat2_plain mat2_plain_scale(float x){
	mat2_plain res = {1.f, 0.f, 0.f, x};
	return res;
}
static inline mat2_plain mat2_plain_transpose(mat2_plain a){
	mat2_plain res = {a.m11, a.m21, a.m12, a.m22};
	return res;
}
static inline mat2_plain mat2_plain_swapRow(mat2_plain a){
	mat2_plain res = {a.m12, a.m11, a.m22, a.m21};
	return res;
}
static inline mat2_plain mat2_plain_swapCol(mat2_plain a){
	mat2_plain res = {a.m21, a.m22, a.m11, a.m12};
	return res;
}

/*
w = (aw*bw - ax*bx - ay*by - az*bz)
x = (aw*bx + ax*bw + ay*bz - az*by)
y = (aw*by - ax*bz + ay*bw + az*bx)
z = (aw*bz + ax*by - ay*bx + az*bw)
*/
static inline quaternion quat_mul(quaternion a, quaternion b){
	quaternion res = {a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z,
		a.w*b.w + a.x*b.w + a.y*b.z - a.z*b.y,
		a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,
		a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w
	};

	return res;
}

#ifdef __cplusplus
}
#endif

#endif /*__GLMC_PLAIN_H__*/
