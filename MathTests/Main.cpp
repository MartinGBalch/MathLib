#include <cassert>
#include <cstdio>
#include <iostream>
#include "Test.h"
#include "vec2.h"
#include "flops.h"
#include "vec3.h"
#include <cfloat>
#include "mat3.h"
#include "mat2.h"
#include "collision.h"
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
	assert(fequals(0, 0.00001));

	assert(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4);
	
	vec3 j = { 2,5,1 };

	assert((scale(5, 1) * j == vec3{ 10,5,1 }));

	//assert((rotation(deg2rad(90)) * j == vec3{ -5,2,1 }));

	assert((translate(0, 3) * j == vec3{ 2,8,1 }));

	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,2,1 };
	vec2 v0 = vec2{ 1,0 };

	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI*-1 == -mI);

	

	assert(transpose(mI) == mI);
	assert(inverse(mI) == mI);

	assert(t0*inverse(t0) == mI);

	mat3 t03 = {};
	mat3 mI3 = mat3Identity();

	assert(mI3*inverse(mI3) == mI3);

	



	system("pause");

}