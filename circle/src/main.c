

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

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
    glutMainLoop();
    return 0;
}


void drawPixels(int x, int y, int xc, int yc)
{
    drawPixel(xc + x, yc + y);
    drawPixel(xc + x, yc - y);
    drawPixel(xc - x, yc + y);
    drawPixel(xc - x, yc - y);
    drawPixel(xc + y, yc + x);
    drawPixel(xc + y, yc - x);
    drawPixel(xc - y, yc + x);
    drawPixel(xc - y, yc - x);
}

void drawCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (y >= x)
    {
        drawPixels(x, y, xc, yc);
        x++;

        if (d > 0){
            y--;
            d = d + 4 *x + 10;
        } else{
            d = d + 4 * (x - y) +6;
        }
    }
}

void display()
{

    glBegin(GL_LINES);
    glColor3f(1, 1.0, 1);
    glVertex2i(-320, 0);
    glVertex2i(319, 0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1, 1.0, 1);
    glVertex2i(0, -240);
    glVertex2i(0, 239);
    glEnd();

    int xc, yc, r;
    scanf("%d %d %d", &xc, &yc, &r);

    drawCircle(xc, yc, r);
    //Draw order
    glFlush();
}