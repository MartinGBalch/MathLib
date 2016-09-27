#include <cassert>
#include <cstdio>
#include <iostream>
#include "Test.h"
#include "vec2.h"

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

	



	system("pause");

}