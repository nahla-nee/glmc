#ifndef GLMC_QUAT_PLAIN
#define GLMC_QUAT_PLAIN

#include "../defs_plain.h"

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <math.h>
#include <float.h>

quat quat_set1(x)
quat quat_add(a, b)
quat quat_sub(quat a, quat b)
quat quat_div(quat a, quat b)
quat quat_addScal(quat a, float scalar)
quat quat_subScal(quat a, float scalar)
quat quat_mulScal(quat a, float scalar)
quat quat_divScal(quat a, float scalar)
quat quat_abs(quat a)
quat quat_ceil(quat a)
quat quat_floor(quat a)
quat quat_round(quat a)
bool quat_equal(quat a, quat b);
bool quat_equal_eps(quat a, quat b, float epsilon);
float quat_len(quat a);
quat quat_norm(quat a);
quat quat_set(float x, float y, float z, float w);
quat quat_mul(quat a, quat b);

#ifdef __cplusplus
}
#endif

#endif
