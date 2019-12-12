#include "matrix/mat3.h"

mat3 mat3_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8){
	mat3 res = {m0, m1, m2, m3, m4, m5, m6, m7, m8};
	return res;
}
mat3 mat3_set1(float x){
	mat3 res = {x, x, x, x, x, x, x, x, x};
	return res;
}
mat3 mat3_add(mat3 a, mat3 b){
	a.m0 = a.m0+b.m0;
	a.m1 = a.m1+b.m1;
	a.m2 = a.m2+b.m2;
	a.m3 = a.m3+b.m3;
	a.m4 = a.m4+b.m4;
	a.m5 = a.m5+b.m5;
	a.m6 = a.m6+b.m6;
	a.m7 = a.m7+b.m7;
	a.m8 = a.m8+b.m8;
	return a;
}
mat3 mat3_sub(mat3 a, mat3 b){
	a.m0 = a.m0-b.m0;
	a.m1 = a.m1-b.m1;
	a.m2 = a.m2-b.m2;
	a.m3 = a.m3-b.m3;
	a.m4 = a.m4-b.m4;
	a.m5 = a.m5-b.m5;
	a.m6 = a.m6-b.m6;
	a.m7 = a.m7-b.m7;
	a.m8 = a.m8-b.m8;
	return a;
}
mat3 mat3_mul(mat3 a, mat3 b){
	mat3 res;

	res.m0 = a.m0*b.m0+a.m3*b.m1+a.m6*b.m2;
	res.m1 = a.m1*b.m0+a.m4*b.m1+a.m7*b.m2;
	res.m2 = a.m2*b.m0+a.m5*b.m1+a.m8*b.m2;

	res.m3 = a.m0*b.m3+a.m3*b.m4+a.m6*b.m5;
	res.m4 = a.m1*b.m3+a.m4*b.m4+a.m7*b.m5;
	res.m5 = a.m2*b.m3+a.m5*b.m4+a.m8*b.m5;

	res.m6 = a.m0*b.m6+a.m3*b.m7+a.m6*b.m8;
	res.m7 = a.m1*b.m6+a.m4*b.m7+a.m7*b.m8;
	res.m8 = a.m2*b.m6+a.m5*b.m7+a.m8*b.m8;

	return res;
}
mat3 mat3_addScal(mat3 a, float scalar){
	a.m0 = a.m0+scalar;
	a.m1 = a.m1+scalar;
	a.m2 = a.m2+scalar;
	a.m3 = a.m3+scalar;
	a.m4 = a.m4+scalar;
	a.m5 = a.m5+scalar;
	a.m6 = a.m6+scalar;
	a.m7 = a.m7+scalar;
	a.m8 = a.m8+scalar;
	return a;
}
mat3 mat3_subScal(mat3 a, float scalar){
	a.m0 = a.m0-scalar;
	a.m1 = a.m1-scalar;
	a.m2 = a.m2-scalar;
	a.m3 = a.m3-scalar;
	a.m4 = a.m4-scalar;
	a.m5 = a.m5-scalar;
	a.m6 = a.m6-scalar;
	a.m7 = a.m7-scalar;
	a.m8 = a.m8-scalar;
	return a;
}
mat3 mat3_mulScal(mat3 a, float scalar){
	a.m0 = a.m0*scalar;
	a.m1 = a.m1*scalar;
	a.m2 = a.m2*scalar;
	a.m3 = a.m3*scalar;
	a.m4 = a.m4*scalar;
	a.m5 = a.m5*scalar;
	a.m6 = a.m6*scalar;
	a.m7 = a.m7*scalar;
	a.m8 = a.m8*scalar;
	return a;
}
mat3 mat3_divScal(mat3 a, float scalar){
	a.m0 = a.m0/scalar;
	a.m1 = a.m1/scalar;
	a.m2 = a.m2/scalar;
	a.m3 = a.m3/scalar;
	a.m4 = a.m4/scalar;
	a.m5 = a.m5/scalar;
	a.m6 = a.m6/scalar;
	a.m7 = a.m7/scalar;
	a.m8 = a.m8/scalar;
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
	mat3 res = {a.m0, a.m3, a.m6,
		a.m1, a.m4, a.m7,
		a.m2, a.m5, a.m8};
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
