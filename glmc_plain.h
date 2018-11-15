#ifndef __GLMC_PLAIN_H__
#define __GLMC_PLAIN_H__

//non SSE version of glmc!
//you really shouldn't use this, literally every CPU supports SSE

#ifdef __cplusplus
extern "C"{
#endif

#include <math.h>
#include <float.h>
#include <bool.h>

#define VEC2_EPSILON FLT_EPSILON*2
#define VEC3_EPSILON FLT_EPSILON*3
#define VEC4_EPSILON FLT_EPSILON*4

typedef union vec2{
	float vec[2];
	struct{
		float x, y;
	};
} vec2;

typedef union vec3{
	float vec[3];
	struct{
		float x, y, z;
	};
	struct{
		float r, g, b;
	};
} vec3;

typedef union vec4{
	float vec[4];
	struct{
		float x, y, z, w;
	};
	struct{
		float r, g, b, a;
	};
} vec4;

typedef union mat4{
	float mat[16];
	float mat2D[4][4];
	struct{
		float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
	};
} mat4;

typedef union mat3{
	float mat[9];
	float mat2D[3][3];
	struct{
		float m11, m12, m13, m21, m22, m23, m31, m32, m33;
	};
} mat3;

typedef union mat2{
	float mat[4];
	float mat2D[2][2];
	struct{
		float m11, m12, m21, m22;
	};
} mat2;

static inline float vec2_len(vec2 a){
	return sqrtf(a.x*a.x+a.y*a.y);
}
static inline vec2 vec2_norm(vec2 a){
	float len = sqrtf(a.x*a.x+a.y*a.y);
	a.x /= len;
	a.y /= len;
	return a;
}
static inline vec2 vec2_set(float x, float y){
	vec2 res = {x, y, 0.0f, 0.0f};
	return res;
}
static inline vec2 vec2_set1(float x){
	vec2 res = {x, x, 0.0f, 0.0f};
	return res;
}
static inline vec2 vec2_add(vec2 a, vec2 b){
	a.x += b.x;
	a.y += b.y;
	return a;
}
static inline vec2 vec2_sub(vec2 a, vec2 b){
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
static inline vec2 vec2_mul(vec2 a, vec2 b){
	a.x *= b.x;
	a.y *= b.y;
	return a;
}
static inline vec2 vec2_div(vec2 a, vec2 b){
	a.x /= b.x;
	a.y /= b.y;
	return a;
}
static inline vec2 vec2_addScal(vec2 a, float scalar){
	a.x += scalar;
	a.y += scalar;
	return a;
}
static inline vec2 vec2_subScal(vec2 a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	return a;
}
static inline vec2 vec2_mulScal(vec2 a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	return a;
}
static inline vec2 vec2_divScal(vec2 a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	return a;
}
static inline float vec2_dot(vec2 a, vec2 b){
	return a.x*b.x+a.y*b.y;
}
static inline vec2 vec2_abs(vec2 a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	return a;
}
static inline vec2 vec2_ceil(vec2 a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	return a;
}
static inline vec2 vec2_floor(vec2 a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	return a;
}
static inline vec2 vec2_round(vec2 a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	return a;
}
static inline vec2 vec2_mulMat(vec2 a, mat2 b){
	vec2 res;

	res.vec[0] = a.x*b.m11+a.y*b.m21+a.z*b.m31;
	res.vec[1] = a.x*b.m12+a.y*b.m22+a.z*b.m32;
	res.vec[2] = a.x*b.m13+a.y*b.m23+a.z*b.m33;

	return res;
}

//vec3 functions
static inline float vec3_len(vec3 a){
	return sqrtf(a.x*a.x+a.y*a.y+a.z*a.z);
}
static inline vec3 vec3_norm(vec3 a){
	float len = sqrtf(a.x*a.x+a.y*a.y+a.z*a.z);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return a;
}
static inline vec3 vec3_set(float x, float y, float z){
	vec3 res = {x, y, z, 0.0f};
	return res;
}
static inline vec3 vec3_set1(float x){
	vec3 res = {x, x, x, 0.0f};
	return res;
}
static inline vec3 vec3_add(vec3 a, vec3 b){
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}
static inline vec3 vec3_sub(vec3 a, vec3 b){
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}
static inline vec3 vec3_mul(vec3 a, vec3 b){
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return a;
}
static inline vec3 vec3_div(vec3 a, vec3 b){
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return a;
}
static inline vec3 vec3_addScal(vec3 a, float scalar){
	a.x += scalar;
	a.y += scalar;
	a.z += scalar;
	return a;
}
static inline vec3 vec3_subScal(vec3 a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	a.z -= scalar;
	return a;
}
static inline vec3 vec3_mulScal(vec3 a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	return a;
}
static inline vec3 vec3_divScal(vec3 a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	a.z /= scalar;
	return a;
}
static inline float vec3_dot(vec3 a, vec3 b){
	return (a.x*b.x+a.y*b.y+a.z*b.z);
}
static inline vec3 vec3_abs(vec3 a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	a.z = fabs(a.z);
	return a;
}
static inline vec3 vec3_ceil(vec3 a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	a.z = ceilf(a.z);
	return a;
}
static inline vec3 vec3_floor(vec3 a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	a.z = floorf(a.z);
	return a;
}
static inline vec3 vec3_round(vec3 a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	a.z = roundf(a.z);
	return a;
}
static inline vec3 vec3_mulMat(vec3 a, mat3 b){
	vec3 res;

	res.vec[0] = a.x*b.m11+a.y*b.m21+a.z*b.m31;
	res.vec[1] = a.x*b.m12+a.y*b.m22+a.z*b.m32;
	res.vec[2] = a.x*b.m13+a.y*b.m23+a.z*b.m33;

	return res;
}

//vec4 functions
static inline float vec4_len(vec4 a){
	return sqrtf(a.x*a.x+a.y*a.y+a.z*a.z+a.w*a.w);
}
static inline vec4 vec4_norm(vec4 a){
	float len = sqrtf(a.x*a.x+a.y*a.y+a.z*a.z+a.w*a.w);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	a.w /= len;
	return a;
}
static inline vec4 vec4_set(float x, float y, float z, float w){
	vec4 res = {x, y, z, w};
	return res;
}
static inline vec4 vec4_set1(float x){
	vec4 res = {x, x, x, x};
	return res;
}
static inline vec4 vec4_add(vec4 a, vec4 b){
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return a;
}
static inline vec4 vec4_sub(vec4 a, vec4 b){
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return a;
}
static inline vec4 vec4_mul(vec4 a, vec4 b){
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return a;
}
static inline vec4 vec4_div(vec4 a, vec4 b){
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	a.w /= b.w;
	return a;
}
static inline vec4 vec4_addScal(vec4 a, float scalar){
	a.x += scalar;
	a.y += scalar;
	a.z += scalar;
	a.w += scalar;
	return a;
}
static inline vec4 vec4_subScal(vec4 a, float scalar){
	a.x -= scalar;
	a.y -= scalar;
	a.z -= scalar;
	a.w -= scalar;
	return a;
}
static inline vec4 vec4_mulScal(vec4 a, float scalar){
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	a.w *= scalar;
	return a;
}
static inline vec4 vec4_divScal(vec4 a, float scalar){
	a.x /= scalar;
	a.y /= scalar;
	a.z /= scalar;
	a.w /= scalar;
	return a;
}
static inline float vec4_dot(vec4 a, vec4 b){
	return (a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w);
}
static inline vec4 vec4_abs(vec4 a){
	a.x = fabs(a.x);
	a.y = fabs(a.y);
	a.z = fabs(a.z);
	a.w = fabs(a.w);
	return a;
}
static inline vec4 vec4_ceil(vec4 a){
	a.x = ceilf(a.x);
	a.y = ceilf(a.y);
	a.z = ceilf(a.z);
	a.w = ceilf(a.w);
	return a;
}
static inline vec4 vec4_floor(vec4 a){
	a.x = floorf(a.x);
	a.y = floorf(a.y);
	a.z = floorf(a.z);
	a.w = floorf(a.w);
	return a;
}
static inline vec4 vec4_round(vec4 a){
	a.x = roundf(a.x);
	a.y = roundf(a.y);
	a.z = roundf(a.z);
	a.w = roundf(a.w);
	return a;
}
static inline vec4 vec4_mulMat(vec4 a, mat4 b){
	vec4 res;

	res.vec[0] = a.x*b.m11+a.y*b.m21+a.z*b.m31+a.w*b.m41;
	res.vec[1] = a.x*b.m12+a.y*b.m22+a.z*b.m32+a.w*b.m42;
	res.vec[2] = a.x*b.m13+a.y*b.m23+a.z*b.m33+a.w*b.m43;
	res.vec[3] = a.x*b.m14+a.y*b.m24+a.z*b.m34+a.w*b.m44;

	return res;
}

static inline mat4 mat4_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15){
	mat4 a = {m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15};
	return a;
}
static inline mat4 mat4_set1(float x){
	mat4 a = {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x};
	return a;
}
static inline mat4 mat4_add(mat4 a, mat4 b){
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
static inline mat4 mat4_sub(mat4 a, mat4 b){
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
static inline mat4 mat4_mul(mat4 a, mat4 b){
	mat4 res;
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
static inline mat4 mat4_addScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
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
static inline mat4 mat4_subScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
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
static inline mat4 mat4_mulScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
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
static inline mat4 mat4_divScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
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
static inline mat4 mat4_identity(void){
	mat4 a = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	return a;
}
static inline mat4 mat4_translate(float x, float y, float z){
	mat4 a = {1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		x, y, z, 1.f};
	return a;
}
static inline mat4 mat4_scale(float x, float y, float z){
	mat4 a = {x, 0.0f, 0.0f, 0.0f,
		0.0f, y, 0.0f, 0.0f,
		0.0f, 0.0f, z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.f};
	return a;
}
static inline mat4 mat4_transpose(mat4 a){
	//way faster to just use another matrix instead of a bunch of subtitutions
	mat4 res = {a.m11, a.m21, a.m31, a.m41,
		a.m12, a.m22, a.m32, a.m42,
		a.m13, a.m23, a.m33, a.m34,
		a.m14, a.m24, a.m34, a.m44};
	return res;
}
static inline mat4 mat4_swapRow(mat4 a, int R1, int R2){
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
static inline mat4 mat4_swapCol(mat4 a, int C1, int C2){
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

static inline mat3 mat3_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8){
	mat3 res = {m0, m1, m2, m3, m4, m5, m6, m7, m8};
	return res;
}
static inline mat3 mat3_set1(float x){
	mat3 res = {x, x, x, x, x, x, x, x, x};
	return res;
}
static inline mat3 mat3_add(mat3 a, mat3 b){
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
static inline mat3 mat3_sub(mat3 a, mat3 b){
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
static inline mat3 mat3_mul(mat3 a, mat3 b){
	mat3 res;

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
static inline mat3 mat3_addScal(mat3 a, float scalar){
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
static inline mat3 mat3_subScal(mat3 a, float scalar){
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
static inline mat3 mat3_mulScal(mat3 a, float scalar){
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
static inline mat3 mat3_divScal(mat3 a, float scalar){
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
static inline mat3 mat3_identity(void){
	mat3 res = {1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 0.f, 1.f};
	return res;
}
static inline mat3 mat3_translate(float x, float y){
	mat3 res = {1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		y, x, 1.f};
	return res;
}
static inline mat3 mat3_scale(float x, float y){
	mat3 res = {x, 0.f, 0.f,
		0.f, y, 0.f,
		0.f, 0.f, 1.f};
	return res;
}
static inline mat3 mat3_transpose(mat3 a){
	mat3 res = {a.m11, a.m21, a.m31,
		a.m12, a.m22, a.m32,
		a.m13, a.m23, a.m33};
	return res;
}
static inline mat3 mat3_swapRow(mat3 a, int R1, int R2){
	float tmp[3] = {a.mat2D[0][R1], a.mat2D[1][R1], a.mat2D[2][R1]};

	a.mat2D[0][R1] = a.mat2D[0][R2];
	a.mat2D[1][R1] = a.mat2D[1][R2];
	a.mat2D[2][R1] = a.mat2D[2][R2];

	a.mat2D[0][R2] = tmp[0];
	a.mat2D[1][R2] = tmp[1];
	a.mat2D[2][R2] = tmp[2];
	
	return a;
}
static inline mat3 mat3_swapCol(mat3 a, int C1, int C2){
	float tmp[3] = {a.mat2D[C1][0], a.mat2D[C1][1], a.mat2D[C1][2]};

	a.mat2D[C1][0] = a.mat2D[C2][0];
	a.mat2D[C1][1] = a.mat2D[C2][1];
	a.mat2D[C1][2] = a.mat2D[C2][2];

	a.mat2D[C2][0] = tmp[0];
	a.mat2D[C2][1] = tmp[1];
	a.mat2D[C2][2] = tmp[2];
	
	return a;
}

static inline mat2 mat2_set(float m0, float m1, float m2, float m3){
	mat2 res = {m0, m1, m2, m3};
	return res;
}
static inline mat2 mat2_set1(float x){
	mat2 res = {m0, m1, m2, m3};
	return res;
}
static inline mat2 mat2_add(mat2 a, mat2 b){
	a.mat[0] += b.mat[0];
	a.mat[0] += b.mat[0];
	a.mat[0] += b.mat[0];
	a.mat[0] += b.mat[0];
	return a;
}
static inline mat2 mat2_sub(mat2 a, mat2 b){
	a.mat[0] -= b.mat[0];
	a.mat[0] -= b.mat[0];
	a.mat[0] -= b.mat[0];
	a.mat[0] -= b.mat[0];
	return a;
}
static inline mat2 mat2_mul(mat2 a, mat2 b){
	mat2 res;

	res.mat[0] = a.m11*b.m11+a.m21*b.m12;
	res.mat[1] = a.m12*b.m11+a.m22*b.m12;

	res.mat[2] = a.m11*b.m21+a.m21*b.m22;
	res.mat[3] = a.m12*b.m21+a.m22*b.m22;

	return res;
}
static inline mat2 mat2_addScal(mat2 a, float scalar){
	a.mat[0] += scalar;
	a.mat[0] += scalar;
	a.mat[0] += scalar;
	a.mat[0] += scalar;
	return a;
}
static inline mat2 mat2_subScal(mat2 a, float scalar){
	a.mat[0] -= scalar;
	a.mat[0] -= scalar;
	a.mat[0] -= scalar;
	a.mat[0] -= scalar;
	return a;
}
static inline mat2 mat2_mulScal(mat2 a, float scalar){
	a.mat[0] *= scalar;
	a.mat[0] *= scalar;
	a.mat[0] *= scalar;
	a.mat[0] *= scalar;
	return a;
}
static inline mat2 mat2_divScal(mat2 a, float scalar){
	a.mat[0] /= scalar;
	a.mat[0] /= scalar;
	a.mat[0] /= scalar;
	a.mat[0] /= scalar;
	return a;
}
static inline mat2 mat2_identity(void){
	mat2 res = {1.f, 0.f, 0.f, 1.f};
}
static inline mat2 mat2_translate(float x){
	mat2 res = {1.f, 1.f, x, 1.f};
	return res;
}
static inline mat2 mat2_scale(float x){
	mat2 res = {1.f, 0.f, 0.f, x};
	return res;
}
static inline mat2 mat2_transpose(mat2 a){
	mat2 res = {a.m11, a.m21, a.m12, a.m22};
	return res;
}
static inline mat2 mat2_swapRow(mat2 a){
	mat2 res = {a.m12, a.m11, a.m22, a.m21};
	return res;
}
static inline mat2 mat2_swapCol(mat2 a){
	mat2 res = {a.m21, a.m22, a.m11, a.m12};
	return res;
}

#ifdef __cplusplus
}
#endif

#endif /*__GLMC_PLAIN_H__*/
