#ifndef CAMERA_H__
#define CAMERA_H__

#include "vec2.h"

typedef struct {
	Vec2 offset;
	double scale;
} SimCamera;

double camera_scale(const SimCamera* camera, double x);

int sim_to_screen_x(const SimCamera* camera, double x);
int sim_to_screen_y(const SimCamera* camera, double y);
double screen_to_sim_x(const SimCamera* camera, double x);
double screen_to_sim_y(const SimCamera* camera, double y);

Vec2 sim_to_screen(const SimCamera* camera, Vec2 pos);
Vec2 screen_to_sim(const SimCamera* camera, Vec2 pos);

#endif //CAMERA_H__
