#include "matrix/matrix2_plain.h"

mat2 mat2_set(float m0, float m1, float m2, float m3){
	mat2 res = {m0, m1, m2, m3};
	return res;
}
mat2 mat2_set1(float x){
	mat2 res = {x, x, x, x};
	return res;
}
mat2 mat2_add(mat2 a, mat2 b){
	a.mat1d[0] += b.mat1d[0];
	a.mat1d[0] += b.mat1d[0];
	a.mat1d[0] += b.mat1d[0];
	a.mat1d[0] += b.mat1d[0];
	return a;
}
mat2 mat2_sub(mat2 a, mat2 b){
	a.mat1d[0] -= b.mat1d[0];
	a.mat1d[0] -= b.mat1d[0];
	a.mat1d[0] -= b.mat1d[0];
	a.mat1d[0] -= b.mat1d[0];
	return a;
}
mat2 mat2_mul(mat2 a, mat2 b){
	mat2 res;

	res.mat1d[0] = a.m11*b.m11+a.m21*b.m12;
	res.mat1d[1] = a.m12*b.m11+a.m22*b.m12;

	res.mat1d[2] = a.m11*b.m21+a.m21*b.m22;
	res.mat1d[3] = a.m12*b.m21+a.m22*b.m22;

	return res;
}
mat2 mat2_addScal(mat2 a, float scalar){
	a.mat1d[0] += scalar;
	a.mat1d[0] += scalar;
	a.mat1d[0] += scalar;
	a.mat1d[0] += scalar;
	return a;
}
mat2 mat2_subScal(mat2 a, float scalar){
	a.mat1d[0] -= scalar;
	a.mat1d[0] -= scalar;
	a.mat1d[0] -= scalar;
	a.mat1d[0] -= scalar;
	return a;
}
mat2 mat2_mulScal(mat2 a, float scalar){
	a.mat1d[0] *= scalar;
	a.mat1d[0] *= scalar;
	a.mat1d[0] *= scalar;
	a.mat1d[0] *= scalar;
	return a;
}
mat2 mat2_divScal(mat2 a, float scalar){
	a.mat1d[0] /= scalar;
	a.mat1d[0] /= scalar;
	a.mat1d[0] /= scalar;
	a.mat1d[0] /= scalar;
	return a;
}
mat2 mat2_identity(void){
	mat2 res = {1.f, 0.f, 0.f, 1.f};
}
mat2 mat2_translate(float x){
	mat2 res = {1.f, 1.f, x, 1.f};
	return res;
}
mat2 mat2_scale(float x){
	mat2 res = {1.f, 0.f, 0.f, x};
	return res;
}
mat2 mat2_transpose(mat2 a){
	mat2 res = {a.m11, a.m21, a.m12, a.m22};
	return res;
}
mat2 mat2_swapRow(mat2 a){
	mat2 res = {a.m12, a.m11, a.m22, a.m21};
	return res;
}
mat2 mat2_swapCol(mat2 a){
	mat2 res = {a.m21, a.m22, a.m11, a.m12};
	return res;
}

