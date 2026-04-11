#include "config.h"
#include "camera.h"

double camera_scale(const SimCamera* camera, double x)
{
	return camera->scale * x;
}

int sim_to_screen_x(const SimCamera* camera, double x)
{
	return (int)((x - camera->offset.x) * camera->scale + SCREEN_W / 2);
}

int sim_to_screen_y(const SimCamera* camera, double y)
{
	return (int)((y - camera->offset.y) * camera->scale + SCREEN_H / 2);
}

double screen_to_sim_x(const SimCamera* camera, double x)
{
	return (x - SCREEN_W / 2) / camera->scale + camera->offset.x;
}

double screen_to_sim_y(const SimCamera* camera, double y)
{
	return (y - SCREEN_H / 2) / camera->scale + camera->offset.y;
}

Vec2 sim_to_screen(const SimCamera* camera, Vec2 pos)
{
	return (Vec2) {
		.x = sim_to_screen_x(camera, pos.x),
		.y = sim_to_screen_y(camera, pos.y),
	};
}

Vec2 screen_to_sim(const SimCamera* camera, Vec2 pos)
{
	return (Vec2) {
		.x = screen_to_sim_x(camera, pos.x),
		.y = screen_to_sim_y(camera, pos.y),
	};
}
