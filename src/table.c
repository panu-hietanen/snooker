#include "table.h"
#include "config.h"

Table table_init(void)
{
    double hw = TABLE_W / 2.0;
    double hh = TABLE_H / 2.0;

    // Baulk line: measured from the bottom/baulk cushion face inward.
    // Positive y points toward the baulk end, so baulk_y is positive.
    double baulk_y = hh - TABLE_BAULK_FROM_BOTTOM;

    // Pink: midpoint between the blue spot (origin) and the top cushion face.
    double pink_y = -hh / 2.0;

    // Black: measured from the top cushion face inward.
    // Negative y points toward the top end.
    double black_y = -(hh - TABLE_BLACK_FROM_TOP);

    return (Table) {
        .width    = TABLE_W,
        .height   = TABLE_H,
        .cushion_t = TABLE_CUSHION_T,

        // Pockets, clockwise from top-left.
        // Corner pockets sit at the four corners; middle pockets at x = 0
        // on each long cushion. Y is negative toward the top end.
        .pocket_pos = {
            { .x = -hw, .y = -hh }, // top-left
            { .x =  0,  .y = -hh }, // top-mid
            { .x = +hw, .y = -hh }, // top-right
            { .x = +hw, .y = +hh }, // bottom-right
            { .x =  0,  .y = +hh }, // bottom-mid
            { .x = -hw, .y = +hh }, // bottom-left
        },
        .pocket_radius = TABLE_POCKET_RADIUS,

        .baulk_y  = baulk_y,
        .d_radius = TABLE_D_RADIUS,
        .d_centre = { .x = 0.0, .y = baulk_y },

        // Colour spots. Brown, yellow, green all sit on the baulk line.
        // Yellow is to the right (+x), green to the left (-x).
        .spot_blue   = { .x =             0.0, .y =       0.0 },
        .spot_pink   = { .x =             0.0, .y =    pink_y },
        .spot_black  = { .x =             0.0, .y =   black_y },
        .spot_brown  = { .x =             0.0, .y =   baulk_y },
        .spot_yellow = { .x = +TABLE_D_RADIUS, .y =   baulk_y },
        .spot_green  = { .x = -TABLE_D_RADIUS, .y =   baulk_y },
    };
}
