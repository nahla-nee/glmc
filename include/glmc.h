#ifndef GLMC_H
#define GLMC_H

//vector.h doens't actually include vector 2 3 and 4
//the reason is that vector.h is meant to define functions that can be used with all vectors
//this is not the case with matrix.h vector_plain.h, or matrix_plain.h.
#include "vector/vector.h"
#include "vector/vector2.h"
#include "vector/vector3.h"
#include "vector/vector4.h"
#include "vector/quaternion.h"

#include "matrix/matrix2.h"
#include "matrix/matrix3.h"
#include "matrix/matrix4.h"

#define GLMC_DEG2RAD(DEG) (DEG*M_PI/180.f)
#define GLMC_RAD2DEG(RAD) (RAD*180.f/M_PI)

#endif /*GLMC_H*/
