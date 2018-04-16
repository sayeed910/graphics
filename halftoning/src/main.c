

#include "main.h"
#include "halftoning.c"

void display();




//Main program
int main(int argc, char **argv)
{
    // halftone();
    read_image();
    glutInit(&argc, argv);
    //Simple buffer
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Line DDA");
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
    //Call to the drawing function
    
    glutDisplayFunc(display);
    // glutSpecialFunc(keypressCallback);
    glutMainLoop();
    return 0;
}

void display()
{



    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            double color = grey_image[i][j] / 255.0;
            glBegin(GL_POINTS);
            glColor3f(color, color, color);
            glVertex2d(i, HEIGHT - j);
            glEnd();
            printf("%.0lf ", color);
        }
        puts("");
            
    }
    // for (int i = 0; i < 10; i+=3){
    //     for (int j = 0; j < 15; j+=2){
    //         glBegin(GL_POINTS);
    //         glColor3f(.9, .8, .7);
    //         glVertex2d(i, j);
    //         glEnd();
    //     }
    // }
    

    
    glFlush();
}
