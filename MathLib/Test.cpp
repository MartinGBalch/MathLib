#include "Test.h"
#include <math.h>

int doNothing(int x)
{
	return x*x + 2 * x + 5;
}

int doSomething(int x)
{
	return x*x + 2 * x - 7;
}

quad_results quad(float a, float b, float c)
{
	quad_results retval;

	retval.left_root = (b * -1 + sqrt(b*b - 4 * a*c)) / (2 * a);
	retval.right_root = (b * -1 - sqrt(b*b - 4 * a*c)) / (2 * a);

	float discr = b*b - 4 * a*c;

	if (discr < 0)
	{
		retval.roots = 0;
	}
	else if (discr == 0.0f)
	{
		retval.roots = 1;
	}
	else
	{
		retval.roots = 2;
	}
	
	return retval;
}

float blend(float s, float t, float e)
{
	return (s + t * (e - s));
}

float distance(Point P1, Point P2)
{
	return sqrt(((P2.x - P1.x)*(P2.x - P1.x)) + (P2.y - P1.y)*(P2.y - P1.y));
}








