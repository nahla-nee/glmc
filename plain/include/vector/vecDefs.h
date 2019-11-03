#ifndef LIBGLMC_VECDEFS_PLAIN
#define LIBGLMC_VECDEFS_PLAIN

#ifdef __cplusplus
namespace glmc{
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
		float x, y, z, w;
	};
	struct{
		float s, i, j, k;
	};
} quat;

#ifdef __cplusplus
}
}
#endif

#endif
