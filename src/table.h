#ifndef TABLE_H__
#define TABLE_H__

#include "vec2.h"

#define POCKET_COUNT 6

typedef struct {
    double width;
    double height;
    double cushion_t;               // cushion thickness, for rendering

    Vec2   pocket_pos[POCKET_COUNT]; // clockwise from top-left
    double pocket_radius;

    double baulk_y;                 // y of baulk line (positive = baulk/bottom end)
    double d_radius;
    Vec2   d_centre;                // on the baulk line, at x = 0

    Vec2 spot_blue;
    Vec2 spot_pink;
    Vec2 spot_black;
    Vec2 spot_brown;
    Vec2 spot_yellow;
    Vec2 spot_green;
} Table;

Table table_init(void);

#endif // TABLE_H__
