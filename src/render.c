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

void ball_draw(const SimCamera* camera, const Ball* ball)
{
	if (!ball->bool_draw) return;
	Vector2 ball_pos_screen = raylib_vec(sim_to_screen(camera, ball->pos));
	Color c = PURPLE;
	switch (ball->type)
	{
	case BALL_WHITE:
		c = COLOR_WHITE;
		break;
	case BALL_RED: 
		c = COLOR_RED;
		break;
	case BALL_BLACK: 
		c = COLOR_BLACK;
		break;
	case BALL_PINK: 
		c = COLOR_PINK;
		break;
	case BALL_BLUE: 
		c = COLOR_BLUE;
		break;
	case BALL_BROWN: 
		c = COLOR_BROWN;
		break;
	case BALL_GREEN: 
		c = COLOR_GREEN;
		break;
	case BALL_YELLOW: 
		c = COLOR_YELLOW;
		break;
	}
	DrawCircleV(ball_pos_screen, (float)(BALL_RADIUS_SIM * camera->scale), c);
}
