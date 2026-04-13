#ifndef RENDER_H__
#define RENDER_H__

#include "camera.h"
#include "table.h"
#include "ball.h"

void table_draw(const SimCamera* camera, const Table* table);
void ball_draw(const SimCamera* camera, const Ball* ball);
void ball_array_draw(const SimCamera* camera, const BallArray* arr);

#endif //RENDER_H__
