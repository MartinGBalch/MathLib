#pragma once


bool fequals(float lhs, float rhs);

float deg2rad(float deg);

float rad2deg(float rad);


//Basic curving stuff
float linearHalf(float x);

float growFast(float x);

float growSlow(float x);

float hardAngle(float x);

float bounce(float x);
float bounceFlip(float x);

float parabFlip(float x);

//curving Functions (legit)

float lerp(float start, float end, float alpha);

float quadBezier(float start, float mid, float end, float alpha);

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha);

float cardinalSpline(float start, float mid, float end, float tightness, float alpha);

float catRomSpline(float start, float mid, float end);