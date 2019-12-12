#include "matrix/mat4.h"

mat4 mat4_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6,
	float m7, float m8, float m9, float m10, float m11, float m12, float m13,
	float m14, float m15){

	mat4 a = {m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m0, m1, m2, m3, m15};
	return a;
}

mat4 mat4_set1(float x){
	mat4 a = {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x};
	return a;
}

mat4 mat4_add(mat4 a, mat4 b){
	a.m0 = a.m0+b.m0;
	a.m1 = a.m1+b.m1;
	a.m2 = a.m2+b.m2;
	a.m3 = a.m3+b.m3;
	a.m4 = a.m4+b.m4;
	a.m5 = a.m5+b.m5;
	a.m6 = a.m6+b.m6;
	a.m7 = a.m7+b.m7;
	a.m8 = a.m8+b.m8;
	a.m9 = a.m9+b.m9;
	a.m10 = a.m10+b.m10;
	a.m11 = a.m11+b.m11;
	a.m12 = a.m12+b.m12;
	a.m13 = a.m13+b.m13;
	a.m14 = a.m14+b.m14;
	a.m15 = a.m15+b.m15;
	return a;
}

mat4 mat4_sub(mat4 a, mat4 b){
	a.m0 = a.m0-b.m0;
	a.m1 = a.m1-b.m1;
	a.m2 = a.m2-b.m2;
	a.m3 = a.m3-b.m3;
	a.m4 = a.m4-b.m4;
	a.m5 = a.m5-b.m5;
	a.m6 = a.m6-b.m6;
	a.m7 = a.m7-b.m7;
	a.m8 = a.m8-b.m8;
	a.m9 = a.m9-b.m9;
	a.m10 = a.m10-b.m10;
	a.m11 = a.m11-b.m11;
	a.m12 = a.m12-b.m12;
	a.m13 = a.m13-b.m13;
	a.m14 = a.m14-b.m14;
	a.m15 = a.m15-b.m15;
	return a;
}

mat4 mat4_mul(mat4 a, mat4 b){
	mat4 res;
	res.m0 = a.m0*b.m0+a.m4*b.m1+a.m8*b.m2+a.m12*b.m3;
	res.m1 = a.m1*b.m0+a.m5*b.m1+a.m9*b.m2+a.m13*b.m3;
	res.m2 = a.m2*b.m0+a.m6*b.m1+a.m10*b.m2+a.m14*b.m3;
	res.m3 = a.m3*b.m0+a.m7*b.m1+a.m11*b.m2+a.m15*b.m3;

	res.m4 = a.m0*b.m4+a.m4*b.m5+a.m8*b.m6+a.m12*b.m7;
	res.m5 = a.m1*b.m4+a.m5*b.m5+a.m9*b.m6+a.m13*b.m7;
	res.m6 = a.m2*b.m4+a.m6*b.m5+a.m10*b.m6+a.m14*b.m7;
	res.m7 = a.m3*b.m4+a.m7*b.m5+a.m11*b.m6+a.m15*b.m7;

	res.m8 = a.m0*b.m8+a.m4*b.m9+a.m8*b.m10+a.m12*b.m11;
	res.m9 = a.m1*b.m8+a.m5*b.m9+a.m9*b.m10+a.m13*b.m11;
	res.m10 = a.m2*b.m8+a.m6*b.m9+a.m10*b.m10+a.m14*b.m11;
	res.m11 = a.m3*b.m8+a.m7*b.m9+a.m11*b.m10+a.m15*b.m11;

	res.m12 = a.m0*b.m12+a.m4*b.m13+a.m8*b.m14+a.m12*b.m15;
	res.m13 = a.m1*b.m12+a.m5*b.m13+a.m9*b.m14+a.m13*b.m15;
	res.m14 = a.m2*b.m12+a.m6*b.m13+a.m10*b.m14+a.m14*b.m15;
	res.m15 = a.m3*b.m12+a.m7*b.m13+a.m11*b.m14+a.m15*b.m15;
	return a;
}

mat4 mat4_addScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.m0 = a.m0+scal.m0;
	a.m1 = a.m1+scal.m1;
	a.m2 = a.m2+scal.m2;
	a.m3 = a.m3+scal.m3;
	a.m4 = a.m4+scal.m4;
	a.m5 = a.m5+scal.m5;
	a.m6 = a.m6+scal.m6;
	a.m7 = a.m7+scal.m7;
	a.m8 = a.m8+scal.m8;
	a.m9 = a.m9+scal.m9;
	a.m10 = a.m10+scal.m10;
	a.m11 = a.m11+scal.m11;
	a.m12 = a.m12+scal.m12;
	a.m13 = a.m13+scal.m13;
	a.m14 = a.m14+scal.m14;
	a.m15 = a.m15+scal.m15;
	return a;
}

mat4 mat4_subScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.m0 = a.m0-scal.m0;
	a.m1 = a.m1-scal.m1;
	a.m2 = a.m2-scal.m2;
	a.m3 = a.m3-scal.m3;
	a.m4 = a.m4-scal.m4;
	a.m5 = a.m5-scal.m5;
	a.m6 = a.m6-scal.m6;
	a.m7 = a.m7-scal.m7;
	a.m8 = a.m8-scal.m8;
	a.m9 = a.m9-scal.m9;
	a.m10 = a.m10-scal.m10;
	a.m11 = a.m11-scal.m11;
	a.m12 = a.m12-scal.m12;
	a.m13 = a.m13-scal.m13;
	a.m14 = a.m14-scal.m14;
	a.m15 = a.m15-scal.m15;
	return a;
}

mat4 mat4_mulScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.m0 = a.m0*scal.m0;
	a.m1 = a.m1*scal.m1;
	a.m2 = a.m2*scal.m2;
	a.m3 = a.m3*scal.m3;
	a.m4 = a.m4*scal.m4;
	a.m5 = a.m5*scal.m5;
	a.m6 = a.m6*scal.m6;
	a.m7 = a.m7*scal.m7;
	a.m8 = a.m8*scal.m8;
	a.m9 = a.m9*scal.m9;
	a.m10 = a.m10*scal.m10;
	a.m11 = a.m11*scal.m11;
	a.m12 = a.m12*scal.m12;
	a.m13 = a.m13*scal.m13;
	a.m14 = a.m14*scal.m14;
	a.m15 = a.m15*scal.m15;
	return a;
}

mat4 mat4_divScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.m0 = a.m0/scal.m0;
	a.m1 = a.m1/scal.m1;
	a.m2 = a.m2/scal.m2;
	a.m3 = a.m3/scal.m3;
	a.m4 = a.m4/scal.m4;
	a.m5 = a.m5/scal.m5;
	a.m6 = a.m6/scal.m6;
	a.m7 = a.m7/scal.m7;
	a.m8 = a.m8/scal.m8;
	a.m9 = a.m9/scal.m9;
	a.m10 = a.m10/scal.m10;
	a.m11 = a.m11/scal.m11;
	a.m12 = a.m12/scal.m12;
	a.m13 = a.m13/scal.m13;
	a.m14 = a.m14/scal.m14;
	a.m15 = a.m15/scal.m15;
	return a;
}

mat4 mat4_identity(void){
	mat4 a = {1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f};
	return a;
}

mat4 mat4_translate(float x, float y, float z){
	mat4 a = {1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			x, y, z, 1.f};
	return a;
}
mat4 mat4_scale(float x, float y, float z){
	mat4 a = {x, 0.0f, 0.0f, 0.0f,
			0.0f, y, 0.0f, 0.0f,
			0.0f, 0.0f, z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.f};
	return a;
}
mat4 mat4_transScale1(float x, float y, float z, float scale){
	mat4 res;

	res.m0 = res.m5 = res.m10 = scale;
	res.m15 = 1;

	res.m12 = x;
	res.m13 = y;
	res.m14 = z;

	res.m1 = res.m2 = res.m3 = 0.f;
	res.m4 = res.m6 = res.m7 = 0.f;
	res.m8 = res.m9 = res.m10 = 0.f;

	return res;
}
mat4 mat4_transScale(float x, float y, float z, float xscale, float yscale, float zscale){
	mat4 res;

	res.m0 = xscale;
	res.m5 = yscale;
	res.m10 = zscale;
	res.m15 = 1;

	res.m12 = x;
	res.m13 = y;
	res.m14 = z;

	res.m1 = res.m2 = res.m3 = 0.f;
	res.m4 = res.m6 = res.m7 = 0.f;
	res.m8 = res.m9 = res.m10 = 0.f;

	return res;
}
mat4 mat4_perspective(float fov, float aspect, float near, float far){
	mat4 res;

	float top = tan(fov/2)*near;
	float bottom = -top;
	float left = top*aspect;
	float right = -left;

	float nx2 = near*2;
	float FminN = far - near;
	float RminL = right - left;
	float TminB = top - bottom;

	res.m0 = nx2/(RminL);
	res.m1 = 0.f;
	res.m2 = 0.f;
	res.m3 = 0.f;

	res.m4 = 0.f;
	res.m5 = nx2/(TminB);
	res.m6 = 0.f;
	res.m7 = 0.f;

	res.m8 = (right+left)/(RminL);
	res.m9 = (top+bottom)/(TminB);
	res.m10 = (-(far+near))/FminN;
	res.m11 = -1.f;

	res.m12 = 0.f;
	res.m13 = 0.f;
	res.m14 = (-nx2*far)/FminN;
	res.m15 = 0.f;

	return res;
}
mat4 mat4_ortho(float left, float right, float top, float bottom, float near, float far){
	mat4 res;

	float FminN = far - near;
	float RminL = right - left;
	float TminB = top - bottom;

	res.m0 = 2.f/(RminL);
	res.m1 = 0.f;
	res.m2 = 0.f;
	res.m3 = 0.f;

	res.m4 = 0.f;
	res.m5 = 2.f/(TminB);
	res.m6 = 0.f;
	res.m7 = 0.f;

	res.m8 = 0.f;
	res.m9 = 0.f;
	res.m10 = 2.f/FminN;
	res.m11 = 0.f;

	res.m12 = -((right+left)/RminL);
	res.m13 = -((top+bottom)/TminB);
	res.m14 = -((far+near)/FminN);
	res.m15 = 1.f;

	return res;
}
mat4 mat4_lookAt(vec3 position, vec3 target, vec3 up){
	vec3 forward = vec3_norm(vec3_sub(position, target));
	vec3 right = vec3_norm(vec3_cross(up, forward));
	vec3 realUp = vec3_norm(vec3_cross(right, forward));

	float dotX = -vec3_dot(right, position);
	float dotY = -vec3_dot(realUp, position);
	float dotZ = -vec3_dot(forward, position);

	mat4 res;
	res.m0 = right.x;
	res.m1 = realUp.x;
	res.m2 = forward.x;
	res.m3 = 0.f;

	res.m4 = right.y;
	res.m5 = realUp.y;
	res.m6 = forward.y;
	res.m7 = 0.f;

	res.m8 = right.z;
	res.m9 = realUp.z;
	res.m10 = forward.z;
	res.m11 = 0.f;

	res.m12 = dotX;
	res.m13 = dotY;
	res.m14 = dotZ;
	res.m15 = 1.f;

	return res;
}
mat4 mat4_lookAtFast(vec3 position, vec3 forward, vec3 up, vec3 right){
	float dotX = -vec3_dot(right, position);
	float dotY = -vec3_dot(up, position);
	float dotZ = -vec3_dot(forward, position);

	mat4 res;
	res.m0 = right.x;
	res.m1 = up.x;
	res.m2 = forward.x;
	res.m3 = 0.f;

	res.m4 = right.y;
	res.m5 = up.y;
	res.m6 = forward.y;
	res.m7 = 0.f;

	res.m8 = right.z;
	res.m9 = up.z;
	res.m10 = forward.z;
	res.m11 = 0.f;

	res.m12 = dotX;
	res.m13 = dotY;
	res.m14 = dotZ;
	res.m15 = 1.f;

	return res;
}
mat4 mat4_transpose(mat4 a){
	//way faster to just use another matrix instead of a bunch of subtitutions
	mat4 res = {a.m0, a.m4, a.m8, a.m12,
		a.m1, a.m5, a.m9, a.m13,
		a.m2, a.m6, a.m10, a.m11,
		a.m3, a.m7, a.m11, a.m15};
	return res;
}
mat4 mat4_swapRow(mat4 a, int R1, int R2){
	float tmp[4] = {a.mat2d[0][R1], a.mat2d[1][R1], a.mat2d[2][R1], a.mat2d[3][R1]};

	a.mat2d[0][R1] = a.mat2d[0][R2];
	a.mat2d[1][R1] = a.mat2d[1][R2];
	a.mat2d[2][R1] = a.mat2d[2][R2];
	a.mat2d[3][R1] = a.mat2d[3][R2];

	a.mat2d[0][R2] = tmp[0];
	a.mat2d[1][R2] = tmp[1];
	a.mat2d[2][R2] = tmp[2];
	a.mat2d[3][R2] = tmp[3];

	return a;
}
mat4 mat4_swapCol(mat4 a, int C1, int C2){
	float tmp = a.mat2d[C1][0];
	a.mat2d[C1][0] = a.mat2d[C2][0];
	a.mat2d[C2][0] = tmp;

	tmp = a.mat2d[C1][1];
	a.mat2d[C1][1] = a.mat2d[C2][1];
	a.mat2d[C2][1] = tmp;

	tmp = a.mat2d[C1][2];
	a.mat2d[C1][2] = a.mat2d[C1][2];
	a.mat2d[C1][2] = tmp;

	tmp = a.mat2d[C1][3];
	a.mat2d[C1][3] = a.mat2d[C1][3];
	a.mat2d[C1][3] = tmp;

	return a;
}
