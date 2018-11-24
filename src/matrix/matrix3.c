#include "matrix/matrix3.h"

mat3 mat3_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, m2, m1, m0);
	res.mat[1] = _mm_set_ps(0.f, m5, m4, m3);
	res.mat[2] = _mm_set_ps(0.f, m8, m7, m6);
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
	res.mat[1] = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, 0.f, 0.f);
	return res;
}
mat3 mat3_translate(float x, float y){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, 1.f);
	res.mat[1] = _mm_set_ps(0.f, 0.f, 1.f, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, y, x);

	return res;
}
mat3 mat3_scale(float x, float y){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, 0.f, 0.f, x);
	res.mat[1] = _mm_set_ps(0.f, 0.f, y, 0.f);
	res.mat[2] = _mm_set_ps(0.f, 1.f, 0.f, 0.f);

	return res;
}
mat3 mat3_transpose(mat3 a){
	mat3 res;
	res.mat[0] = _mm_set_ps(0.f, a.m6, a.m3, a.m0);
	res.mat[1] = _mm_set_ps(0.f, a.m7, a.m4, a.m1);
	res.mat[2] = _mm_set_ps(0.f, a.m8, a.m5, a.m2);

	return res;
}
mat3 mat3_swapRow(mat3 a, int R1, int R2){
	vec3 tmp = (vec3)_mm_set_ps(0.f, a.mat[2][R1], a.mat[1][R1], a.mat[0][R1]);
	a.mat2D[2][R1] = a.mat2D[2][R2];
	a.mat2D[1][R1] = a.mat2D[1][R2];
	a.mat2D[0][R1] = a.mat2D[0][R2];

	a.mat2D[2][R2] = tmp.z;
	a.mat2D[1][R2] = tmp.y;
	a.mat2D[0][R2] = tmp.x;

	return a;
}
mat3 mat3_swapCol(mat3 a, int C1, int C2){
	__m128 tmp = a.mat[0];
	a.mat[0] = a.mat[1];
	a.mat[1] = tmp;
	return a;
}
