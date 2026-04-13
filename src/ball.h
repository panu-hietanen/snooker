#ifndef BALL_H__
#define BALL_H__

#include <stddef.h>

#include "vec2.h"

typedef enum { BALL_WHITE, BALL_RED, BALL_BLACK, BALL_PINK, BALL_BLUE, BALL_BROWN, BALL_GREEN, BALL_YELLOW, } BallType;

typedef struct {
	Vec2 pos;
	Vec2 vel;
	BallType type;
	int bool_draw;
} Ball;

Ball ball_init(Vec2 pos, Vec2 vel, BallType type, int draw);

typedef struct {
	Ball* data;
	size_t len;
	size_t cap;
} BallArray;

BallArray ball_array_init (size_t capacity);
void      ball_array_push (BallArray* arr, const Ball b);
void      ball_array_pop  (BallArray* arr);
void      ball_array_free (BallArray* arr);

#endif //BALL_H__