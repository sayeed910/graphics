#include "rotation.h"


int x0 = -200, _y0 = 100, x1 = 200, _y1 = 100, x2 = 200, y2 = -100, x3 = -200, y3 = -100;
double theta = 0.0174533; // radian of 1 degree

int transformX(int x, int y, int modifier){
    return x * cos(theta) - modifier * ( y * sin(theta));
}

int transformY(int x, int y, int modifier){
    return y * cos(theta) + modifier *(x * sin(theta));
}

void rotateLeft(){
    x0 = transformX(x0, _y0, 1);
    _y0 = transformY(x0, _y0, 1);
    x1 = transformX(x1, _y1, 1);
    _y1 = transformY(x1, _y1, 1);
    x2 = transformX(x2, y2, 1);
    y2 = transformY(x2, y2, 1);
    x3 = transformX(x3, y3, 1);
    y3 = transformY(x3, y3, 1);
}

void rotateRight(){
    x0 = transformX(x0, _y0, -1);
    _y0 = transformY(x0, _y0, -1);
    x1 = transformX(x1, _y1, -1);
    _y1 = transformY(x1, _y1, -1);
    x2 = transformX(x2, y2, -1);
    y2 = transformY(x2, y2, -1);
    x3 = transformX(x3, y3, -1);
    y3 = transformY(x3, y3, -1);
}

void keypressCallback(int key, int x, int y){
    switch (key){
        case 100:
        //left key
        puts("Left pressed");
        rotateLeft();
        break;
        case 102:
        //right key
        puts("Right pressed");
        rotateRight();
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