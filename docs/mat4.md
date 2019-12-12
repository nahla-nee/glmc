# Mat4

A 4x4 column major matrix

## Internals

```c
//simd
typedef union mat4{
	__m128 mat[4];
	float mat2d[4][4];
	float mat1d[16];
	struct{
		float m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15;
	};
} mat4;
```

>`mat4 mat4_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)`

Returns a matrix with the specified values.

>`mat4 mat4_set1(float x)`

Returns a matrix with all values set to `x`.

>`mat4 mat4_add(mat4 a, mat4 b)`

Returns the matrix that results from adding `a` and `b`.

>`mat4 mat4_sub(mat4 a, mat4 b)`

Returns the matrix that results from subtracting `a` and `b`.

>`mat4 mat4_mul(mat4 a, mat4 b)`

Returns the matrix that results from multiplying `a` and `b`.

>`mat4 mat4_addScal(mat4 a, float scalar)`

Returns the matrix that results from adding `scalar` to `a`.

>`mat4 mat4_subScal(mat4 a, float scalar)`

Returns the matrix that results from subtracting `scalar` from `a`.

>`mat4 mat4_mulScal(mat4 a, float scalar)`

Returns the matrix that results from multiplying `a` by `scalar`.

>`mat4 mat4_divScal(mat4 a, float scalar)`

Returns the matrix that results from dividing `a` by `scalar`.

>`mat4 mat4_identity(void)`

Returns an identity matrix.

>`mat4 mat4_translate(float x, float y, float z)`

Returns a translation matrix using `x` `y` and `z`.

>`mat4 mat4_scale(float x, float y, float z)`

Returns a scaling matrix using `x` `y` and `z`.

>`mat4 mat4_transScale1(float x, float y, float z, float scale)`

Returns a scaling translation matrix using a single scale value.

>`mat4 mat4_transScale(float x, float y, float z, float xscale, float yscale, float zscale)`

Returns a scaling translation matrix using invidual scale values for each axis.

>`mat4 mat4_perspective(float fov, float aspect, float near, float far)`

Returns a perspective matrix.

>`mat4 mat4_ortho(float left, float right, float top, float bottom, float near, float far)`

Returns an ortho matrix.

>`mat4 mat4_lookAt(__m128 position, __m128 target, __m128 up)`

Returns a lookAt matrix.

>`mat4 mat4_lookAtFast(__m128 position, __m128 forward, __m128 up, __m128 right)`

Returns a lookAt matrix but uses your precomputed forward and right vectors.

>`mat4 mat4_transpose(mat4 a)`

Transposes `a` and returns the resulting matrix.

>`mat4 mat4_swapRow(mat4 a, int R1, int R2)`

Swaps the rows of `a` and returns the resulting matrix.

>`mat4 mat4_swapCol(mat4 a, int C1, int C2)`

Swaps the columns of `a` and returns the resulting matrix.
