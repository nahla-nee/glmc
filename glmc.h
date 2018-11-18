#ifndef GLMC_H
#define GLMC_H

#ifndef __cplusplus
#define GLMC_CAST(TYPE, DATA) (TYPE) DATA
#else
#define GLMC_CAST(TYPE, DATA) TYPE{DATA}
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <smmintrin.h>

typedef union vec2{
	__m128 vec;
	struct{
		float x, y;
	};
} vec2;

typedef union vec3{
	__m128 vec;
	struct{
		float x, y, z;
	};
	struct{
		float r, g, b;
	};
} vec3;

typedef union vec4{
	__m128 vec;
	struct{
		float x, y, z, w;
	};
	struct{
		float r, g, b, a;
	};
} vec4;

typedef union mat4{
	__m128 mat[4];
	float mat2D[4][4];
	float mat1D[16];
	struct{
		float m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15;
	};
} mat4;

//need padding in certain spots, floats need to be packed a certain way to use sse
typedef union mat3{
	__m128 mat[3];
	float mat2D[4][4];
	float mat1D[16];
	struct{
		float m0, m1, m2, pad1, m3, m4, m5, pad2, m6, m7, m8, pad3;
	};
} mat3;

typedef union mat2{
	__m128 mat;
	float mat2D[2][2];
	float mat1D[4];
	struct{
		float m0, m1, m2, m3;
	};
} mat2;

//vec2 function
static inline bool vec2_equal(__m128 a, __m128 b){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec2 tmp = GLMC_CAST(vec2, _mm_set1_ps(FLT_EPSILON));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y){
		return false;
	}
	return true;
}
static inline bool vec2_equal_eps(__m128 a, __m128 b, float epsilon){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec2 tmp = GLMC_CAST(vec2, _mm_set1_ps(epsilon));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y){
		return false;
	}
	return true;
}
static inline float vec2_len(__m128 a){
	vec2 tmp = GLMC_CAST(vec2, _mm_mul_ps(a, a));
	return sqrtf(tmp.x+tmp.y);
}
static inline __m128 vec2_norm(__m128 a){
	vec2 tmp = GLMC_CAST(vec2, _mm_mul_ps(a, a));
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.x+tmp.y)));
}
static inline float vec2_dot(__m128 a, __m128 b){
	vec2 tmp = GLMC_CAST(vec2, _mm_mul_ps(a, b));
	return (tmp.x + tmp.y);
}
static inline __m128 vec2_set(float x, float y){
	return _mm_set_ps(0.f, 0.f, y, x);
}
static inline __m128 vec2_mulMat(__m128 a, mat2 b){
	vec2 vec = GLMC_CAST(vec2, a);
	__m128 res = _mm_mul_ps(b.mat, _mm_set_ps(vec.y, vec.y, vec.x, vec.x));
	return _mm_add_ps(res, _mm_movehl_ps(res, res));
}

//vec3 functions
static inline bool vec3_equal(__m128 a, __m128 b){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec3 tmp = GLMC_CAST(vec3, _mm_set1_ps(FLT_EPSILON));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z){
		return false;
	}
	return true;
}
static inline bool vec3_equal_eps(__m128 a, __m128 b, float epsilon){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec3 tmp = GLMC_CAST(vec3, _mm_set1_ps(epsilon));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z){
		return false;
	}
	return true;
}
static inline float vec3_len(__m128 a){
	vec3 tmp = GLMC_CAST(vec3, _mm_mul_ps(a, a));
	return sqrtf(tmp.x+tmp.y+tmp.z);
}
static inline __m128 vec3_norm(__m128 a){
	vec3 tmp = GLMC_CAST(vec3, _mm_mul_ps(a, a));
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.x+tmp.y+tmp.z)));
}
static inline float vec3_dot(__m128 a, __m128 b){
	vec3 tmp = GLMC_CAST(vec3, _mm_mul_ps(a, b));
	return (tmp.x+tmp.y+tmp.z);
}
static inline __m128 vec3_set(float x, float y, float z){
	return _mm_set_ps(0.f, z, y, x);
}
static inline __m128 vec3_mulMat(__m128 a, mat3 b){
	vec4 tmp = GLMC_CAST(vec4, a);
	__m128 res = _mm_mul_ps(b.mat[0], _mm_set1_ps(tmp.x));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[1], _mm_set1_ps(tmp.y)));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[2], _mm_set1_ps(tmp.z)));
	return res;
}

//vec4 functions
static inline bool vec4_equal(__m128 a, __m128 b){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec4 tmp = GLMC_CAST(vec4, _mm_set1_ps(FLT_EPSILON));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}
static inline bool vec4_equal_eps(__m128 a, __m128 b, float epsilon){
	a = _mm_sub_ps(a, b);
	a = _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
	vec4 tmp = GLMC_CAST(vec4, _mm_set1_ps(epsilon));
	tmp.vec = _mm_cmpgt_ps(a, tmp.vec);
	if((int)tmp.x || (int)tmp.y || (int)tmp.z || (int)tmp.w){
		return false;
	}
	return true;
}
static inline float vec4_len(__m128 a){
	vec4 tmp = GLMC_CAST(vec4, _mm_mul_ps(a, a));
	return sqrtf(tmp.x+tmp.y+tmp.z+tmp.w);
}
static inline __m128 vec4_norm(__m128 a){
	vec4 tmp = GLMC_CAST(vec4, _mm_mul_ps(a, a));
	return _mm_div_ps(a, _mm_set1_ps(sqrtf(tmp.x+tmp.y+tmp.z+tmp.w)));
}
static inline float vec4_dot(__m128 a, __m128 b){
	vec4 tmp = GLMC_CAST(vec4, _mm_mul_ps(a, b));
	return (tmp.x+tmp.y+tmp.z+tmp.w);
}
static inline __m128 vec4_set(float x, float y, float z, float w){
	return _mm_set_ps(w, z, y, x);
}
static inline __m128 vec4_mulMat(__m128 a, mat4 b){
	vec4 tmp = GLMC_CAST(vec4, a);
	__m128 res = _mm_mul_ps(b.mat[0], _mm_set1_ps(tmp.x));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[1], _mm_set1_ps(tmp.y)));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[2], _mm_set1_ps(tmp.z)));
	res = _mm_add_ps(res, _mm_mul_ps(b.mat[3], _mm_set1_ps(tmp.w)));
	return res;
}

//and these work for all of them!
static inline __m128 vec_set1(float x){
	return _mm_set1_ps(x);
}
static inline __m128 vec_add(__m128 a, __m128 b){
	return _mm_add_ps(a, b);
}
static inline __m128 vec_sub(__m128 a, __m128 b){
	return _mm_sub_ps(a, b);
}
static inline __m128 vec_mul(__m128 a, __m128 b){
	return _mm_mul_ps(a, b);
}
static inline __m128 vec_div(__m128 a, __m128 b){
	return _mm_div_ps(a, b);
}
static inline __m128 vec_addScal(__m128 a, float scalar){
	return _mm_add_ps(a, _mm_set1_ps(scalar));
}
static inline __m128 vec_subScal(__m128 a, float scalar){
	return _mm_sub_ps(a, _mm_set1_ps(scalar));
}
static inline __m128 vec_mulScal(__m128 a, float scalar){
	return _mm_mul_ps(a, _mm_set1_ps(scalar));
}
static inline __m128 vec_divScal(__m128 a, float scalar){
	return _mm_div_ps(a, _mm_set1_ps(scalar));
}
static inline __m128 vec_abs(__m128 a){
	return _mm_and_ps(a, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
}
static inline __m128 vec_ceil(__m128 a){
	return _mm_ceil_ps(a);
}
static inline __m128 vec_floor(__m128 a){
	return _mm_floor_ps(a);
}
static inline __m128 vec_round(__m128 a){
	return _mm_round_ps(a, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}

//matrix function
static inline mat4 mat4_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15){
	mat4 res;
	res.mat[0] = _mm_set_ps(m3, m2, m1, m0);
	res.mat[1] = _mm_set_ps(m7, m6, m5, m4);
	res.mat[2] = _mm_set_ps(m11, m10, m9, m8);
	res.mat[3] = _mm_set_ps(m15, m14, m13, m12);
	return res;
}
static inline mat4 mat4_set1(float x){
	mat4 res;
	res.mat[0] = _mm_set1_ps(x);
	res.mat[1] = res.mat[0];
	res.mat[2] = res.mat[0];
	res.mat[3] = res.mat[0];
	return res;
}
static inline mat4 mat4_add(mat4 a, mat4 b){
	a.mat[0] = _mm_add_ps(a.mat[0], b.mat[0]);
	a.mat[1] = _mm_add_ps(a.mat[1], b.mat[1]);
	a.mat[2] = _mm_add_ps(a.mat[2], b.mat[2]);
	a.mat[3] = _mm_add_ps(a.mat[3], b.mat[3]);
	return a;
}
static inline mat4 mat4_sub(mat4 a, mat4 b){
	a.mat[0] = _mm_sub_ps(a.mat[0], b.mat[0]);
	a.mat[1] = _mm_sub_ps(a.mat[1], b.mat[1]);
	a.mat[2] = _mm_sub_ps(a.mat[2], b.mat[2]);
	a.mat[3] = _mm_sub_ps(a.mat[3], b.mat[3]);
	return a;
}
//thanks harold!
static inline mat4 mat4_mul(mat4 a, mat4 b){
	mat4 res;
	__m128 t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[0][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[0][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[0][2])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[3], _mm_set1_ps(b.mat2D[0][3])));
	res.mat[0] = t;
	t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[1][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[1][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[1][2])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[3], _mm_set1_ps(b.mat2D[1][3])));
	res.mat[1] = t;
	t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[2][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[2][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[2][2])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[3], _mm_set1_ps(b.mat2D[2][3])));
	res.mat[2] = t;
	t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[3][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[3][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[3][2])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[3], _mm_set1_ps(b.mat2D[3][3])));
	res.mat[3] = t;
	return res;
}
static inline mat4 mat4_addScal(mat4 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_add_ps(a.mat[0], scal);
	a.mat[1] = _mm_add_ps(a.mat[1], scal);
	a.mat[2] = _mm_add_ps(a.mat[2], scal);
	a.mat[3] = _mm_add_ps(a.mat[3], scal);
	return a;
}
static inline mat4 mat4_subScal(mat4 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_sub_ps(a.mat[0], scal);
	a.mat[1] = _mm_sub_ps(a.mat[1], scal);
	a.mat[2] = _mm_sub_ps(a.mat[2], scal);
	a.mat[3] = _mm_sub_ps(a.mat[3], scal);
	return a;
}
static inline mat4 mat4_mulScal(mat4 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_mul_ps(a.mat[0], scal);
	a.mat[1] = _mm_mul_ps(a.mat[1], scal);
	a.mat[2] = _mm_mul_ps(a.mat[2], scal);
	a.mat[3] = _mm_mul_ps(a.mat[3], scal);
	return a;
}
static inline mat4 mat4_divScal(mat4 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_div_ps(a.mat[0], scal);
	a.mat[1] = _mm_div_ps(a.mat[1], scal);
	a.mat[2] = _mm_div_ps(a.mat[2], scal);
	a.mat[3] = _mm_div_ps(a.mat[3], scal);
	return a;
}
static inline mat4 mat4_identity(void){
	mat4 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, 0.f, 0.f);
	res.mat[3] = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return res;
}
static inline mat4 mat4_translate(float x, float y, float z){
	mat4 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, 0.f, 0.f);
	res.mat[3] = _mm_set_ps(1.f, z, y, x);
	return res;
}
static inline mat4 mat4_scale(float x, float y, float z){
	mat4 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, x);
	res.mat[1] = _mm_set_ps(0.f, 0.f, y, 0.f);
	res.mat[2] = _mm_set_ps(0.f, z, 0.f, 0.f);
	res.mat[3] = _mm_set_ps(1.f, 0.f, 0.f, 0.f);
	return res;
}
static inline mat4 mat4_transpose(mat4 a){
	_MM_TRANSPOSE4_PS(a.mat[0], a.mat[1], a.mat[2], a.mat[3]);
	return a;
}
static inline mat4 mat4_swapRow(mat4 a, int R1, int R2){
	vec4 tmp = GLMC_CAST(vec4, _mm_set_ps(a.mat[3][R1], a.mat[2][R1], a.mat[1][R1], a.mat[0][R1]));
	a.mat2D[3][R1] = a.mat2D[3][R2];
	a.mat2D[2][R1] = a.mat2D[2][R2];
	a.mat2D[1][R1] = a.mat2D[1][R2];
	a.mat2D[0][R1] = a.mat2D[0][R2];

	a.mat2D[3][R2] = tmp.w;
	a.mat2D[2][R2] = tmp.z;
	a.mat2D[1][R2] = tmp.y;
	a.mat2D[0][R2] = tmp.x;
	return a;
}
static inline mat4 mat4_swapCol(mat4 a, int C1, int C2){
	__m128 tmp = a.mat[C1];
	a.mat[C1] = a.mat[C2];
	a.mat[C2] = tmp;
	return a;
}

static inline mat3 mat3_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, m2, m1, m0);
	res.mat[1] = _mm_set_ps(0.f, m5, m4, m3);
	res.mat[2] = _mm_set_ps(0.f, m8, m7, m6);
	return res;
}
static inline mat3 mat3_set1(float x){
	mat3 res;
	res.mat[0] = _mm_set1_ps(x);
	res.mat[1] = res.mat[0];
	res.mat[2] = res.mat[0];
	return res;
}
static inline mat3 mat3_add(mat3 a, mat3 b){
	a.mat[0] = _mm_add_ps(a.mat[0], b.mat[0]);
	a.mat[1] = _mm_add_ps(a.mat[1], b.mat[1]);
	a.mat[2] = _mm_add_ps(a.mat[2], b.mat[2]);
	return a;
}
static inline mat3 mat3_sub(mat3 a, mat3 b){
	a.mat[0] = _mm_sub_ps(a.mat[0], b.mat[0]);
	a.mat[1] = _mm_sub_ps(a.mat[1], b.mat[1]);
	a.mat[2] = _mm_sub_ps(a.mat[2], b.mat[2]);
	return a;
}
static inline mat3 mat3_mul(mat3 a, mat3 b){
	mat3 res;
	__m128 t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[0][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[0][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[0][2])));
	res.mat[0] = t;
	t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[1][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[1][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[1][2])));
	res.mat[1] = t;
	t = _mm_mul_ps(a.mat[0], _mm_set1_ps(b.mat[2][0]));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[1], _mm_set1_ps(b.mat2D[2][1])));
	t = _mm_add_ps(t, _mm_mul_ps(a.mat[2], _mm_set1_ps(b.mat2D[2][2])));
	res.mat[2] = t;
	return res;
}
static inline mat3 mat3_addScal(mat3 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_add_ps(a.mat[0], scal);
	a.mat[1] = _mm_add_ps(a.mat[1], scal);
	a.mat[2] = _mm_add_ps(a.mat[2], scal);
	return a;
}
static inline mat3 mat3_subScal(mat3 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_sub_ps(a.mat[0], scal);
	a.mat[1] = _mm_sub_ps(a.mat[1], scal);
	a.mat[2] = _mm_sub_ps(a.mat[2], scal);
	return a;
}
static inline mat3 mat3_mulScal(mat3 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_mul_ps(a.mat[0], scal);
	a.mat[1] = _mm_mul_ps(a.mat[1], scal);
	a.mat[2] = _mm_mul_ps(a.mat[2], scal);
	return a;
}
static inline mat3 mat3_divScal(mat3 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_div_ps(a.mat[0], scal);
	a.mat[1] = _mm_div_ps(a.mat[1], scal);
	a.mat[2] = _mm_div_ps(a.mat[2], scal);
	return a;
}
static inline mat3 mat3_identity(void){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, 0.f, 0.f);
	return res;
}
static inline mat3 mat3_translate(float x, float y){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, y, x);

	return res;
}
static inline mat3 mat3_scale(float x, float y){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, x);
	res.mat[1] = _mm_set_ps(0.f, 0.f, y, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, 0.f, 0.f);

	return res;
}
static inline mat3 mat3_transpose(mat3 a){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, a.m6, a.m3, a.m0);
	res.mat[1] = _mm_set_ps(0.f, a.m7, a.m4, a.m1);
	res.mat[2] = _mm_set_ps(0.f, a.m8, a.m5, a.m2);

	return res;
}
static inline mat3 mat3_swapRow(mat3 a, int R1, int R2){
	vec3 tmp = GLMC_CAST(vec3, _mm_set_ps(0.f, a.mat[2][R1], a.mat[1][R1], a.mat[0][R1]));
	a.mat2D[2][R1] = a.mat2D[2][R2];
	a.mat2D[1][R1] = a.mat2D[1][R2];
	a.mat2D[0][R1] = a.mat2D[0][R2];

	a.mat2D[2][R2] = tmp.z;
	a.mat2D[1][R2] = tmp.y;
	a.mat2D[0][R2] = tmp.x;

	return a;
}
static inline mat3 mat3_swapCol(mat3 a, int C1, int C2){
	__m128 tmp = a.mat[0];
	a.mat[0] = a.mat[1];
	a.mat[1] = tmp;
	return a;
}

static inline mat2 mat2_set(float m0, float m1, float m2, float m3){
	return GLMC_CAST(mat2, _mm_set_ps(m3, m2, m1, m0));
}
static inline mat2 mat2_set1(float x){
	return GLMC_CAST(mat2, _mm_set1_ps(x));
}
static inline mat2 mat2_add(mat2 a, mat2 b){
	return GLMC_CAST(mat2, _mm_add_ps(a.mat, b.mat));
}
static inline mat2 mat2_sub(mat2 a, mat2 b){
	return GLMC_CAST(mat2, _mm_sub_ps(a.mat, b.mat));
}
static inline mat2 mat2_mul(mat2 a, mat2 b){
	__m128 lhs1 = _mm_set_ps(a.m1, a.m0, a.m1, a.m0);
	__m128 lhs2 = _mm_set_ps(a.m2, a.m2, a.m0, a.m0);
	__m128 rhs1 = _mm_set_ps(a.m3, a.m2, a.m3, a.m2);
	__m128 rhs2 = _mm_set_ps(a.m3, a.m3, a.m1, a.m1);
	return GLMC_CAST(mat2, _mm_add_ps(_mm_mul_ps(lhs1, lhs2), _mm_mul_ps(rhs1, rhs2)));
}
static inline mat2 mat2_addScal(mat2 a, float scalar){
	return GLMC_CAST(mat2, _mm_add_ps(a.mat, _mm_set1_ps(scalar)));
}
static inline mat2 mat2_subScal(mat2 a, float scalar){
	return GLMC_CAST(mat2, _mm_sub_ps(a.mat, _mm_set1_ps(scalar)));
}
static inline mat2 mat2_mulScal(mat2 a, float scalar){
	return GLMC_CAST(mat2, _mm_mul_ps(a.mat, _mm_set1_ps(scalar)));
}
static inline mat2 mat2_divScal(mat2 a, float scalar){
	return GLMC_CAST(mat2, _mm_div_ps(a.mat, _mm_set1_ps(scalar)));
}
static inline mat2 mat2_identity(void){
	return GLMC_CAST(mat2, _mm_set_ps(1.f, 0.f, 0.f, 1.f));
}
static inline mat2 mat2_translate(float x){
	return GLMC_CAST(mat2, _mm_set_ps(1.f, x, 0.f, 1.f));
}
static inline mat2 mat2_scale(float x){
	return GLMC_CAST(mat2, _mm_set_ps(x, 0.f, 0.f, 1.f));
}
static inline mat2 mat2_transpose(mat2 a){
	return GLMC_CAST(mat2, _mm_shuffle_ps(a.mat, a.mat, 0xd8));
}
static inline mat2 mat2_swapRow(mat2 a){
	return GLMC_CAST(mat2, _mm_shuffle_ps(a.mat, a.mat, 0xb1));
}
static inline mat2 mat2_swapCol(mat2 a){
	return GLMC_CAST(mat2, _mm_shuffle_ps(a.mat, a.mat, 0x4e));
}

#ifdef __cplusplus
}
#endif

#endif /*GLMC_H*/
