#include "flops.h"
#include <cfloat>
#define _USE_MATH_DEFINES
#include <cmath>
#include "math.h"

bool fequals(float lhs, float rhs)
{
	if (fabs(lhs - rhs < FLT_EPSILON))
	{
		return true;
	}
	else { return false; }
}

float deg2rad(float deg)
{
	return (deg * M_PI) / 180;
}

float rad2deg(float rad)
{
	return (rad * 180) / M_PI;
}
