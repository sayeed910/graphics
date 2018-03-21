
#include "Coordinate.h"

struct Point* newPoint(double x, double y, double z){

    struct Point* point = malloc(sizeof(struct Point));
    point->x = x;
    point->y = y;
    point->z = z;

    return point;

}

struct Point* project(struct Point* point){

}