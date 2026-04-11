#include "table.h"
#include "config.h"

// Coordinate system
// -----------------
// Origin at the centre of the table.
// +x points toward the top/black end   (right on screen)
// -x points toward the baulk end       (left on screen)
// +y points toward the bottom cushion  (down on screen)
// -y points toward the top cushion     (up on screen)

Table table_init()
{
    double hw = TABLE_W / 2.0;
    double hh = TABLE_H / 2.0;

    // Baulk line: 737 mm inward from the baulk/left cushion face.
    double baulk_x = -hw + TABLE_BAULK_FROM_BOTTOM;

    // Pink: midpoint between the blue spot (x = 0) and the top/right cushion face.
    double pink_x = hw / 2.0;

    // Black: 324 mm inward from the top/right cushion face.
    double black_x = hw - TABLE_BLACK_FROM_TOP;

    return (Table) {
        .width    = TABLE_W,
        .height   = TABLE_H,
        .cushion_t = TABLE_CUSHION_T,

        // Pockets, clockwise from baulk-top corner.
        .pocket_pos = {
            { .x = -hw, .y = -hh }, // baulk-top
            { .x =  0,  .y = -hh }, // top-mid
            { .x = +hw, .y = -hh }, // top-right
            { .x = +hw, .y = +hh }, // bottom-right
            { .x =  0,  .y = +hh }, // bottom-mid
            { .x = -hw, .y = +hh }, // baulk-bottom
        },
        .pocket_radius = TABLE_POCKET_RADIUS,

        .baulk_x  = baulk_x,
        .d_radius = TABLE_D_RADIUS,
        .d_centre = { .x = baulk_x, .y = 0.0 },

        // All spots on the centreline (y = 0) except yellow and green,
        // which sit on the baulk line offset by the D radius.
        .spot_blue   = { .x =             0.0, .y =             0.0 },
        .spot_pink   = { .x =          pink_x, .y =             0.0 },
        .spot_black  = { .x =         black_x, .y =             0.0 },
        .spot_brown  = { .x =         baulk_x, .y =             0.0 },
        .spot_yellow = { .x =         baulk_x, .y = +TABLE_D_RADIUS },
        .spot_green  = { .x =         baulk_x, .y = -TABLE_D_RADIUS },
    };
}
