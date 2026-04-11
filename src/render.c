#include "raylib.h"

#include "config.h"
#include "colours.h"
#include "vec2.h"
#include "render.h"

void table_draw(const SimCamera* camera, const Table* table)
{
	Vec2 table_corner_screen = sim_to_screen(camera, table->baulk_top);

	DrawRectangle(
		(int)table_corner_screen.x,
		(int)table_corner_screen.y,
		(int)(table->width * camera->scale),
		(int)(table->height * camera->scale),
		COLOR_FELT
	);
}

void table_cushion_draw(const SimCamera* camera, const Table* table)
{
	
}
