#include <math.h>
#include "vec2d.h"

Vector2d s_vector_create(double x, double y) {
	Vector2d v;
	v.x = x;
	v.y = y;

	return v;
}

Vector2d s_vector_from_mag_angle(double mag, double angle) {
	Vector2d v;
	v.x = cos(angle) * mag;
	v.y = sin(angle) * mag;
	return v;
}

Vector2d s_vector_add_s(Vector2d v, double num) {
	Vector2d vn;
	vn.x = v.x + num;
	vn.y = v.y + num;
	return vn;
}

Vector2d s_vector_add_v(Vector2d v1, Vector2d v2) {
	Vector2d vn;
	vn.x = v1.x + v2.x;
	vn.y = v1.y + v2.y;
	return vn;
}

Vector2d s_vector_sub_s(Vector2d v, double num) {
	Vector2d vn;
	vn.x = v.x - num;
	vn.y = v.y - num;
	return vn;
}

Vector2d s_vector_sub_v(Vector2d v1, Vector2d v2) {
	Vector2d vn;
	vn.x = v1.x - v2.x;
	vn.y = v1.y - v2.y;
	return vn;
}

Vector2d s_vector_mult_s(Vector2d v, double num) {
	Vector2d vn;
	vn.x = v.x * num;
	vn.y = v.y * num;
	return vn;
}

Vector2d s_vector_mult_v(Vector2d v1, Vector2d v2) {
	Vector2d vn;
	vn.x = v1.x * v2.x;
	vn.y = v1.y * v2.y;
	return vn;
}

Vector2d s_vector_div_s(Vector2d v, double num) {
	Vector2d vn;
	vn.x = (double)v.x / num;
	vn.y = (double)v.y / num;
	return vn;
}

Vector2d s_vector_div_v(Vector2d v1, Vector2d v2) {
	Vector2d vn;
	vn.x = (double)v1.x / v2.x;
	vn.y = (double)v1.y / v2.y;
	return vn;
}

Vector2d s_vector_unit(Vector2d v) {
	double angle = vector_angle(&v);
	return s_vector_from_mag_angle(1.0, angle);
}

Vector2d s_vector_rotate(Vector2d v, double angle) {
	double rot = vector_angle(&v) + angle;
	double mag = vector_mag(&v);
	return s_vector_from_mag_angle(mag, rot);
}


Vector2d *vector_create(double x, double y) {
	Vector2d *v = malloc(sizeof(v));

	if (v == NULL) return NULL;

	v->x = x;
	v->y = y;

	return v;
}

Vector2d *vector_from_mag_angle(double mag, double angle) {
	Vector2d *v = malloc(sizeof(v));

	if (v == NULL) return NULL;

	v->x = mag * cos(angle);
	v->y = mag * sin(angle);

	return v;
}

double vector_angle(Vector2d *v) {
	return atan2(v->y, v->x);

}

double vector_mag(Vector2d *v) {
	return sqrt(pow(v->x, 2) + pow(v->y, 2));
}

void vector_add_s(Vector2d *v, double num) {
	v->x += num;
	v->y += num;
}

void vector_add_v(Vector2d *v1, Vector2d *v2) {
	v1->x += v2->x;
	v1->y += v2->y;
}

void vector_sub_s(Vector2d *v, double num) {
	v->x -= num;
	v->y -= num;
}

void vector_sub_v(Vector2d *v1, Vector2d *v2) {
	v1->x -= v2->x;
	v1->y -= v2->y;
}

void vector_mult_s(Vector2d *v, double num) {
	v->x *= num;
	v->y *= num;
}

void vector_mult_v(Vector2d *v1, Vector2d *v2) {
	v1->x *= v2->x;
	v1->y *= v2->y;
}

void vector_div_s(Vector2d *v, double num) {
	(double)v->x /= num;
	(double)v->y /= num;
}

void vector_div_v(Vector2d *v1, Vector2d *v2) {
	(double)v1->x /= v2->x;
	(double)v1->y /= v2->y;
}

double vector_angle_between(Vector2d *v1, Vector2d *v2) {
	return vector_angle(v1) - vector_angle(v2);
}

double vector_dot(Vector2d *v1, Vector2d *v2) {
	return vector_mag(v1) * vector_mag(v2) * cos(vector_angle_between(v1, v2));
}

void vector_unit(Vector2d *v) {
	double angle = vector_angle(v);
	v = vector_from_mag_angle(1.0, angle);
}

void vector_rotate(Vector2d *v, double angle) {
	double rot = vector_angle(v) + angle;
	double mag = vector_mag(v);
	v = vector_from_mag_angle(mag, rot);
}