#ifndef GLMC_DEFS_PLAIN
#define GLMC_DEFS_PLAIN

#ifdef __cplusplus
extern "C"{
#endif

typedef union vec2{
	float vec[2];
	struct{
		float x, y;
	};
} vec2;

typedef union vec3{
	float vec[3];
	struct{
		float x, y, z;
	};
	struct{
		float r, g, b;
	};
} vec3;

typedef union vec4{
	float vec[4];
	struct{
		float x, y, z, w;
	};
	struct{
		float r, g, b, a;
	};
} vec4;

typedef union quat{
	struct{
		float w, x, y, z;
	};
	struct{
		float s, i, j, k;
	};
} quat;

typedef union mat2{
	float mat[4];
	float mat2D[2][2];
	struct{
		float m11, m12, m21, m22;
	};
} mat2;

typedef union mat3{
	float mat[9];
	float mat2D[3][3];
	struct{
		float m11, m12, m13, m21, m22, m23, m31, m32, m33;
	};
} mat3;

typedef union mat4{
	float mat[16];
	float mat2D[4][4];
	struct{
		float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
	};
} mat4;

#ifdef __cplusplus
}
#endif

#endif
