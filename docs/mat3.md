# Mat3

A 3x3 column major matrix.

## Definition

```c
//simd
typedef union mat3{
	__m128 mat[2];
	float mat2d[3][3];
	float mat1d[9];
	struct{
		float m0, m1, m2, m3, m4, m5, m6, m7, m8;
	};
} mat3;
```

## Functions

>`mat3 mat3_set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);`

Returns a matrix with the specified values.

>`mat3 mat3_set1(float x);`

Returns a matrix with all values set to `x`.

>`mat3 mat3_add(mat3 a, mat3 b);`

Returns the matrix that results from adding `a` and `b`.

>`mat3 mat3_sub(mat3 a, mat3 b);`

Returns the matrix that results from subtracting `a` and `b`.

>`mat3 mat3_mul(mat3 a, mat3 b);`

Returns the matrix that results from multiplying `a` and `b`.

>`mat3 mat3_addScal(mat3 a, float scalar);`

Returns the matrix that results from adding `scalar` to `a`.

>`mat3 mat3_subScal(mat3 a, float scalar);`

Returns the matrix that results from subtracting `scalar` from `a`.

>`mat3 mat3_mulScal(mat3 a, float scalar);`

Returns the matrix that results from multiplying `a` by `scalar`.

>`mat3 mat3_divScal(mat3 a, float scalar);`

Returns the matrix that results from dividing `a` by `scalar`.

>`mat3 mat3_identity(void);`

Returns an identity matrix.

>`mat3 mat3_translate(float x, float y);`

Returns a translation matrix using `x` and `y`.

>`mat3 mat3_scale(float x, float y);`

Returns a scaling matrix using `x` and `y`.

>`mat3 mat3_transpose(mat3 a);`

Transposes `a` and returns the resulting matrix.

>`mat3 mat3_swapRow(mat3 a, int R1, int R2);`

Swaps the rows of `a` and returns the resulting matrix.

>`mat3 mat3_swapCol(mat3 a, int C1, int C2);`

Swaps the columns of `a` and returns the resulting matrix.
