
// #include "ply_handling.h"
// #include "types.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "main.h"

int xc = 0, yc = 0, zc = 0;

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

Point points[3000];
Face faces[6000];
Point projectedPoints[3000];

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
        printf("%s\n", s);
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

       

    if (!cow){
        projectedPoints[i].x = d * x  / (4000 + z) ;
        projectedPoints[i].y = d * y  / (4000 + z) ;
        projectedPoints[i].z = d * z  / (4000 + z) ;
    } else{
         projectedPoints[i].x = d * x * 100 / (4000 + z);
        projectedPoints[i].y = d * y * 100 / (4000 + z);
        projectedPoints[i].z = d * z * 100 / (4000 + z);

    }

        printf("%lf %lf %lf\n", projectedPoints[i].x, projectedPoints[i].y, projectedPoints[i].z);
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

        printf("%lf %lf\n", p1.x, p1.y);

        glBegin(GL_LINES);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
        glVertex2f(p2.x, p2.y);
        glVertex2f(p3.x, p3.y);
        glVertex2f(p3.x, p3.y);
        glVertex2f(p1.x, p1.y);
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


void display()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawShape(faces, projectedPoints, pictureData.face_count);
    glFlush();
}

void keypressCallback(int key, int x, int y)
{
    switch (key)
    {

    case 100:
        //left key
        puts("Left pressed");
        if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
            rotateY(10);
        else
            rotateZ(10);
        break;
    case 102:
        //right key
        puts("Right pressed");
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

//Main program
int main(int argc, char **argv)
{

    readData("../airplane.ply", points, faces);
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
    glutSpecialFunc(keypressCallback);
    glutMainLoop();
    return 0;
}
