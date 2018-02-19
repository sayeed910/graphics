

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>

int TOP = 8, BOTTOM = 4, RIGHT = 2, LEFT = 1;
int xmax = 300, xmin = -300, ymax = 200, ymin = -200;

void display();
void draw_circle(int, int, int);

//Drawing funciton
void drawPixel(int x, int y)
{
    //Background color

    glBegin(GL_POINTS);
    glColor3f(0, 1.0, 0);
    glVertex2i(x, y);
    glEnd();
}

void drawLine(int x0, int y0, int x1, int y1, int _x0, int _y0, int _x1, int _y1)
{
    glBegin(GL_LINES);
    glColor3f(1, 1.0, 1);
    glVertex2i(_x0, _y0);
    glVertex2i(x0, y0);
    glColor3f(.5, 1.0, .5);
    glVertex2i(x0, y0);
    glVertex2i(x1, y1);
    glColor3f(1, 1.0, 1);
    glVertex2i(x1, y1);
    glVertex2i(_x1, _y1);
    glEnd();
    glFlush();
}

int makeCode(int x, int y)
{
    int code = 0;

    if (y > ymax)
        code |= TOP;
    else if (y < ymin)
        code |= BOTTOM;

    if (x > xmax)
        code |= RIGHT;
    else if (x < xmin)
        code |= LEFT;

    return code;
}

void cohen(int x0, int y0, int x1, int y1)
{
    int _x0 = x0, _x1 = x1, _y0 = y0, _y1 = y1;
    int code, x, y;

 
    int count = 10;
    while (1 && count--)
    {
        int code0 = makeCode(x0, y0);
        int code1 = makeCode(x1, y1);

        
        printf("%d %d %d %d\n", x0, y0, x1, y1);
        printf("%d %d\n", code0, code1);

        if (!(code0 | code1))
        {
            puts("Calling draw line");
            drawLine(x0, y0, x1, y1, _x0, _y0, _x1, _y1);
            printf("Accepted\n");
            return;
        }
        else if (code0 & code1)
        {
            puts("Rejected");
            return;
        }
        else
        {
            if (code1)
                code = code1;
            else
                code = code0;

            // if (code & TOP)
            // {
            //     y = ymax;
            //     x = x0 + (((y - y0) * (x1 - x0)) / (y1 - y0));
            // }
            // else if (code & BOTTOM)
            // {
            //     y = ymin;
            //     x = x0 + (((y - y0) * (x1 - x0)) / (y1 - y0));
            // }
            // else if (code & RIGHT)
            // {
            //     x = xmax;
            //     y = y0 + (((x - x0) * (y1 - y0)) / (x1 - x0));
            // }
            // else if (code & LEFT)
            // {
            //     x = xmin;
            //     y = y0 + (((x - x0) * (y1 - y0)) / (x1 - x0));
            // }

            if (code & TOP) {           // point is above the clip window
                puts("top");
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
                printf("converted: %d %d\n", x, y);
			} else if (code & BOTTOM) { // point is below the clip window
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			} else if (code & RIGHT) {  // point is to the right of clip window
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			} else if (code & LEFT) {   // point is to the left of clip window
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}

            printf("%d %d %d \n", code, code0, code1);
            if (code == code1)
            {
                x1 = x;
                y1 = y;
                printf("code1: %d %d\n", x1, y1);
            }
            else
            {
                x0 = x;
                y0 = y;
                printf("code0: %d %d\n", x0, y0);
            }
        }
    }
}

//Main program
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    //Simple buffer
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Line Clipping");
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-320, 319, -240, 239, -1, 1);
    //Call to the drawing function
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void display()
{

    glBegin(GL_LINES);
    glColor3f(1, 1.0, 1);
    glVertex2i(xmin, ymax);
    glVertex2i(xmax, ymax);
    glVertex2i(xmax, ymax);
    glVertex2i(xmax, ymin);
    glVertex2i(xmax, ymin);
    glVertex2i(xmin, ymin);
    glVertex2i(xmin, ymin);
    glVertex2i(xmin, ymax);
    glEnd();

    for (int i = 0; i < 1000; i++)
    {
        int x0 = rand() % 640 - 320;
        int x1 = rand() % 640 - 320;
        int y0 = rand() % 480 - 240;
        int y1 = rand() % 480 - 240;
        
        // glBegin(GL_LINES);
        // glColor3f(1, 1.0, 1);
        // glVertex2i(x0, y0);
        // glVertex2i(x1, y1);
        // glEnd();
        // glFlush();
        cohen(x0, y0, x1, y1);
        glFlush();
    }

    // cohen(-13, 89, 95, 42);

    // cohen(30, 50, -40, -50);
    // drawCircle(xc, yc, r);
    //Draw order
    glFlush();
}