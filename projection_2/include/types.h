
typedef struct{
    double x, y, z;
} Point;


void rotateZ(double angle)
{
    int i;
    angle = angle * 3.1416 / 180;
    for (i = 0; i < pictureData.vertex_count; i++)
    {

        double dx = projectedPoints[i].x - xc;
        double dy = projectedPoints[i].y - yc, tmp;

        printf("%lf %lf", dx, dy);

        tmp = dx * cos(angle) - dy * sin(angle);
        dy = dy * cos(angle) + dx * sin(angle);
        dx = tmp;

        projectedPoints[i].x = xc + dx;
        projectedPoints[i].y = yc + dy;

        printf("%lf %lf\n", projectedPoints[i].x, projectedPoints[i].y);
    }
}

void rotateY(double angle)
{
    int i;
    angle = angle * 3.1416 / 180;
    for (i = 0; i < pictureData.vertex_count; i++)
    {
        double dx = projectedPoints[i].x;
        double dz = projectedPoints[i].z, tmp;

        tmp = dz * cos(angle) - dx * sin(angle);
        dx = dx * cos(angle) + dz * sin(angle);
        dz = tmp;

        projectedPoints[i].x = dx;
        projectedPoints[i].z = dz;
    }
}

void rotateX(double angle)
{
    int i;
    angle = angle * 3.1416 / 180;
    for (i = 0; i < pictureData.vertex_count; i++)
    {
        double dy = projectedPoints[i].y;
        double dz = projectedPoints[i].z, tmp;

        tmp = dz * cos(angle) - dy * sin(angle);
        dy = dy * cos(angle) + dz * sin(angle);
        dz = tmp;

        projectedPoints[i].y = dy;
        projectedPoints[i].z = dz;
    }
}
