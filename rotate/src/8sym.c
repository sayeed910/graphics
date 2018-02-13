#include "8sym.h"

//Drawing funciton
void drawPixel(int x, int y)
{
    //Background color

    glBegin(GL_POINTS);
    glColor3f(0, 1.0, 0);
    glVertex2i(x, y);
    glEnd();

}

int getZone(int dx, int dy)
{
    if (dy >= 0 && dx >= 0)
    {
        if (dx > dy)
            return 0;
        return 1;
    }
    else if (dy > 0 && dx < 0)
    {
        if (abs(dx) > dy)
            return 3;
        return 2;
    }
    else if (dy < 0 && dx < 0)
    {
        if (dx > abs(dy))
            return 4;
        return 5;
    }
    else
    {
        if (dx > abs(dy))
            return 7;
        return 6;
    }
}

int *transformFrom0(int x0, int y0, int zone)
{
    int *points = malloc(2 * sizeof(int));
    switch (zone)
    {
    case 0:
        points[0] = x0;
        points[1] = y0;
        break;

    case 1:
        points[0] = y0;
        points[1] = x0;
        break;

    case 2:
        points[0] = -y0;
        points[1] = x0;
        break;

    case 3:
        points[0] = -x0;
        points[1] = y0;
        break;

    case 4:
        points[0] = -x0;
        points[1] = -y0;
        break;

    case 5:
        points[0] = -y0;
        points[1] = -x0;
        break;

    case 6:
        points[0] = y0;
        points[1] = -x0;
        break;

    case 7:
        points[0] = x0;
        points[1] = -y0;
        break;
    }

    return points;
}

int *transformTo0(int x0, int y0, int zone)
{
    int *points = malloc(2 * sizeof(int));
    switch (zone)
    {
    case 0:
        points[0] = x0;
        points[1] = y0;
        break;
    case 1:
        points[0] = y0;
        points[1] = x0;
        break;
    case 2:
        points[0] = y0;
        points[1] = -x0;
        break;
    case 3:
        points[0] = -x0;
        points[1] = y0;
        break;
    case 4:
        points[0] = -x0;
        points[1] = -y0;
        break;
    case 5:
        points[0] = -y0;
        points[1] = -x0;
        break;
    case 6:
        points[0] = -y0;
        points[1] = x0;
        break;
    case 7:
        points[0] = x0;
        points[1] = -y0;
        break;
    }

    printf("transformto0: %d %d\n", points[0], points[1]);
    return points;
}

void draw_line0(int x0, int y0, int x1, int y1, int zone)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = 2 * dy - dx;
    int dE = 2 * dy;
    int dNE = 2 * (dy - dx);

    int x = x0, y = y0;
    int *points = transformFrom0(x, y, zone);
    drawPixel(points[0], points[1]);

    while (x <= x1)
    {
        if (d > 0)
        {
            x++;
            y++;
            d += dNE;
        }
        else
        {
            x++;
            d += dE;
        }

        points = transformFrom0(x, y, zone);
        drawPixel(points[0], points[1]);
    }
}

void draw_line(int x0, int y0, int x1, int y1)
{
    int zone = getZone(x1 - x0, y1 - y0);
    int *points1 = transformTo0(x0, y0, zone);
    int *points2 = transformTo0(x1, y1, zone);
    printf("%d %d %d %d %d\n", points1[0], points1[1], points2[0], points2[1], -(-1));
    draw_line0(points1[0], points1[1], points2[0], points2[1], zone);
    
}


