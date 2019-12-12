# Vec4

A 4 component vector.

## Definition

```c
typedef union vec4{
	__m128 vec;
	struct{
		float x, y, z, w;
	};
	struct{
		float r, g, b, a;
	};
} vec4;
```

## Functions

>`__m128 vec4_set(float x, float y, float z, float w)`

Returns a vector with the specified values.

>`__m128 vec4_set1(__m128 x)`

Returns a vector with all the values set to `x`.

>`__m128 vec4_add(__m128 a, __m128 b)`

Returns the vector that results from adding `a` and `b`.

>`__m128 vec4_sub(__m128 a, __m128 b)`

Returns the vector that results from subtracting `b` from `a`.

>`__m128 vec4_mul(__m128 a, __m128 b)`

Returns the vector that results from multiplying `a` by `b`.

>`__m128 vec4_div(__m128 a, __m128 b)`

Returns the vector that results from dividing `a` by `b`.

>`__m128 vec4_addScal(__m128 a, float scalar)`

Returns the vector that results from adding `scalar` to `a`.

>`__m128 vec4_subScal(__m128 a, float scalar)`

Returns the vector that results from subtracting `scalar` from `a`.

>`__m128 vec4_mulScal(__m128 a, float scalar)`

Returns the vector that results from multiplying `a` by `scalar`.

>`__m128 vec4_divScal(__m128 a, float scalar)`

Returns the vector that results from dividing `a` by `scalar`.

>`__m128 vec4_abs(__m128 a)`

Returns the vector that results from taking the absolute value of `a`.

>`__m128 vec4_ceil(__m128 a)`

Returns the vector that results from taking the ceiling of `a`.

>`__m128 vec4_floor(__m128 a)`

Returns the vector that results from taking the floor of `a`.

>`__m128 vec4_round(__m128 a)`

Returns the vector that results from rounding `a`.

>`bool vec4_equalEps(__m128 a, __m128 b, float epsilon)`

Returns `true` if the difference between all members of `a` and `b` is less
than `epsilon` otherwise returns `false`.

>`bool vec4_equal(__m128 a, __m128 b)`

Calls `vec4_equalEps(a, b, FLT_EPSILON)` and returns its value.

>`float vec4_len(__m128 a)`

Returns the length of `a`.

>`__m128 vec4_norm(__m128 a)`

Returns the vector that results from normalizing `a`.

>`float vec4_dot(__m128 a, __m128 b)`

Returns the value of taking the dot product of `a` and `b`.

>`__m128 vec4_mulMat(__m128 a, mat4 b)`

Returns the vector that results from multiplying `a` by `b`.
