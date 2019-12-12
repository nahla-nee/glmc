#include "matrix/mat2.h"

mat2 mat2_set(float m0, float m1, float m2, float m3){
	mat2 res = {m0, m1, m2, m3};
	return res;
}
mat2 mat2_set1(float x){
	mat2 res = {x, x, x, x};
	return res;
}
mat2 mat2_add(mat2 a, mat2 b){
	a.m0 += b.m0;
	a.m1 += b.m1;
	a.m2 += b.m2;
	a.m3 += b.m3;
	return a;
}
mat2 mat2_sub(mat2 a, mat2 b){
	a.m0 -= b.m0;
	a.m1 -= b.m1;
	a.m2 -= b.m2;
	a.m3 -= b.m3;
	return a;
}
mat2 mat2_mul(mat2 a, mat2 b){
	mat2 res;

	res.m0 = a.m0*b.m0+a.m2*b.m1;
	res.m1 = a.m1*b.m0+a.m3*b.m1;

	res.m2 = a.m0*b.m2+a.m2*b.m3;
	res.m3 = a.m1*b.m2+a.m3*b.m3;

	return res;
}
mat2 mat2_addScal(mat2 a, float scalar){
	a.m0 += scalar;
	a.m1 += scalar;
	a.m2 += scalar;
	a.m3 += scalar;
	return a;
}
mat2 mat2_subScal(mat2 a, float scalar){
	a.m0 -= scalar;
	a.m1 -= scalar;
	a.m2 -= scalar;
	a.m3 -= scalar;
	return a;
}
mat2 mat2_mulScal(mat2 a, float scalar){
	a.m0 *= scalar;
	a.m1 *= scalar;
	a.m2 *= scalar;
	a.m3 *= scalar;
	return a;
}
mat2 mat2_divScal(mat2 a, float scalar){
	a.m0 /= scalar;
	a.m1 /= scalar;
	a.m2 /= scalar;
	a.m3 /= scalar;
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
	mat2 res = {a.m0, a.m2, a.m1, a.m3};
	return res;
}
mat2 mat2_swapRow(mat2 a){
	mat2 res = {a.m1, a.m0, a.m3, a.m2};
	return res;
}
mat2 mat2_swapCol(mat2 a){
	mat2 res = {a.m2, a.m3, a.m0, a.m1};
	return res;
}

