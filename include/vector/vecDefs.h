#ifndef LIBGLMC_VECDEFS_SIMD
#define LIBGLMC_VECDEFS_SIMD

#include <smmintrin.h>

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

typedef union vec2{
	__m128 vec;
	struct{
		float x, y;
	};
} vec2;

typedef union vec3{
	__m128 vec;
	struct{
		float x, y, z;
	};
	struct{
		float r, g, b;
	};
} vec3;

typedef union vec4{
	__m128 vec;
	struct{
		float x, y, z, w;
	};
	struct{
		float r, g, b, a;
	};
} vec4;

typedef union quat{
	__m128 vec;
	struct{
		float x, y, z, w;
	};
} quat;

#ifdef __cplusplus
}
}
#endif

#endif
