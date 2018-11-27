#include "matrix/matrix3.h"

mat3 mat3_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8){
	mat3 res;
	res.mat[0] = _mm_set_ps(m3, m2, m1, m0);
	res.mat[1] = _mm_set_ps(m7, m6, m5, m4);
	res.mat[2] = _mm_set_ps(0.f, 0.f, 0.f, m8);
	return res;
}
mat3 mat3_set1(float x){
	mat3 res;
	res.mat[0] = _mm_set1_ps(x);
	res.mat[1] = res.mat[0];
	res.mat[2] = res.mat[0];
	return res;
}
mat3 mat3_add(mat3 a, mat3 b){
	a.mat[0] = _mm_add_ps(a.mat[0], b.mat[0]);
	a.mat[1] = _mm_add_ps(a.mat[1], b.mat[1]);
	a.mat[2] = _mm_add_ps(a.mat[2], b.mat[2]);
	return a;
}
mat3 mat3_sub(mat3 a, mat3 b){
	a.mat[0] = _mm_sub_ps(a.mat[0], b.mat[0]);
	a.mat[1] = _mm_sub_ps(a.mat[1], b.mat[1]);
	a.mat[2] = _mm_sub_ps(a.mat[2], b.mat[2]);
	return a;
}
mat3 mat3_mul(mat3 a, mat3 b){
	mat3 res;

	res.mat1D[0] = a.m0*b.m0+a.m3*b.m1+a.m6*b.m2;
	res.mat1D[1] = a.m1*b.m0+a.m4*b.m1+a.m7*b.m2;
	res.mat1D[2] = a.m2*b.m0+a.m5*b.m1+a.m8*b.m2;

	res.mat1D[3] = a.m0*b.m3+a.m3*b.m4+a.m6*b.m5;
	res.mat1D[4] = a.m1*b.m3+a.m4*b.m4+a.m7*b.m5;
	res.mat1D[5] = a.m2*b.m3+a.m5*b.m4+a.m8*b.m5;

	res.mat1D[6] = a.m0*b.m6+a.m3*b.m7+a.m6*b.m8;
	res.mat1D[7] = a.m1*b.m6+a.m4*b.m7+a.m7*b.m8;
	res.mat1D[8] = a.m2*b.m6+a.m5*b.m7+a.m8*b.m8;

	return res;
}
mat3 mat3_addScal(mat3 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_add_ps(a.mat[0], scal);
	a.mat[1] = _mm_add_ps(a.mat[1], scal);
	a.mat[2] = _mm_add_ps(a.mat[2], scal);
	return a;
}
mat3 mat3_subScal(mat3 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_sub_ps(a.mat[0], scal);
	a.mat[1] = _mm_sub_ps(a.mat[1], scal);
	a.mat[2] = _mm_sub_ps(a.mat[2], scal);
	return a;
}
mat3 mat3_mulScal(mat3 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_mul_ps(a.mat[0], scal);
	a.mat[1] = _mm_mul_ps(a.mat[1], scal);
	a.mat[2] = _mm_mul_ps(a.mat[2], scal);
	return a;
}
mat3 mat3_divScal(mat3 a, float scalar){
	__m128 scal = _mm_set1_ps(scalar);
	a.mat[0] = _mm_div_ps(a.mat[0], scal);
	a.mat[1] = _mm_div_ps(a.mat[1], scal);
	a.mat[2] = _mm_div_ps(a.mat[2], scal);
	return a;
}
mat3 mat3_identity(void){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[2] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	return res;
}
mat3 mat3_translate(float x, float y){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(y, x, 0.f, 1.f);
	res.mat[2] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);

	return res;
}
mat3 mat3_scale(float x, float y){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, x);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 0.f, y);
	res.mat[2] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);

	return res;
}
mat3 mat3_transpose(mat3 a){
	__m128 t = _mm_shuffle_ps(a.mat[0], a.mat[1], _MM_SHUFFLE(1, 2, 1, 2));
	a.mat[0] = _mm_shuffle_ps(a.mat[0], t, _MM_SHUFFLE(1, 2, 3, 0));
	a.mat[1] = _mm_shuffle_ps(a.mat[1], t, _MM_SHUFFLE(3, 0, 3, 0));
	return a;
}
mat3 mat3_swapRow(mat3 a, int R1, int R2){
	float tmp[3] = {a.mat2D[0][R1], a.mat2D[1][R1], a.mat2D[2][R1]};

	a.mat2D[0][R1] = a.mat2D[0][R2];
	a.mat2D[1][R1] = a.mat2D[1][R2];
	a.mat2D[2][R1] = a.mat2D[2][R2];

	a.mat2D[0][R2] = tmp[0];
	a.mat2D[1][R2] = tmp[1];
	a.mat2D[2][R2] = tmp[2];
	
	return a;
}
mat3 mat3_swapCol(mat3 a, int C1, int C2){
	float tmp[3] = {a.mat2D[C1][0], a.mat2D[C1][1], a.mat2D[C1][2]};

	a.mat2D[C1][0] = a.mat2D[C2][0];
	a.mat2D[C1][1] = a.mat2D[C2][1];
	a.mat2D[C1][2] = a.mat2D[C2][2];

	a.mat2D[C2][0] = tmp[0];
	a.mat2D[C2][1] = tmp[1];
	a.mat2D[C2][2] = tmp[2];
	return a;
}
