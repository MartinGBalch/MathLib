#pragma once

int doNothing(int x);

int doSomething(int x);

struct quad_results
{
	float left_root, right_root;
	int roots; //0, 1, 2
};

quad_results quad(float a, float b, float c);

float blend(float s, float t, float e);

struct Point { float x, y; };
float distance(Point P1, Point P2);
float distance(float x1, float y1, float x2, float y2);

struct Point3D { float x, y, z; };
float inner(Point3D P1, Point3D P2);
float inner(float x1, float y1, float z1, float x2, float y2, float z2);

