#ifndef GLMC_QUAT_PLAIN
#define GLMC_QUAT_PLAIN

#include "../defs_plain.h"
#include <stdbool.h>
#include <math.h>
#include <float.h>

#ifdef __cplusplus
namespace glmc{
extern "C"{
#endif

quat quat_set1(float x);
quat quat_add(quat a, quat b);
quat quat_sub(quat a, quat b);
quat quat_addScal(quat a, float scalar);
quat quat_subScal(quat a, float scalar);
quat quat_mulScal(quat a, float scalar);
quat quat_divScal(quat a, float scalar);
quat quat_abs(quat a);
quat quat_ceil(quat a);
quat quat_floor(quat a);
quat quat_round(quat a);
bool quat_equal(quat a, quat b);
bool quat_equal_eps(quat a, quat b, float epsilon);
float quat_len(quat a);
quat quat_norm(quat a);
quat quat_set(float w, float x, float y, float z);
quat quat_conj(quat a);
quat quat_inv(quat a);
quat quat_mul(quat a, quat b);
quat quat_mulReal(quat a, quat b);
quat quat_mulPure(quat a, quat b);
quat quat_div(quat a, quat b);
quat quat_rotation(float angle, float x, float y, float z);

#ifdef __cplusplus
}
}
#endif

#endif
