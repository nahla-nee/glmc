#ifndef GLMC_PLAIN_H
#define GLMC_PLAIN_H

//non SSE version of glmc!
//you really shouldn't use this, literally every CPU supports SSE
#include "vector/vector2_plain.h"
#include "vector/vector3_plain.h"
#include "vector/vector4_plain.h"
#include "vector/quaternion_plain.h"

#include "matrix/matrix2_plain.h"
#include "matrix/matrix3_plain.h"
#include "matrix/matrix4_plain.h"

#define GLMC_DEG2RAD(DEG) (DEG*M_PI/180.f);
#define GLMC_RAD2DEG(RAD) (RAD*180.f/M_PI);

#endif /*GLMC_PLAIN_H*/
