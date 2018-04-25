

#include "main.h"
#include "halftoning.c"

void display_color();
void display_greyscale();
void display_halftone();

//Main program
int main(int argc, char **argv)
{

    halftone("../Lion.bmp");
    // read_image("../images/baboon.ascii.pgm");
    glutInit(&argc, argv);
    //Simple buffer
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(width, height);
    glutCreateWindow("Color");
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(0, width, 0, height, -1, 1);
    //Call to the drawing function

    glutDisplayFunc(display_color);
    // glutSpecialFunc(keypressCallback);

    glutCreateWindow("GreyScale");
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(0, width, 0, height, -1, 1);
    //Call to the drawing function

    glutDisplayFunc(display_greyscale);
    glutCreateWindow("HalfTone");
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(0, width, 0, height, -1, 1);
    //Call to the drawing function

    glutDisplayFunc(display_halftone);
    glutMainLoop();
    return 0;
}

void display_color()
{

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Pixel pixel = color_image[i][j];
            glBegin(GL_POINTS);
            glColor3f(pixel.r / 255, pixel.g / 255.0, pixel.b/ 255.0);
            glVertex2d(j, i);
            glEnd();
            // printf("%.0lf ", color);
        }
        // puts("");
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

void display_greyscale()
{

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double color = grey_image[i][j] / 255.0;
            glBegin(GL_POINTS);
            glColor3f(color, color, color);
            glVertex2d(j, i);
            glEnd();
            // printf("%.0lf ", color);
        }
        // puts("");
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

void display_halftone()
{

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double color = halftone_image[i][j] / 255.0;
            glBegin(GL_POINTS);
            glColor3f(color, color, color);
            glVertex2d(j, i);
            glEnd();
            // printf("%.0lf ", color);
        }
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
