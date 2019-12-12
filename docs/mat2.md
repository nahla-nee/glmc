# Mat2

A 2x2 column major matrix

## Internals

```c
//simd
typedef union mat2{
	__m128 mat;
	float mat2d[2][2];
	float mat1d[4];
	struct{
		float m0, m1, m2, m3;
	};
} mat2;
```

>`mat2 mat2_set(float m0, float m1, float m2, float m3)`

Returns a matrix with the specified values.

>`mat2 mat2_set1(float x)`

Returns a matrix with all values set to `x`.

>`mat2 mat2_add(mat2 a, mat2 b)`

Returns the matrix that results from adding `a` and `b`.

>`mat2 mat2_sub(mat2 a, mat2 b)`

Returns the matrix that results from subtracting `a` and `b`.

>`mat2 mat2_mul(mat2 a, mat2 b)`

Returns the matrix that results from multiplying `a` and `b`.

>`mat2 mat2_addScal(mat2 a, float scalar)`

Returns the matrix that results from adding `scalar` to `a`.

>`mat2 mat2_subScal(mat2 a, float scalar)`

Returns the matrix that results from subtracting `scalar` from `a`.

>`mat2 mat2_mulScal(mat2 a, float scalar)`

Returns the matrix that results from multiplying `a` by `scalar`.

>`mat2 mat2_divScal(mat2 a, float scalar)`

Returns the matrix that results from dividing `a` by `scalar`.

>`mat2 mat2_identity(void)`

Returns an identity matrix.

>`mat2 mat2_translate(float x)`

Returns a translation matrix using `x`.

>`mat2 mat2_scale(float x)`

Returns a scaling matrix using `x`.

>`mat2 mat2_transpose(mat2 a)`

Transposes `a` and returns the resulting matrix.

>`mat2 mat2_swapRow(mat2 a)`

Swaps the rows of `a` and returns the resulting matrix.

>`mat2 mat2_swapCol(mat2 a)`

Swaps the columns of `a` and returns the resulting matrix.
