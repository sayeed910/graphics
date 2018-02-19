#include "rotation.h"


double x0 = -200, _y0 = 100, x1 = 200, _y1 = 100, x2 = 200, y2 = -100, x3 = -200, y3 = -100;

double z0 = 0, z1 = 0, z2 = 0, z3 = 0;

double theta = 0.0174533; // radian of 1 degree

double transformX(double x, double y, double modifier){
    return x * cos(theta) - modifier * ( y * sin(theta));
}

double transformY(double x, double y, double modifier){
    return y * cos(theta) + modifier *(x * sin(theta));
}

void rotateUp(){
    double temp;
    temp = z0;
    z0 = transformX(temp, x0, 1);
    x0 = transformY(temp, x0, 1);
    temp = z1;
    z1 = transformX(temp, x1, 1);
    x1 = transformY(temp, x1, 1);
    temp = z2;
    z2 = transformX(temp, x2, 1);
    x2 = transformY(temp, x2, 1);
    temp = z3;
    z3 = transformX(temp, x3, 1);
    x3 = transformY(temp, x3, 1);
}

void rotateDown(){
   double temp;
    temp = z0;
    z0 = transformX(temp, x0, -1);
    x0 = transformY(temp, x0, -1);
    temp = z1;
    z1 = transformX(temp, x1, -1);
    x1 = transformY(temp, x1, -1);
    temp = z2;
    z2 = transformX(temp, x2, -1);
    x2 = transformY(temp, x2, -1);
    temp = z3;
    z3 = transformX(temp, x3, -1);
    x3 = transformY(temp, x3, -1);
}

void flipRight(){
    double temp;
    temp = _y0;
    _y0 = transformX(temp, z0, 1);
    z0 = transformY(temp, z0, 1);
    temp = _y1;
    _y1 = transformX(temp, z1, 1);
    z1 = transformY(temp, z1, 1);
    temp = y2;
    y2 = transformX(temp, z2, 1);
    z2 = transformY(temp, z2, 1);
    temp = y3;
    y3 = transformX(temp, z3, 1);
    z3 = transformY(temp, z3, 1);
}

void flipLeft(){
  double temp;
    temp = _y0;
    _y0 = transformX(temp, z0, -1);
    z0 = transformY(temp, z0, -1);
    temp = _y1;
    _y1 = transformX(temp, z1, -1);
    z1 = transformY(temp, z1, -1);
    temp = y2;
    y2 = transformX(temp, z2, -1);
    z2 = transformY(temp, z2, -1);
    temp = y3;
    y3 = transformX(temp, z3, -1);
    z3 = transformY(temp, z3, -1);
}

void rotateLeft(){
    double temp;
    temp = x0;
    x0 = transformX(temp, _y0, 1);
    _y0 = transformY(temp, _y0, 1);
    temp = x1;
    x1 = transformX(temp, _y1, 1);
    _y1 = transformY(temp, _y1, 1);
    temp = x2;
    x2 = transformX(temp, y2, 1);
    y2 = transformY(temp, y2, 1);
    temp = x3;
    x3 = transformX(temp, y3, 1);
    y3 = transformY(temp, y3, 1);
}

void rotateRight(){
    double temp;
    temp = x0;
    x0 = transformX(temp, _y0, -1);
    _y0 = transformY(temp, _y0, -1);
    temp = x1;
    x1 = transformX(temp, _y1, -1);
    _y1 = transformY(temp, _y1, -1);
    temp = x2;
    x2 = transformX(temp, y2, -1);
    y2 = transformY(temp, y2, -1);
    temp = x3;
    x3 = transformX(temp, y3, -1);
    y3 = transformY(temp, y3, -1);
}

void keypressCallback(int key, int x, int y){
    switch (key){
        case 100:
        //left key
        puts("Left pressed");
        if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
            rotateUp();
        else rotateLeft();
        break;
        case 102:
        //right key
        puts("Right pressed");
        if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
            rotateDown();
        else rotateRight();
        break;
         case 101:
        //left key
        puts("Left pressed");
        flipRight();
        break;
        case 103:
        //right key
        puts("Right pressed");
        flipLeft();
        break;
    }
    
    glutPostRedisplay();
}

void displayRectangle(){
    glBegin(GL_LINES);
    glColor3f(1, 1.0, 0);
    glVertex2i(x0, _y0);
    glVertex2i(x1, _y1);
    glVertex2i(x1, _y1);
    glVertex2i(x2, y2);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x3, y3);
    glVertex2i(x0, _y0);
    glEnd();
    glFlush();

}