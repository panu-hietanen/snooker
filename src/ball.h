#ifndef BALL_H__
#define BALL_H__

#include <stddef.h>

#include "vec2.h"

typedef enum { white, red, black, pink, blue, brown, green, yellow, } BallType;

typedef struct {
	Vec2 pos;
	Vec2 vel;
	BallType type;
} Ball;

Ball ball_init(Vec2 pos, Vec2 vel, int type);

typedef struct {
	Ball* data;
	size_t len;
	size_t cap;
} BallArray;

BallArray ball_array_init (size_t capacity);
void      ball_array_push (BallArray* arr, const Ball b);
void      ball_array_pop  (BallArray* arr);
void      ball_array_free (BallArray* arr);
void      ball_array_print(BallArray* arr);

#endif //BALL_H__