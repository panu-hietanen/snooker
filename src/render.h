#ifndef RENDER_H__
#define RENDER_H__

#include "camera.h"
#include "table.h"

void table_draw(const SimCamera* camera, const Table* table);
void table_cushion_draw(const SimCamera* camera, const Table* table);
void ball_draw(const SimCamera* camera, const Ball* ball);

#endif //RENDER_H__
