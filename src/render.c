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
    double hw = table->width  / 2.0;
    double hh = table->height / 2.0;
    double ct = table->cushion_t;

    double wt = table->wood_t;

    // -- Wood frame (outermost) --
    Vector2 wood_corner = raylib_vec(sim_to_screen(camera, (Vec2){ .x = -hw - ct - wt, .y = -hh - ct - wt }));
    Vector2 wood_size   = {
        (float)((table->width  + 2.0 * (ct + wt)) * camera->scale),
        (float)((table->height + 2.0 * (ct + wt)) * camera->scale),
    };
    DrawRectangleV(wood_corner, wood_size, COLOR_WOOD);

    // -- Cushions (darker green border, sits inside the wood frame) --
    Vector2 cushion_corner = raylib_vec(sim_to_screen(camera, (Vec2){ .x = -hw - ct, .y = -hh - ct }));
    Vector2 cushion_size   = {
        (float)((table->width  + 2.0 * ct) * camera->scale),
        (float)((table->height + 2.0 * ct) * camera->scale),
    };
    DrawRectangleV(cushion_corner, cushion_size, COLOR_CUSHION);

    // -- Playing surface --
    Vector2 felt_corner = raylib_vec(sim_to_screen(camera, table->baulk_top));
    Vector2 felt_size   = {
        (float)(table->width  * camera->scale),
        (float)(table->height * camera->scale),
    };
    DrawRectangleV(felt_corner, felt_size, COLOR_FELT);

    // -- Shadow line along the inner cushion edge --
    float shadow_thick = (float)(ct * camera->scale * 0.3f);
    DrawRectangleLinesEx(
        (Rectangle){ felt_corner.x, felt_corner.y, felt_size.x, felt_size.y },
        shadow_thick,
        COLOR_SHADOW
    );

    // -- Pockets --
    float pocket_r = (float)(table->pocket_radius * camera->scale);
    for (int i = 0; i < POCKET_COUNT; i++)
    {
        Vector2 p = raylib_vec(sim_to_screen(camera, table->pocket_pos[i]));
        DrawCircleV(p, pocket_r, COLOR_POCKET);
    }

    // -- Baulk line --
    Vector2 baulk_top_s    = raylib_vec(sim_to_screen(camera, (Vec2){ .x = table->baulk_x, .y = -hh }));
    Vector2 baulk_bottom_s = raylib_vec(sim_to_screen(camera, (Vec2){ .x = table->baulk_x, .y = +hh }));
    DrawLineV(baulk_top_s, baulk_bottom_s, COLOR_WHITE);

    // -- D arc (semicircle opening toward baulk/left end) --
    Vector2 d_centre_s = raylib_vec(sim_to_screen(camera, table->d_centre));
    float   d_r        = (float)(table->d_radius * camera->scale);
    DrawCircleSectorLines(d_centre_s, d_r, 90.0f, 270.0f, 32, COLOR_WHITE);
}

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

void ball_array_draw(const SimCamera* camera, const BallArray* arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        ball_draw(camera, &arr->data[i]);
    }
}
