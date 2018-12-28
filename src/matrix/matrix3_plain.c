#include "matrix/matrix3_plain.h"

mat3 mat3_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8){
	mat3 res = {m0, m1, m2, m3, m4, m5, m6, m7, m8};
	return res;
}
mat3 mat3_set1(float x){
	mat3 res = {x, x, x, x, x, x, x, x, x};
	return res;
}
mat3 mat3_add(mat3 a, mat3 b){
	a.mat1d[0] = a.mat1d[0]+b.mat1d[0];
	a.mat1d[1] = a.mat1d[1]+b.mat1d[1];
	a.mat1d[2] = a.mat1d[2]+b.mat1d[2];
	a.mat1d[3] = a.mat1d[3]+b.mat1d[3];
	a.mat1d[4] = a.mat1d[4]+b.mat1d[4];
	a.mat1d[5] = a.mat1d[5]+b.mat1d[5];
	a.mat1d[6] = a.mat1d[6]+b.mat1d[6];
	a.mat1d[7] = a.mat1d[7]+b.mat1d[7];
	a.mat1d[8] = a.mat1d[8]+b.mat1d[8];
	return a;
}
mat3 mat3_sub(mat3 a, mat3 b){
	a.mat1d[0] = a.mat1d[0]-b.mat1d[0];
	a.mat1d[1] = a.mat1d[1]-b.mat1d[1];
	a.mat1d[2] = a.mat1d[2]-b.mat1d[2];
	a.mat1d[3] = a.mat1d[3]-b.mat1d[3];
	a.mat1d[4] = a.mat1d[4]-b.mat1d[4];
	a.mat1d[5] = a.mat1d[5]-b.mat1d[5];
	a.mat1d[6] = a.mat1d[6]-b.mat1d[6];
	a.mat1d[7] = a.mat1d[7]-b.mat1d[7];
	a.mat1d[8] = a.mat1d[8]-b.mat1d[8];
	return a;
}
mat3 mat3_mul(mat3 a, mat3 b){
	mat3 res;

	res.mat1d[0] = a.m11*b.m11+a.m21*b.m12+a.m31*b.m13;
	res.mat1d[1] = a.m12*b.m11+a.m22*b.m12+a.m32*b.m13;
	res.mat1d[2] = a.m13*b.m11+a.m23*b.m12+a.m33*b.m13;

	res.mat1d[3] = a.m11*b.m21+a.m21*b.m22+a.m31*b.m23;
	res.mat1d[4] = a.m12*b.m21+a.m22*b.m22+a.m32*b.m23;
	res.mat1d[5] = a.m13*b.m21+a.m23*b.m22+a.m33*b.m23;

	res.mat1d[6] = a.m11*b.m31+a.m21*b.m32+a.m31*b.m33;
	res.mat1d[7] = a.m12*b.m31+a.m22*b.m32+a.m32*b.m33;
	res.mat1d[8] = a.m13*b.m31+a.m23*b.m32+a.m33*b.m33;

	return res;
}
mat3 mat3_addScal(mat3 a, float scalar){
	a.mat1d[0] = a.mat1d[0]+scalar;
	a.mat1d[1] = a.mat1d[1]+scalar;
	a.mat1d[2] = a.mat1d[2]+scalar;
	a.mat1d[3] = a.mat1d[3]+scalar;
	a.mat1d[4] = a.mat1d[4]+scalar;
	a.mat1d[5] = a.mat1d[5]+scalar;
	a.mat1d[6] = a.mat1d[6]+scalar;
	a.mat1d[7] = a.mat1d[7]+scalar;
	a.mat1d[8] = a.mat1d[8]+scalar;
	return a;
}
mat3 mat3_subScal(mat3 a, float scalar){
	a.mat1d[0] = a.mat1d[0]-scalar;
	a.mat1d[1] = a.mat1d[1]-scalar;
	a.mat1d[2] = a.mat1d[2]-scalar;
	a.mat1d[3] = a.mat1d[3]-scalar;
	a.mat1d[4] = a.mat1d[4]-scalar;
	a.mat1d[5] = a.mat1d[5]-scalar;
	a.mat1d[6] = a.mat1d[6]-scalar;
	a.mat1d[7] = a.mat1d[7]-scalar;
	a.mat1d[8] = a.mat1d[8]-scalar;
	return a;
}
mat3 mat3_mulScal(mat3 a, float scalar){
	a.mat1d[0] = a.mat1d[0]*scalar;
	a.mat1d[1] = a.mat1d[1]*scalar;
	a.mat1d[2] = a.mat1d[2]*scalar;
	a.mat1d[3] = a.mat1d[3]*scalar;
	a.mat1d[4] = a.mat1d[4]*scalar;
	a.mat1d[5] = a.mat1d[5]*scalar;
	a.mat1d[6] = a.mat1d[6]*scalar;
	a.mat1d[7] = a.mat1d[7]*scalar;
	a.mat1d[8] = a.mat1d[8]*scalar;
	return a;
}
mat3 mat3_divScal(mat3 a, float scalar){
	a.mat1d[0] = a.mat1d[0]/scalar;
	a.mat1d[1] = a.mat1d[1]/scalar;
	a.mat1d[2] = a.mat1d[2]/scalar;
	a.mat1d[3] = a.mat1d[3]/scalar;
	a.mat1d[4] = a.mat1d[4]/scalar;
	a.mat1d[5] = a.mat1d[5]/scalar;
	a.mat1d[6] = a.mat1d[6]/scalar;
	a.mat1d[7] = a.mat1d[7]/scalar;
	a.mat1d[8] = a.mat1d[8]/scalar;
	return a;
}
mat3 mat3_identity(void){
	mat3 res = {1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		0.f, 0.f, 1.f};
	return res;
}
mat3 mat3_translate(float x, float y){
	mat3 res = {1.f, 0.f, 0.f,
		0.f, 1.f, 0.f,
		y, x, 1.f};
	return res;
}
mat3 mat3_scale(float x, float y){
	mat3 res = {x, 0.f, 0.f,
		0.f, y, 0.f,
		0.f, 0.f, 1.f};
	return res;
}
mat3 mat3_transpose(mat3 a){
	mat3 res = {a.m11, a.m21, a.m31,
		a.m12, a.m22, a.m32,
		a.m13, a.m23, a.m33};
	return res;
}
mat3 mat3_swapRow(mat3 a, int R1, int R2){
	float tmp[3] = {a.mat2d[0][R1], a.mat2d[1][R1], a.mat2d[2][R1]};

	a.mat2d[0][R1] = a.mat2d[0][R2];
	a.mat2d[1][R1] = a.mat2d[1][R2];
	a.mat2d[2][R1] = a.mat2d[2][R2];

	a.mat2d[0][R2] = tmp[0];
	a.mat2d[1][R2] = tmp[1];
	a.mat2d[2][R2] = tmp[2];
	
	return a;
}
mat3 mat3_swapCol(mat3 a, int C1, int C2){
	float tmp[3] = {a.mat2d[C1][0], a.mat2d[C1][1], a.mat2d[C1][2]};

	a.mat2d[C1][0] = a.mat2d[C2][0];
	a.mat2d[C1][1] = a.mat2d[C2][1];
	a.mat2d[C1][2] = a.mat2d[C2][2];

	a.mat2d[C2][0] = tmp[0];
	a.mat2d[C2][1] = tmp[1];
	a.mat2d[C2][2] = tmp[2];

	return a;
}
