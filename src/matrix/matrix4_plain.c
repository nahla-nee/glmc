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
	a.mat1d[0] = a.mat1d[0]+b.mat1d[0];
	a.mat1d[1] = a.mat1d[1]+b.mat1d[1];
	a.mat1d[2] = a.mat1d[2]+b.mat1d[2];
	a.mat1d[3] = a.mat1d[3]+b.mat1d[3];
	a.mat1d[4] = a.mat1d[4]+b.mat1d[4];
	a.mat1d[5] = a.mat1d[5]+b.mat1d[5];
	a.mat1d[6] = a.mat1d[6]+b.mat1d[6];
	a.mat1d[7] = a.mat1d[7]+b.mat1d[7];
	a.mat1d[8] = a.mat1d[8]+b.mat1d[8];
	a.mat1d[9] = a.mat1d[9]+b.mat1d[9];
	a.mat1d[10] = a.mat1d[10]+b.mat1d[10];
	a.mat1d[11] = a.mat1d[11]+b.mat1d[11];
	a.mat1d[12] = a.mat1d[12]+b.mat1d[12];
	a.mat1d[13] = a.mat1d[13]+b.mat1d[13];
	a.mat1d[14] = a.mat1d[14]+b.mat1d[14];
	a.mat1d[15] = a.mat1d[15]+b.mat1d[15];
	return a;
}
mat4 mat4_sub(mat4 a, mat4 b){
	a.mat1d[0] = a.mat1d[0]-b.mat1d[0];
	a.mat1d[1] = a.mat1d[1]-b.mat1d[1];
	a.mat1d[2] = a.mat1d[2]-b.mat1d[2];
	a.mat1d[3] = a.mat1d[3]-b.mat1d[3];
	a.mat1d[4] = a.mat1d[4]-b.mat1d[4];
	a.mat1d[5] = a.mat1d[5]-b.mat1d[5];
	a.mat1d[6] = a.mat1d[6]-b.mat1d[6];
	a.mat1d[7] = a.mat1d[7]-b.mat1d[7];
	a.mat1d[8] = a.mat1d[8]-b.mat1d[8];
	a.mat1d[9] = a.mat1d[9]-b.mat1d[9];
	a.mat1d[10] = a.mat1d[10]-b.mat1d[10];
	a.mat1d[11] = a.mat1d[11]-b.mat1d[11];
	a.mat1d[12] = a.mat1d[12]-b.mat1d[12];
	a.mat1d[13] = a.mat1d[13]-b.mat1d[13];
	a.mat1d[14] = a.mat1d[14]-b.mat1d[14];
	a.mat1d[15] = a.mat1d[15]-b.mat1d[15];
	return a;
}
mat4 mat4_mul(mat4 a, mat4 b){
	mat4 res;
	res.mat1d[0] = a.m11*b.m11+a.m21*b.m12+a.m31*b.m13+a.m41*b.m14;
	res.mat1d[1] = a.m12*b.m11+a.m22*b.m12+a.m32*b.m13+a.m42*b.m14;
	res.mat1d[2] = a.m13*b.m11+a.m23*b.m12+a.m33*b.m13+a.m43*b.m14;
	res.mat1d[3] = a.m14*b.m11+a.m24*b.m12+a.m34*b.m13+a.m44*b.m14;

	res.mat1d[4] = a.m11*b.m21+a.m21*b.m22+a.m31*b.m23+a.m41*b.m24;
	res.mat1d[5] = a.m12*b.m21+a.m22*b.m22+a.m32*b.m23+a.m42*b.m24;
	res.mat1d[6] = a.m13*b.m21+a.m23*b.m22+a.m33*b.m23+a.m43*b.m24;
	res.mat1d[7] = a.m14*b.m21+a.m24*b.m22+a.m34*b.m23+a.m44*b.m24;

	res.mat1d[8] = a.m11*b.m31+a.m21*b.m32+a.m31*b.m33+a.m41*b.m34;
	res.mat1d[9] = a.m12*b.m31+a.m22*b.m32+a.m32*b.m33+a.m42*b.m34;
	res.mat1d[10] = a.m13*b.m31+a.m23*b.m32+a.m33*b.m33+a.m43*b.m34;
	res.mat1d[11] = a.m14*b.m31+a.m24*b.m32+a.m34*b.m33+a.m44*b.m34;

	res.mat1d[12] = a.m11*b.m41+a.m21*b.m42+a.m31*b.m43+a.m41*b.m44;
	res.mat1d[13] = a.m12*b.m41+a.m22*b.m42+a.m32*b.m43+a.m42*b.m44;
	res.mat1d[14] = a.m13*b.m41+a.m23*b.m42+a.m33*b.m43+a.m43*b.m44;
	res.mat1d[15] = a.m14*b.m41+a.m24*b.m42+a.m34*b.m43+a.m44*b.m44;
	return a;
}
mat4 mat4_addScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.mat1d[0] = a.mat1d[0]+scal.mat1d[0];
	a.mat1d[1] = a.mat1d[1]+scal.mat1d[1];
	a.mat1d[2] = a.mat1d[2]+scal.mat1d[2];
	a.mat1d[3] = a.mat1d[3]+scal.mat1d[3];
	a.mat1d[4] = a.mat1d[4]+scal.mat1d[4];
	a.mat1d[5] = a.mat1d[5]+scal.mat1d[5];
	a.mat1d[6] = a.mat1d[6]+scal.mat1d[6];
	a.mat1d[7] = a.mat1d[7]+scal.mat1d[7];
	a.mat1d[8] = a.mat1d[8]+scal.mat1d[8];
	a.mat1d[9] = a.mat1d[9]+scal.mat1d[9];
	a.mat1d[10] = a.mat1d[10]+scal.mat1d[10];
	a.mat1d[11] = a.mat1d[11]+scal.mat1d[11];
	a.mat1d[12] = a.mat1d[12]+scal.mat1d[12];
	a.mat1d[13] = a.mat1d[13]+scal.mat1d[13];
	a.mat1d[14] = a.mat1d[14]+scal.mat1d[14];
	a.mat1d[15] = a.mat1d[15]+scal.mat1d[15];
	return a;
}
mat4 mat4_subScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.mat1d[0] = a.mat1d[0]-scal.mat1d[0];
	a.mat1d[1] = a.mat1d[1]-scal.mat1d[1];
	a.mat1d[2] = a.mat1d[2]-scal.mat1d[2];
	a.mat1d[3] = a.mat1d[3]-scal.mat1d[3];
	a.mat1d[4] = a.mat1d[4]-scal.mat1d[4];
	a.mat1d[5] = a.mat1d[5]-scal.mat1d[5];
	a.mat1d[6] = a.mat1d[6]-scal.mat1d[6];
	a.mat1d[7] = a.mat1d[7]-scal.mat1d[7];
	a.mat1d[8] = a.mat1d[8]-scal.mat1d[8];
	a.mat1d[9] = a.mat1d[9]-scal.mat1d[9];
	a.mat1d[10] = a.mat1d[10]-scal.mat1d[10];
	a.mat1d[11] = a.mat1d[11]-scal.mat1d[11];
	a.mat1d[12] = a.mat1d[12]-scal.mat1d[12];
	a.mat1d[13] = a.mat1d[13]-scal.mat1d[13];
	a.mat1d[14] = a.mat1d[14]-scal.mat1d[14];
	a.mat1d[15] = a.mat1d[15]-scal.mat1d[15];
	return a;
}
mat4 mat4_mulScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.mat1d[0] = a.mat1d[0]*scal.mat1d[0];
	a.mat1d[1] = a.mat1d[1]*scal.mat1d[1];
	a.mat1d[2] = a.mat1d[2]*scal.mat1d[2];
	a.mat1d[3] = a.mat1d[3]*scal.mat1d[3];
	a.mat1d[4] = a.mat1d[4]*scal.mat1d[4];
	a.mat1d[5] = a.mat1d[5]*scal.mat1d[5];
	a.mat1d[6] = a.mat1d[6]*scal.mat1d[6];
	a.mat1d[7] = a.mat1d[7]*scal.mat1d[7];
	a.mat1d[8] = a.mat1d[8]*scal.mat1d[8];
	a.mat1d[9] = a.mat1d[9]*scal.mat1d[9];
	a.mat1d[10] = a.mat1d[10]*scal.mat1d[10];
	a.mat1d[11] = a.mat1d[11]*scal.mat1d[11];
	a.mat1d[12] = a.mat1d[12]*scal.mat1d[12];
	a.mat1d[13] = a.mat1d[13]*scal.mat1d[13];
	a.mat1d[14] = a.mat1d[14]*scal.mat1d[14];
	a.mat1d[15] = a.mat1d[15]*scal.mat1d[15];
	return a;
}
mat4 mat4_divScal(mat4 a, float scalar){
	mat4 scal = {scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar};
	a.mat1d[0] = a.mat1d[0]/scal.mat1d[0];
	a.mat1d[1] = a.mat1d[1]/scal.mat1d[1];
	a.mat1d[2] = a.mat1d[2]/scal.mat1d[2];
	a.mat1d[3] = a.mat1d[3]/scal.mat1d[3];
	a.mat1d[4] = a.mat1d[4]/scal.mat1d[4];
	a.mat1d[5] = a.mat1d[5]/scal.mat1d[5];
	a.mat1d[6] = a.mat1d[6]/scal.mat1d[6];
	a.mat1d[7] = a.mat1d[7]/scal.mat1d[7];
	a.mat1d[8] = a.mat1d[8]/scal.mat1d[8];
	a.mat1d[9] = a.mat1d[9]/scal.mat1d[9];
	a.mat1d[10] = a.mat1d[10]/scal.mat1d[10];
	a.mat1d[11] = a.mat1d[11]/scal.mat1d[11];
	a.mat1d[12] = a.mat1d[12]/scal.mat1d[12];
	a.mat1d[13] = a.mat1d[13]/scal.mat1d[13];
	a.mat1d[14] = a.mat1d[14]/scal.mat1d[14];
	a.mat1d[15] = a.mat1d[15]/scal.mat1d[15];
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
mat4 mat4_transScale1(float x, float y, float z, float scale){
	mat4 res;

	res.mat2d[0][0] = res.mat2d[1][1] = res.mat2d[2][2] = scale;
	res.mat2d[3][3] = 1;

	res.mat2d[3][0] = x;
	res.mat2d[3][1] = y;
	res.mat2d[3][2] = z;

	res.mat2d[0][1] = res.mat2d[0][2] = res.mat2d[0][3] = 0.f;
	res.mat2d[1][0] = res.mat2d[1][2] = res.mat2d[1][3] = 0.f;
	res.mat2d[2][0] = res.mat2d[2][1] = res.mat2d[2][2] = 0.f;

	return res;
}
mat4 mat4_transScale(float x, float y, float z, float xscale, float yscale, float zscale){
	mat4 res;

	res.mat2d[0][0] = xscale;
	res.mat2d[1][1] = yscale;
	res.mat2d[2][2] = zscale;
	res.mat2d[3][3] = 1;

	res.mat2d[3][0] = x;
	res.mat2d[3][1] = y;
	res.mat2d[3][2] = z;

	res.mat2d[0][1] = res.mat2d[0][2] = res.mat2d[0][3] = 0.f;
	res.mat2d[1][0] = res.mat2d[1][2] = res.mat2d[1][3] = 0.f;
	res.mat2d[2][0] = res.mat2d[2][1] = res.mat2d[2][2] = 0.f;

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

	res.mat1d[0] = nx2/(RminL);
	res.mat1d[1] = 0.f;
	res.mat1d[2] = 0.f;
	res.mat1d[3] = 0.f;

	res.mat1d[4] = 0.f;
	res.mat1d[5] = nx2/(TminB);
	res.mat1d[6] = 0.f;
	res.mat1d[7] = 0.f;

	res.mat1d[8] = (right+left)/(RminL);
	res.mat1d[9] = (top+bottom)/(TminB);
	res.mat1d[10] = (-(far+near))/FminN;
	res.mat1d[11] = -1.f;

	res.mat1d[12] = 0.f;
	res.mat1d[13] = 0.f;
	res.mat1d[14] = (-nx2*far)/FminN;
	res.mat1d[15] = 0.f;

	return res;
}
mat4 mat4_ortho(float left, float right, float top, float bottom, float near, float far){
	mat4 res;

	float FminN = far - near;
	float RminL = right - left;
	float TminB = top - bottom;

	res.mat1d[0] = 2.f/(RminL);
	res.mat1d[1] = 0.f;
	res.mat1d[2] = 0.f;
	res.mat1d[3] = 0.f;

	res.mat1d[4] = 0.f;
	res.mat1d[5] = 2.f/(TminB);
	res.mat1d[6] = 0.f;
	res.mat1d[7] = 0.f;

	res.mat1d[8] = 0.f;
	res.mat1d[9] = 0.f;
	res.mat1d[10] = 2.f/FminN;
	res.mat1d[11] = 0.f;

	res.mat1d[12] = -((right+left)/RminL);
	res.mat1d[13] = -((top+bottom)/TminB);
	res.mat1d[14] = -((far+near)/FminN);
	res.mat1d[15] = 1.f;

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
	res.mat2d[0][0] = right.x;
	res.mat2d[0][1] = realUp.x;
	res.mat2d[0][2] = forward.x;
	res.mat2d[0][3] = 0.f;

	res.mat2d[1][0] = right.y;
	res.mat2d[1][1] = realUp.y;
	res.mat2d[1][2] = forward.y;
	res.mat2d[1][3] = 0.f;

	res.mat2d[2][0] = right.z;
	res.mat2d[2][1] = realUp.z;
	res.mat2d[2][2] = forward.z;
	res.mat2d[2][3] = 0.f;

	res.mat2d[3][0] = dotX;
	res.mat2d[3][1] = dotY;
	res.mat2d[3][2] = dotZ;
	res.mat2d[3][3] = 1.f;

	return res;
}
mat4 mat4_lookAtFast(vec3 position, vec3 forward, vec3 target, vec3 up, vec3 right){
	float dotX = -vec3_dot(right, position);
	float dotY = -vec3_dot(up, position);
	float dotZ = -vec3_dot(forward, position);

	mat4 res;
	res.mat2d[0][0] = right.x;
	res.mat2d[0][1] = up.x;
	res.mat2d[0][2] = forward.x;
	res.mat2d[0][3] = 0.f;

	res.mat2d[1][0] = right.y;
	res.mat2d[1][1] = up.y;
	res.mat2d[1][2] = forward.y;
	res.mat2d[1][3] = 0.f;

	res.mat2d[2][0] = right.z;
	res.mat2d[2][1] = up.z;
	res.mat2d[2][2] = forward.z;
	res.mat2d[2][3] = 0.f;

	res.mat2d[3][0] = dotX;
	res.mat2d[3][1] = dotY;
	res.mat2d[3][2] = dotZ;
	res.mat2d[3][3] = 1.f;

	return res;
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
