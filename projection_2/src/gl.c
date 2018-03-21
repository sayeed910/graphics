

#include "main.h"
#include "types.h"

void display();


Point inputPoints[4000];



//Main program
int run(int argc, char **argv)
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
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw3d();
    glFlush();
}
