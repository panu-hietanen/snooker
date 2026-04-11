#include <stdio.h>

#include "utils.h"

void vec2_print(Vec2 a)
{
	printf("[%f, %f]", a.x, a.y);
}

void vec2_println(Vec2 a)
{
	vec2_print(a);
	printf("\n");
}

void ball_print(const Ball* b)
{
	printf("Type %d, ", b->type);
	printf("vel = ");
	vec2_print(b->vel);
	printf(" @ ");
	vec2_print(b->pos);
}

void ball_println(const Ball* b)
{
	ball_print(b);
	printf("\n");
}

void ball_array_print(const BallArray* arr)
{
	for (size_t i = 0; i < arr->len; ++i)
	{
		printf("<%d>: ", (int)i);
		ball_println(&arr->data[i]);
	}
}