# Vec3

A 3 component vector.

## Definition

```c
typedef union vec3{
	__m128 vec;
	struct{
		float x, y, z;
	};
	struct{
		float r, g, b;
	};
} vec3;
```

## Functions

>`__m128 vec3_set(float x, float y, float z)`

Returns a vector with the specified values.

>`__m128 vec3_set1(__m128 x)`

Returns a vector with all values set to `x`.

>`__m128 vec3_add(__m128 a, __m128 b)`

Returns the vector that results from adding `a` and `b`.

>`__m128 vec3_sub(__m128 a, __m128 b)`

Returns the vector that results from subtracting `b` from a.

>`__m128 vec3_mul(__m128 a, __m128 b)`

Returns the vector that results from multiplying `a` by `b`.

>`__m128 vec3_div(__m128 a, __m128 b)`

Returns the vector that results from dividing `a` by `b`.

Note: this would return a vector that looks like the following:
`{a.x/b.x, a.y/b.y, a.z/b.z}`

>`__m128 vec3_addScal(__m128 a, float scalar)`

Returns the vector that results from adding `scalar` to `a`.

>`__m128 vec3_subScal(__m128 a, float scalar)`

Returns the vector that results from subtracting `scalar` from `b`.

>`__m128 vec3_mulScal(__m128 a, float scalar)`

Returns the vector that results from multiplying `a` by `scalar`.

>`__m128 vec3_divScal(__m128 a, float scalar)`

Returns the vector that results from dividing `a` by `scalar`.

>`__m128 vec3_abs(__m128 a)`

Returns the vector that results from taking the absolute value of `a`.

>`__m128 vec3_ceil(__m128 a)`

Returns the vector that results from taking the ceiling of `a`.

>`__m128 vec3_floor(__m128 a)`

Returns the vector that results from taking the floor of `a`.

>`__m128 vec3_round(__m128 a)`

Returns the vector that results from rounding `a`.

>`bool vec3_equalEps(__m128 a, __m128 b, float epsilon)`

Returns `true` if the difference between all members of `a` and `b` is less
than `epsilon` otherwise returns `false`.

>`bool vec3_equal(__m128 a, __m128 b)`

Calls `vec3_equalEps(a, b, FLT_EPSILON)` and returns its value.

>`float vec3_len(__m128 a)`

Returns the length of `a`.

>`__m128 vec3_norm(__m128 a)`

Returns the vector that results from normalizing `a`.

>`float vec3_dot(__m128 a, __m128 b)`

Returns the value that results from taking the dot product of `a` and `b`

>`__m128 vec3_cross(__m128 a, __m128 b)`

Returns the vector that results from cross multiplying `a` and `b`.

>`__m128 vec3_mulMat(__m128 a, mat3 b)`

Returns the vector that results from multiplying `a` by `b`.
