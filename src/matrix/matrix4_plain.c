#include "matrix/matrix4_plain.h"

mat4 mat4_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15){
	mat4 a = {m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15};
	return a;
}
mat4 mat4_set1(float x){
	mat4 a = {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x};
	return a;
}
mat4 mat4_add(mat4 a, mat4 b){
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
mat4 mat4_sub(mat4 a, mat4 b){
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
mat4 mat4_mul(mat4 a, mat4 b){
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
mat4 mat4_addScal(mat4 a, float scalar){
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
mat4 mat4_subScal(mat4 a, float scalar){
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
mat4 mat4_mulScal(mat4 a, float scalar){
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
mat4 mat4_divScal(mat4 a, float scalar){
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
mat4 mat4_identity(void){
	mat4 a = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
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
mat4 mat4_transpose(mat4 a){
	//way faster to just use another matrix instead of a bunch of subtitutions
	mat4 res = {a.m11, a.m21, a.m31, a.m41,
		a.m12, a.m22, a.m32, a.m42,
		a.m13, a.m23, a.m33, a.m34,
		a.m14, a.m24, a.m34, a.m44};
	return res;
}
mat4 mat4_swapRow(mat4 a, int R1, int R2){
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
mat4 mat4_swapCol(mat4 a, int C1, int C2){
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
