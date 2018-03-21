

#include "draw3d.h"

double x0 = -100,  _y0 = 50,   z0 = 10;
double x1 = 100,   _y1 = 50,   z1 = 10;
double x2 = 100,    y2 = -50,  z2 = 10;
double x3 = -100,   y3 = -50,  z3 = 10;

double nx0, ny0, nz0 = 10;
double nx1, ny1, nz1 = 10;
double nx2, ny2, nz2 = 10;
double nx3, ny3, nz3 = 10;



int d = 30;


void drawRectangle(int x0, int _y0, int x1, int _y1, int x2, int y2, int x3, int y3){
    glBegin(GL_LINES);
    glColor3f(1, 1.0, 1);
    glVertex2i(x0, _y0);
    glVertex2i(x1, _y1);
    glVertex2i(x1, _y1);
    glVertex2i(x2, y2);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x3, y3);
    glVertex2i(x0, _y0);
    glEnd();
}

void draw3d()
{
    drawRectangle(x0, _y0, x1, _y1, x2, y2, x3, y3);
 
    nx0 = x0 / ( 1 +  (nz0 / d));
    ny0 = _y0 / ( 1 + (nz0 / d));

    nx1 = x1 / ( 1 +  (nz1 / d));
    ny1 = _y1 / ( 1 + (nz1 / d));

    nx2 = x2 / ( 1 +  (nz2 / d));
    ny2 = y2 / ( 1 +  (nz2 / d));

    nx3 = x3 / ( 1 +  (nz3 / d));
    ny3 = y3 / ( 1 +  (nz3 / d));


    drawRectangle(nx0, ny0, nx1, ny1, nx2, ny2, nx3, ny3);
    

    glBegin(GL_LINES);
    glColor3f(1, 1.0, 1);
    glVertex2i(x0, _y0);
    glVertex2i(nx0, ny0);
    glVertex2i(x1, _y1);
    glVertex2i(nx1, ny1);
    glVertex2i(x2, y2);
    glVertex2i(nx2, ny2);
    glVertex2i(x3, y3);
    glVertex2i(nx3, ny3);
    
    glEnd();
    
    
}
        



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

    // double ntemp = nz0;
    // nz0 = transformX(ntemp, nx0, 1);
    // nx0 = transformY(ntemp, nx0, 1);
    // ntemp = nz1;
    // nz1 = transformX(ntemp, nx1, 1);
    // nx1 = transformY(ntemp, nx1, 1);
    // ntemp = nz2;
    // nz2 = transformX(ntemp, nx2, 1);
    // nx2 = transformY(ntemp, nx2, 1);
    // ntemp = nz3;
    // nz3 = transformX(ntemp, nx3, 1);
    // nx3 = transformY(ntemp, nx3, 1);
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

    // double ntemp = nz0;
    // nz0 = transformX(ntemp, nx0, -1);
    // nx0 = transformY(ntemp, nx0, -1);
    // ntemp = nz1;
    // nz1 = transformX(ntemp, nx1, -1);
    // nx1 = transformY(ntemp, nx1, -1);
    // ntemp = nz2;
    // nz2 = transformX(ntemp, nx2, -1);
    // nx2 = transformY(ntemp, nx2, -1);
    // ntemp = nz3;
    // nz3 = transformX(ntemp, nx3, -1);
    // nx3 = transformY(ntemp, nx3, -1);
}

void flipRight(){
    puts("flipeed");
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
