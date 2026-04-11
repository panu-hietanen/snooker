#ifndef VEC2_H__
#define VEC2_H__

typedef struct {
	double x, y;
} Vec2;

Vec2 vec2_add(Vec2 a, Vec2 b);
Vec2 vec2_sub(Vec2 a, Vec2 b);
Vec2 vec2_shift(Vec2 a, double s);
Vec2 vec2_scale(Vec2 a, double s);
Vec2 vec2_rotate(Vec2 a, double theta);
double vec2_dot(Vec2 a, Vec2 b);
double vec2_length(Vec2 a);
double vec2_length2(Vec2 a);
Vec2 vec2_normalise(Vec2 a);
double vec2_distance(Vec2 a, Vec2 b);
double vec2_distance2(Vec2 a, Vec2 b);

Vec2 vec2_zeroed();

#endif // VEC2_H__