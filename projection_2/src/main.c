
// #include "ply_handling.h"
// #include "types.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "main.h"

int xc = 0, yc = 0, zc = 0;
int d = -2500, m = -1500;

typedef struct
{
    double x, y, z;
} Point;

typedef struct
{
    int v1, v2, v3;
} Face;

typedef struct
{
    int vertex_count, face_count;
} Data;

typedef struct
{
<<<<<<< HEAD
    double curx, ymax, ymin, slopeInv;
=======
    int ymax;
    double current_x, slopeInv;
>>>>>>> 66d76bd4d9ce137a7519dcaef23c8d1b08feabfe
} Edge;

Point points[3000];
Face faces[6000];
Point projectedPoints[3000];
Point lightSource;

int cow = 0;

Data pictureData;

void readData(const char *file_name, Point points[], Face faces[])
{
    FILE *file = fopen(file_name, "r");

    int vertex_count;
    int face_count;

    if (strcmp(file_name, "../cow.ply") == 0)
    {
        cow = 1;
        vertex_count = 2903;
        face_count = 5804;
    }
    else
    {
        vertex_count = 1335;
        face_count = 2452;
    }

    pictureData.face_count = face_count;
    pictureData.vertex_count = vertex_count;

    char s[1000];
    int line = 1;
    while (line++)
    {
        fscanf(file, "%s", s);
        // printf("%s\n", s);
        if (strcmp(s, "end_header") == 0)
            break;
    }

    for (int i = 0; i < vertex_count; i++)
    {
        double x, y, z;
        fscanf(file, "%lf %lf %lf", &x, &y, &z);

        points[i].x = x;
        points[i].y = y;
        points[i].z = z;
    }

    for (int i = 0; i < face_count; i++)
    {
        double v, x, y, z;
        fscanf(file, "%lf %lf %lf %lf", &v, &x, &y, &z);

        faces[i].v1 = x;
        faces[i].v2 = y;
        faces[i].v3 = z;
    }
}

void project(Point points[], Point projectedPoints[], int pointCount)
{
    double d = 2500;
    for (int i = 0; i < pointCount; i++)
    {
        double z = points[i].z;
        double x = points[i].x;
        double y = points[i].y;

        if (!cow)
        {
            projectedPoints[i].x = d * x / (4000 + z);
            projectedPoints[i].y = d * y / (4000 + z);
            projectedPoints[i].z = d * z / (4000 + z);
        }
        else
        {
            projectedPoints[i].x = d * x * 100 / (4000 + z);
            projectedPoints[i].y = d * y * 100 / (4000 + z);
            projectedPoints[i].z = d * z * 100 / (4000 + z);
        }

<<<<<<< HEAD
        printf("%lf %lf %lf\n", projectedPoints[i].x, projectedPoints[i].y, projectedPoints[i].z);
    }
}

Edge makeEdge(Point p1, Point p2)
{
    Edge e;

    if (p1.y > p2.y)
    {
        e.ymax = p1.y;
        e.ymin = p2.y;
        e.curx = p2.x;
        e.slopeInv = (p1.y - p2.y) != 0 ? (p1.x - p2.x) / (p1.y - p2.y) : 0;
    }
    else
    {
        e.ymax = p2.y;
        e.ymin = p1.y;
        e.curx = p1.x;
        e.slopeInv = (p2.y - p1.y) != 0 ? (p2.x - p1.x) / (p2.y - p1.y) : 0;
    }

    return e;
}

double min(double a, double b, double c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

double max(double a, double b, double c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

void fill(Point p1, Point p2, Point p3)
{

    Edge edges[3];

    Edge *edgeTable[2] = {NULL};

    edges[0] = makeEdge(p1, p2);
    edges[1] = makeEdge(p2, p3);
    edges[2] = makeEdge(p3, p1);

    double ymin = min(p1.y, p2.y, p3.y);
    double ymax = max(p1.y, p2.y, p3.y);

    for (int i = 0; i < 3; i++)
    {
        if (edges[i].ymin == ymin)
        {
            if (edgeTable[0] == NULL)
                edgeTable[0] = &edges[i];
            else
                edgeTable[1] = &edges[i];
        }
    }

    for (int y = ymin; y <= ymax; y++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (edgeTable[i]->ymax == y)
            {
                for (int j = 0; i < 3; i++)
                {
                    if (edges[j].ymin == y)
                    {
                        edgeTable[i] = &edges[i];
                    }
                }
            }

            glBegin(GL_LINES);
            glVertex2f(edgeTable[0]->curx, y);
            glVertex2f(edgeTable[1]->curx, y);

            glEnd();

            edgeTable[0]->curx += edgeTable[0]->slopeInv;
            edgeTable[1]->curx += edgeTable[1]->slopeInv;
        }
=======
        // printf("%lf %lf %lf\n", projectedPoints[i].x, projectedPoints[i].y, projectedPoints[i].z);
    }
}

void drawLine(double x1, double y1, double x2, double y2, double color){
    glColor3f(color, color, color);
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();
}

Point make_point(double x, double y, double z)
{
    Point p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

// Edge make_edge(int ymax, double cx, double slopeInv)
// {
//     Edge e;
//     e.ymax = ymax;
//     e.current_x = cx;
//     e.slopeInv = slopeInv;

//     return e;
// }

Edge make_edge(Point phigh, Point plow)
{
    Edge e;
    e.ymax = phigh.y;
    e.current_x = plow.x;
    double dx = phigh.x - plow.x;
    double dy = phigh.y - plow.y;

    if (dy == 0)
        e.slopeInv = 1;
    if (dx == 0)
        e.slopeInv = 0;

    if (dy != 0 && dx != 0)
        e.slopeInv = dx/dy;


    return e;
}



double get_color(Point p1, Point p2, Point p3)
{
    
	float ux = p2.x - p1.x;
	float uy = p2.y - p1.y;
	float uz = p2.z - p1.z;

	float vx = p3.x - p1.x;
	float vy = p3.y - p1.y;
	float vz = p3.z - p1.z;

	float nx = uy*vz - uz*vy;
	float ny = uz*vx - ux*vz;
	float nz = ux*vy - uy*vz;

	float lenn = sqrt(nx*nx + ny*ny + nz*nz);
	if(lenn == 0) return 0;
	nx /= lenn;
	ny /= lenn;
	nz /= lenn;

	float lx = lightSource.x -(p1.x + p2.x + p3.x)/3;
	float ly = lightSource.y -(p1.y + p2.y + p3.y)/3;
	float lz = lightSource.z - (p1.z + p2.z + p3.z)/3;
    printf("lx%lf ly%lf lz%lf\n", lx, ly, lz);
    // float lz = (p1.z + p2.z + p3.z)/3;

	float ll = sqrt(lx*lx + ly*ly + lz*lz);
    if(ll == 0) return 0;
	lx /= ll;
	ly /= ll;
	lz /= ll;

	double color = nx*lx + ny*ly + nz*lz;

	return color < 0 ? 0 : color;
}

void fill(Point p1, Point p2, Point p3)
{
    Point temp;
    if (p1.y > p2.y)
    {
        temp = p1;
        p1 = p2;
        p2 = temp;
    }

    if (p2.y > p3.y)
    {
        temp = p2;
        p2 = p3;
        p3 = temp;
    }

    if (p1.y > p2.y)
    {
        temp = p1;
        p1 = p2;
        p2 = temp;
    }

//    printf("yval: %lf %lf %lf\n", p1.y, p2.y, p3.y);

    Edge e12, e13, e23;
    // e12 = make_edge(p2.y, p1.x, (p1.x - p2.x) / (p1.y - p2.y));
    // e13 = make_edge(p3.y, p1.x, (p1.x - p3.x) / (p1.y - p3.y));
    // e23 = make_edge(p3.y, p2.x, (p2.x - p3.x) / (p2.y - p3.y));

    e12 = make_edge(p2, p1);
    e13 = make_edge(p3, p1);
    e23 = make_edge(p3, p2);


    double color = get_color(p1, p2, p3);
//    color = 1;

    // printf("%lf %lf %lf\n", e12.current_x, e13.current_x, p1.y);
    int y;
    for (y = p1.y; y < (int)p2.y; y++)
    {
        drawLine(e12.current_x, y, e13.current_x, y, color);
       
        e12.current_x += e12.slopeInv;
        e13.current_x += e13.slopeInv;
    }
    while (y < (int)p3.y)
    {
        drawLine(e23.current_x, y, e13.current_x, y, color);
        e23.current_x += e23.slopeInv;
        e13.current_x += e13.slopeInv;
        y++;
>>>>>>> 66d76bd4d9ce137a7519dcaef23c8d1b08feabfe
    }
}

void drawShape(Face faces[], Point points[], int face_count)
{

    // return;

    glColor3f(.5, .5, .5);

    for (int i = 0; i < face_count; i++)
    {
        Point p1 = points[faces[i].v1];
        Point p2 = points[faces[i].v2];
        Point p3 = points[faces[i].v3];

        // printf("%lf %lf\n", p1.x, p1.y);

        glBegin(GL_LINES);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
        glVertex2f(p2.x, p2.y);
        glVertex2f(p3.x, p3.y);
        glVertex2f(p3.x, p3.y);
        glVertex2f(p1.x, p1.y);
        fill(p1, p2, p3);
        glEnd();
    }
}

void rotateZ(double angle)
{
    int i;
    angle = angle * 3.1416 / 180;
    for (i = 0; i < pictureData.vertex_count; i++)
    {

        double dx = projectedPoints[i].x - xc;
        double dy = projectedPoints[i].y - yc, tmp;

        // printf("%lf %lf", dx, dy);

        tmp = dx * cos(angle) - dy * sin(angle);
        dy = dy * cos(angle) + dx * sin(angle);
        dx = tmp;

        projectedPoints[i].x = xc + dx;
        projectedPoints[i].y = yc + dy;

        // printf("%lf %lf\n", projectedPoints[i].x, projectedPoints[i].y);
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

void display()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POINTS);
    glVertex2d(lightSource.x, lightSource.y);
    glEnd();

    drawShape(faces, projectedPoints, pictureData.face_count);
    glFlush();
}

void keypressCallback(int key, int x, int y)
{
    switch (key)
    {

    case 100:
        //left key
        // puts("Left pressed");
        if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
            rotateY(10);
        else
            rotateZ(10);
        break;
    case 102:
        //right key
        // puts("Right pressed");
        rotateX(10);
        break;
        // else rotateRight();
        // break;
        //  case 101:
        // //left key
        // puts("Left pressed");
        // flipRight();
        // break;
        // case 103:
        // //right key
        // puts("Right pressed");
        // flipLeft();
        // break;
    
    }

    glutPostRedisplay();
}

void keypress(unsigned char key, int x, int y){
    switch(key){
    case 'x':
        
        lightSource.x += 5;
        break;
    case 'y':
        lightSource.y += 5;
        break;
    case 'z':
        lightSource.z += 5;
        break;
    case 'q':
        
        lightSource.x -= 5;
        break;
    case 'w':
        lightSource.y -= 5;
        break;
    case 'e':
        lightSource.z -= 5;
        break;
    }
    glutPostRedisplay();
}

//Main program
int main(int argc, char **argv)
{

    readData("../airplane.ply", points, faces);
    lightSource = make_point(0, 0, d+m);
    project(points, projectedPoints, pictureData.vertex_count);

    glutInit(&argc, argv);
    //Simple buffer
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Line DDA");
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-1000, 1000, -1000, 1000, -1, 1);
    //Call to the drawing function

    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    glutSpecialFunc(keypressCallback);
    glutMainLoop();
    return 0;
}
