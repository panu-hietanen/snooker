#include "config.h"
#include "camera.h"

int sim_to_screen_x(const Camera* camera, double x)
{
	return (int)((x - camera->x) * camera->scale + SCREEN_W / 2);
}

int sim_to_screen_y(const Camera* camera, double y)
{
	return (int)((y - camera->y) * camera->scale + SCREEN_H / 2);
}

int screen_to_sim_x(const Camera* camera, double x)
{
	return (int)((x - SCREEN_W / 2) / camera->scale + camera->x);
}

int screen_to_sim_y(const Camera* camera, double y)
{
	return (int)((y - SCREEN_H / 2) / camera->scale + camera->y);
}