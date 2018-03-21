

#include "main.h"

void display();




//Main program
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    //Simple buffer
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Line DDA");
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-320, 319, -240, 239, -1, 1);
    //Call to the drawing function
    
    glutDisplayFunc(display);
    glutSpecialFunc(keypressCallback);
    glutMainLoop();
    return 0;
}

void display()
{

    // glBegin(GL_LINES);
    // glColor3f(1, 1.0, 1);
    // glVertex2i(-320, 0);
    // glVertex2i(319, 0);
    // glEnd();

    // glBegin(GL_LINES);
    // glColor3f(1, 1.0, 1);
    // glVertex2i(0, -240);
    // glVertex2i(0, 239);
    // glEnd();

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw3d();
    glFlush();
}
