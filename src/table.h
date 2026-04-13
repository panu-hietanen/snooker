#ifndef TABLE_H__
#define TABLE_H__

#include "vec2.h"

#define POCKET_COUNT 6

typedef struct Table {
    double width;               // long axis, along x  (3569 mm)
    double height;              // short axis, along y  (1778 mm)
    double cushion_t;           // green felt cushion depth (collision boundary)
    double wood_t;              // outer wood frame depth (visual only)

    Vec2   pocket_pos[POCKET_COUNT]; // clockwise from baulk-top
    double pocket_radius;

    Vec2   baulk_top;
    double baulk_x;             // x of the baulk line (negative = baulk/left end)
    double d_radius;
    Vec2   d_centre;            // on baulk line, at y = 0

    Vec2 spot_blue;             // centre of table
    Vec2 spot_pink;             // between blue and top cushion, y = 0
    Vec2 spot_black;            // near top cushion, y = 0
    Vec2 spot_brown;            // centre of baulk line, y = 0
    Vec2 spot_yellow;           // baulk line, +y side
    Vec2 spot_green;            // baulk line, -y side
} Table;

Table table_init();

#endif // TABLE_H__
