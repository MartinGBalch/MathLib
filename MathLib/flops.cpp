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

float linearHalf(float x)
{
	return 0.5f*x;
}

float growFast(float x)
{
	return x*x*x*x;
}

float growSlow(float x)
{
	return 1 - growFast(1 - x);
}

float hardAngle(float x)
{
	return x < 0.5 ? 2 * x : -2 * (x - 1);
}

float bounce(float x)
{
	return abs(cos(x * 10) * (1 - x));
}

float bounceFlip(float x)
{
	return 1 - bounce(x);
}

float parabFlip(float x)
{
	return 1 - (2 * x - 1)*(2 * x - 1);
}

float lerp(float start, float end, float alpha)
{
	return (1 - alpha)*start + (alpha)*end;
}

float quadBezier(float start, float mid, float end, float alpha)
{
	return lerp(lerp(start, mid, alpha), lerp(mid, end, alpha), alpha);
}

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	return h00 * start + h10 * s_tan + h01 * end + h11 * e_tan;
}

float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	float tan0 = (mid - start) * tightness;
	float tan1 = (end - mid) * tightness;

	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	return h00 * start + h10 * tan0 + h01 * mid + h11 * tan1;
}

float catRomSpline(float start, float mid, float end)
{
	//return cardinalSpline(start, mid ,.5,);
}
