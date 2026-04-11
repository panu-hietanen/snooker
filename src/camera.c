#include "config.h"
#include "camera.h"

int sim_to_screen_x(const SimCamera* camera, double x)
{
	return (int)((x - camera->offset.x) * camera->scale + SCREEN_W / 2);
}

int sim_to_screen_y(const SimCamera* camera, double y)
{
	return (int)((y - camera->offset.y) * camera->scale + SCREEN_H / 2);
}

int screen_to_sim_x(const SimCamera* camera, double x)
{
	return (int)((x - SCREEN_W / 2) / camera->scale + camera->offset.x);
}

int screen_to_sim_y(const SimCamera* camera, double y)
{
	return (int)((y - SCREEN_H / 2) / camera->scale + camera->offset.y);
}