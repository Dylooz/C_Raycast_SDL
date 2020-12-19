#include <stdlib.h>
#include <stdio.h>

#include "vec2d.h"

int main(int argc, char **argv) {
	Vector2d v = vector_create(1, 1);
	printf("%f %f\n", v.x, v.y);
	return 0;
}
