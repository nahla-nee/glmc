# Quat

A quaternion.

## Definition

```c
typedef union quat{
	__m128 vec;
	struct{
		float x, y, z, w;
	};
} quat;
```

## Functions

>`__m128 quat_set(float x, float y, float z, float w)`

Returns a quaternion with the specified values.

>`__m128 quat_set1(__m128 x)`

Returns a quaternion with all values set to `x`.

>`__m128 quat_add(__m128 a, __m128 b)`

Returns the quaternion that results from adding `a` and `b`.

>`__m128 quat_sub(__m128 a, __m128 b)`

Returns the quaternion that results from subtracting `b` from `a`.

>`__m128 quat_addScal(__m128 a, float scalar)`

Returns the quaternion that results from adding `scalar` to `a`.

>`__m128 quat_subScal(__m128 a, float scalar)`

Returns the quaternion that resutls from subtracting `scalar` from `a`.

>`__m128 quat_mulScal(__m128 a, float scalar)`

Returns the quaternion that results from multiplying `a` by `scalar`.

>`__m128 quat_divScal(__m128 a, float scalar)`

Returns the quaternion that results from dividing `a` by `scalar`

>`__m128 quat_abs(__m128 a)`

Returns the quaternion that results from taking the absolute value of `a`.

>`__m128 quat_ceil(__m128 a)`

Returns the quaternion that results from taking the ceiling of `a`.

>`__m128 quat_floor(__m128 a)`

Returns the quaternion that results from taking the floor of `a`.

>`__m128 quat_round(__m128 a)`

Returns the quaternion that results from rounding `a`.

>`bool quat_equalEps(__m128 a, __m128 b, float epsilon)`

Returns `true` if the difference between all members of `a` and `b` is less
than `epsilon` otherwise returns `false`.

>`bool quat_equal(__m128 a, __m128 b)`

Calls `quat_equalEps(a, b, FLT_EPSILON)` and returns its value.

>`float quat_len(__m128 a)`

Returns the length of `a`.

>`__m128 quat_norm(__m128 a)`

Returns the quaternion that results from normalizing `a`.

>`__m128 quat_conj(__m128 a)`

Returns the conjugate of `a`.

>`__m128 quat_inv(__m128 a)`

Returns the inverse of `a`.

>`__m128 quat_mul(__m128 a, __m128 b)`

Returns the result of multyping each element of `a` and `b`

>`__m128 quat_mulReal(__m128 a, __m128 b)`

Returns the result of multiplying two real quaternions.

>`__m128 quat_mulPure(__m128 a, __m128 b)`

Returns the result of multiplying two pure quaternions.

>`__m128 quat_div(__m128 a, __m128 b)`

Returns the result of dividing two quaternions.

>`__m128 quat_rotation(float angle, float x, float y, float z)`

Returns a quaternion with a rotation of `angle` around the `x, y, z` axis.

Note: `angle` is in radians.

>`mat4 quat_toMat(__m128 a)`

Converts the quaternion to a rotation matrix.
