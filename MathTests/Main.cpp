#include <cassert>
#include <cstdio>
#include <iostream>
#include "Test.h"

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

	assert(distance(0, 10) == 50);



	system("pause");

}