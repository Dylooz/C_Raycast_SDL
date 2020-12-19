#ifndef GUARD_VEC2D_H
#define GUARD_VEC2D_H

#define PI 3.14159265358979323846
#define HALF_PI 1.57079632679489661923
#define QUATER_PI 0.785398163397448309615

struct Vector2d {
	double x;
	double y;
};

typedef struct Vector2d Vector2d;

extern Vector2d s_vector_create(double x, double y);
extern Vector2d s_vector_from_mag_angle(double mag, double angle);
extern Vector2d s_vector_add_s(Vector2d v, double num);
extern Vector2d s_vector_add_v(Vector2d v1, Vector2d v2);
extern Vector2d s_vector_sub_s(Vector2d v, double num);
extern Vector2d s_vector_sub_v(Vector2d v1, Vector2d v2);
extern Vector2d s_vector_mult_s(Vector2d v, double num);
extern Vector2d s_vector_mult_v(Vector2d v1, Vector2d v2);
extern Vector2d s_vector_div_s(Vector2d v, double num);
extern Vector2d s_vector_div_v(Vector2d v1, Vector2d v2);
extern Vector2d s_vector_unit(Vector2d v);
extern Vector2d s_vector_rotate(Vector2d v, double angle);

extern Vector2d *vector_create(double x, double y);
extern Vector2d *vector_from_mag_angle(double mag, double angle);
extern double vector_angle(Vector2d *v);
extern double vector_mag(Vector2d *v);
extern double vector_dist(Vector2d *v);
extern void vector_add_s(Vector2d *v, double num);
extern void vector_add_v(Vector2d *v1, Vector2d *v2);
extern void vector_sub_s(Vector2d *v, double num);
extern void vector_sub_v(Vector2d *v1, Vector2d *v2);
extern void vector_mult_s(Vector2d *v, double num);
extern void vector_mult_v(Vector2d *v1, Vector2d *v2);
extern void vector_div_s(Vector2d *v, double num);
extern void vector_div_v(Vector2d *v1, Vector2d *v2);
extern double vector_angle_between(Vector2d *v1, Vector2d *v2);
extern double vector_dot(Vector2d *v1, Vector2d *v2);
extern void vector_unit(Vector2d *v);
extern void vector_rotate(Vector2d *v, double angle);

#endif