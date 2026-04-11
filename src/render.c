#include "raylib.h"

#include "config.h"
#include "colours.h"
#include "vec2.h"
#include "render.h"

Vector2 raylib_vec(Vec2 v)
{
	return (Vector2) { (float)v.x, (float)v.y };
}

void table_draw(const SimCamera* camera, const Table* table)
{
	Vector2 table_corner_screen = raylib_vec(sim_to_screen(camera, table->baulk_top));
	Vector2 table_size = { (float)(table->width * camera->scale), (float)(table->height * camera->scale) };

	DrawRectangleV(
		table_corner_screen,
		table_size,
		COLOR_FELT
	);
}

//void table_cushion_draw(const SimCamera* camera, const Table* table)
//{
//		
//}
//
//void ball_draw(const SimCamera* camera, const Ball* ball)
//{
//	
//}
