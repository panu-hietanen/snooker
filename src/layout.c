#include <math.h>

#include "config.h"
#include "layout.h"

void layout_rack(BallArray* arr, const Table* table)
{
    arr->len = 0;

    // -- Colours on spots --
    ball_array_push(arr, ball_init(table->spot_black,  vec2_zeroed(), BALL_BLACK,  1));
    ball_array_push(arr, ball_init(table->spot_pink,   vec2_zeroed(), BALL_PINK,   1));
    ball_array_push(arr, ball_init(table->spot_blue,   vec2_zeroed(), BALL_BLUE,   1));
    ball_array_push(arr, ball_init(table->spot_brown,  vec2_zeroed(), BALL_BROWN,  1));
    ball_array_push(arr, ball_init(table->spot_green,  vec2_zeroed(), BALL_GREEN,  1));
    ball_array_push(arr, ball_init(table->spot_yellow, vec2_zeroed(), BALL_YELLOW, 1));

    // -- Reds: 5-row triangle, apex touching the pink from the black end --
    // Rows fan out toward the black spot (positive x).
    // Row spacing along x: r * sqrt(3), where r = BALL_RADIUS_SIM.
    // Within each row, balls are spaced by one diameter (2r) along y, centred on y = 0.
    double r      = BALL_RADIUS_SIM;
    double step   = r * sqrt(3.0);
    double apex_x = table->spot_pink.x + 2.0 * r;

    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            Vec2 pos = {
                .x = apex_x + row * step,
                .y = (col - row / 2.0) * 2.0 * r,
            };
            ball_array_push(arr, ball_init(pos, vec2_zeroed(), BALL_RED, 1));
        }
    }

    // -- White: centred in the D --
    Vec2 white_pos = { .x = table->d_centre.x - table->d_radius * 0.5, .y = 0.0 };
    ball_array_push(arr, ball_init(white_pos, vec2_zeroed(), BALL_WHITE, 1));
}
