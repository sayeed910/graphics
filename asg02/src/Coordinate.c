
// #include "Coordinate.h"

#include<stdlib.h>
#include<math.h>

struct Point{
    double x;
    double y;
    double z;
};

struct Point lightSource;


struct Point *newPoint(double x, double y, double z)
{

    struct Point *point = malloc(sizeof(struct Point));
    point->x = x;
    point->y = y;
    point->z = z;

    return point;
}

struct Point *project(struct Point point[], int pointCount, int d)
{
    struct Point* projectedPoints = malloc(sizeof(struct Point) * pointCount);

    for (int i = 0; i < pointCount; i++){
        double x = point[i].x;
        double y = point[i].y;
        double z = point[i].z;

        projectedPoints[i].x = point[i].x * d / z; 
        projectedPoints[i].y = point[i].y * d / z; 
        projectedPoints[i].z = d; 
    }

    return projectedPoints;

}

double getBrightness(struct Point* p1, struct Point* p2, struct Point* p3){

    lightSource = *(newPoint(100, 50, 30));

    int x1 = p1->x;
    int y1 = p1->y;
    int z1 = p1->z;

    int x2 = p2->x;
    int y2 = p2->y;
    int z2= p2->z;


    struct Point N;
    N.x = y1*z2 - y2*z1;
    N.y = - (x2*z1 - x1*z2);
    N.z = x1*y2 - x2*y1;


    struct Point center;
    center.x = (x1 + x2 + p3->x) / 3;
    center.y = (y1 + y2 + p3->y) / 3;
    center.z = (z1 + z2 + p3->z) / 3;


    struct Point L;
    L.x = lightSource.x - center.x;
    L.y = lightSource.y - center.y;
    L.z = lightSource.z - center.z;

    double magnitude = sqrt((N.x*N.x + N.y*N.y + N.z*N.z) * (L.x*L.x + L.y*L.y + L.z*L.z));
    double brightness = (N.x * L.x + N.y * L.y + N.z * L.z)/magnitude;

    return brightness < 0 ? 0 : brightness;
}

void scanPolyfill(struct Point* p1, struct Point* p2, struct Point* p3 ){
    
}