#include <math.h>
#include <stdio.h>

#include "vec2.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// VEC2
///////////////////////////////////////////////////////////////////////////////////////////////////

Vec2 vec2_add(Vec2 a, Vec2 b)
{
	return (Vec2) {
		.x = a.x + b.x,
		.y = a.y + b.y,
	};
}

Vec2 vec2_sub(Vec2 a, Vec2 b)
{
	return (Vec2) {
		.x = a.x - b.x,
		.y = a.y - b.y,
	};
}

Vec2 vec2_shift(Vec2 a, double s)
{
	return (Vec2) {
		.x = a.x + s,
		.y = a.y + s,
	};
}

Vec2 vec2_scale(Vec2 a, double s)
{
	return (Vec2) {
		.x = a.x * s,
		.y = a.y * s,
	};
}

Vec2 vec2_rotate(Vec2 a, double theta)
{
	return (Vec2) {
		.x = a.x * cos(theta) - a.y * sin(theta),
		.y = a.x * sin(theta) + a.y * cos(theta),
	};
}

double vec2_dot(Vec2 a, Vec2 b)
{
	return a.x * b.x + a.y * b.y;
}

double vec2_length(Vec2 a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

double vec2_length2(Vec2 a)
{
	return a.x * a.x + a.y * a.y;
}

Vec2 vec2_normalise(Vec2 a)
{
	double l = vec2_length(a);
	return (Vec2) {
		.x = a.x / l,
		.y = a.y / l,
	};
}

double vec2_distance(Vec2 a, Vec2 b)
{
	return vec2_length(vec2_sub(a, b));
}

double vec2_distance2(Vec2 a, Vec2 b)
{
	return vec2_length2(vec2_sub(a, b));
}

Vec2 vec2_zeroed()
{
	return (Vec2) { .x = 0, .y = 0 };
}
