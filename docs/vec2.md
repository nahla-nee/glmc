# Vec2

A 2 component vector.

## Definition

```c
typedef union vec2{
	__m128 vec;
	struct{
		float x, y;
	};
} vec2;
```

## Functions

>`__m128 vec2_set(float x, float y)`

Returns a vector with the specified values.

>`__m128 vec2_set1(__m128 x)`

Returns a vector with all values set to `x`.

>`__m128 vec2_add(__m128 a, __m128 b)`

Returns the vector that results from adding `a` and `b`.

>`__m128 vec2_sub(__m128 a, __m128 b)`

Returns the vector that results from subtracting `b` from `a`.

>`__m128 vec2_mul(__m128 a, __m128 b)`

Returns the vector that results from multiplying `a` and `b`.

>`__m128 vec2_div(__m128 a, __m128 b)`

Returns the vector taht results from dividing `a` by `b`.

Note: this would return a vector that looks like the following:
`{a.x/b.x, a.y/b.y}`

>`__m128 vec2_addScal(__m128 a, float scalar)`

Returns the vector that results from addding `scalar` to `a`.

>`__m128 vec2_subScal(__m128 a, float scalar)`

Returns the vector that results from subtracting `scalar` from `a`.

>`__m128 vec2_mulScal(__m128 a, float scalar)`

Returns the vector that results from multiplying `a` by `scalar`.

>`__m128 vec2_divScal(__m128 a, float scalar)`

Returns the vector that results from dividing the members of `a` by `scalar`.

>`__m128 vec2_abs(__m128 a)`

Returns the vector that results from taking the absolute value of `a`.

>`__m128 vec2_ceil(__m128 a)`

Returns the vector that results from taking the ceiling of `a`.

>`__m128 vec2_floor(__m128 a)`

Returns the vector that results from taking the floor of `a`.

>`__m128 vec2_round(__m128 a)`

Returns the vector that results from rounding `a`.

>`bool vec2_equalEps(__m128 a, __m128 b, float epsilon)`

Returns `true` if the difference between all members of `a` and `b` is less
than `epsilon` otherwise returns `false`.

>`bool vec2_equal(__m128 a, __m128 b)`

Calls `vec2_equalEps(a, b, FLT_EPSILON)` and returns its value.

>`float vec2_len(__m128 a)`

Returns the length of `a`.

>`__m128 vec2_norm(__m128 a)`

Returns the vector that results from normalizing `a`.

>`float vec2_dot(__m128 a, __m128 b)`

Returns the value of taking the dot product of `a` and `b`.

>`__m128 vec2_mulMat(__m128 a, mat2 b)`

Returns the vector that results from multiplying `a` by `b`.
