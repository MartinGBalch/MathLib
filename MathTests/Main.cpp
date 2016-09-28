#include <cassert>
#include <cstdio>
#include <iostream>
#include "Test.h"
#include "vec2.h"
#include "flops.h"
#include "vec3.h"
#include <cfloat>
int main()
{
	//printf("Hello fucker %d\n", doNothing(40));

	assert(doNothing(0) == 5);

	assert(doSomething(0) == -7);

	assert(doSomething(1) == -4);

	assert(doSomething(-1) == -8);

	assert(quad(1, 4, 4).left_root == -2);
	assert(quad(1, 4, 4).right_root == -2);

	assert(quad(4, 1, -5).roots == 2);

	assert(blend(0, 5, 10) == 50);

	assert((vec2{ 1,1 } + vec2{ 1,0 } == vec2{ 2,1 }));

	
	assert(normal(vec2{ 0,1 }) == (vec2{ 0,1 }));
	assert(fequals(1, FLT_EPSILON));

	assert(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4);
	


	system("pause");

}