#ifndef UTILS_H__
#define UTILS_H__

#include "vec2.h"
#include "ball.h"

void vec2_print(Vec2 a);
void vec2_println(Vec2 a);

void ball_print(const Ball* b);
void ball_println(const Ball* b);

void ball_array_print(const BallArray* arr);

#endif //UTILS_H__
