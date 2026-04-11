#include <stdlib.h>

#include "ball.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// BALL
///////////////////////////////////////////////////////////////////////////////////////////////////

Ball ball_init(Vec2 pos, Vec2 vel, BallType type)
{
	return (Ball) {
		.pos = pos,
		.vel = vel,
		.type = type,
	};
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// BALLARRAY
///////////////////////////////////////////////////////////////////////////////////////////////////

BallArray ball_array_init(size_t capacity)
{
	Ball* new_array = malloc(sizeof(Ball) * capacity);
	return (BallArray) {
		.data = new_array,
		.len = 0,
		.cap = capacity,
	};
}

void ball_array_push(BallArray* arr, const Ball b)
{
	if (arr->cap == arr->len)
	{
		arr->cap = (arr->cap == 0) ? 1 : arr->cap * 2;
		arr->data = realloc(arr->data, sizeof(Ball) * arr->cap);
	}
	arr->data[arr->len++] = b;
}

void ball_array_pop(BallArray* arr)
{
	if (arr->len == 0) return;
	arr->len--;
}

void ball_array_free(BallArray* arr)
{
	free(arr->data);
	arr->data = NULL;
	arr->len = 0;
	arr->cap = 0;
}