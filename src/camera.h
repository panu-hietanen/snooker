#ifndef CAMERA_H__
#define CAMERA_H__

#include "vec2.h"

typedef struct {
	Vec2 offset;
	double scale
} Camera;

int sim_to_screen_x(const Camera* camera, double x);
int sim_to_screen_y(const Camera* camera, double y);
int screen_to_sim_x(const Camera* camera, double x);
int screen_to_sim_y(const Camera* camera, double y);

#endif //CAMERA_H__
