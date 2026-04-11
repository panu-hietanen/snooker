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