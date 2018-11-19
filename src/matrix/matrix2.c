#include "matrix/matrix2.h"

mat2 mat2_set(float m0, float m1, float m2, float m3){
	return GLMC_CAST(mat2, _mm_set_ps(m3, m2, m1, m0));
}
mat2 mat2_set1(float x){
	return GLMC_CAST(mat2, _mm_set1_ps(x));
}
mat2 mat2_add(mat2 a, mat2 b){
	return GLMC_CAST(mat2, _mm_add_ps(a.mat, b.mat));
}
mat2 mat2_sub(mat2 a, mat2 b){
	return GLMC_CAST(mat2, _mm_sub_ps(a.mat, b.mat));
}
mat2 mat2_mul(mat2 a, mat2 b){
	__m128 lhs1 = _mm_set_ps(a.m1, a.m0, a.m1, a.m0);
	__m128 lhs2 = _mm_set_ps(a.m2, a.m2, a.m0, a.m0);
	__m128 rhs1 = _mm_set_ps(a.m3, a.m2, a.m3, a.m2);
	__m128 rhs2 = _mm_set_ps(a.m3, a.m3, a.m1, a.m1);
	return GLMC_CAST(mat2, _mm_add_ps(_mm_mul_ps(lhs1, lhs2), _mm_mul_ps(rhs1, rhs2)));
}
mat2 mat2_addScal(mat2 a, float scalar){
	return GLMC_CAST(mat2, _mm_add_ps(a.mat, _mm_set1_ps(scalar)));
}
mat2 mat2_subScal(mat2 a, float scalar){
	return GLMC_CAST(mat2, _mm_sub_ps(a.mat, _mm_set1_ps(scalar)));
}
mat2 mat2_mulScal(mat2 a, float scalar){
	return GLMC_CAST(mat2, _mm_mul_ps(a.mat, _mm_set1_ps(scalar)));
}
mat2 mat2_divScal(mat2 a, float scalar){
	return GLMC_CAST(mat2, _mm_div_ps(a.mat, _mm_set1_ps(scalar)));
}
mat2 mat2_identity(void){
	return GLMC_CAST(mat2, _mm_set_ps(1.f, 0.f, 0.f, 1.f));
}
mat2 mat2_translate(float x){
	return GLMC_CAST(mat2, _mm_set_ps(1.f, x, 0.f, 1.f));
}
mat2 mat2_scale(float x){
	return GLMC_CAST(mat2, _mm_set_ps(x, 0.f, 0.f, 1.f));
}
mat2 mat2_transpose(mat2 a){
	return GLMC_CAST(mat2, _mm_shuffle_ps(a.mat, a.mat, 0xd8));
}
mat2 mat2_swapRow(mat2 a){
	return GLMC_CAST(mat2, _mm_shuffle_ps(a.mat, a.mat, 0xb1));
}
mat2 mat2_swapCol(mat2 a){
	return GLMC_CAST(mat2, _mm_shuffle_ps(a.mat, a.mat, 0x4e));
}
