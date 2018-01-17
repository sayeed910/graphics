

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void display();
void draw_line(int, int, int, int);

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
    glutInitDisplayMode(GLUT_SINGLE );
    glutInitWindowPosition(50,25);
    glutInitWindowSize(640,480);
    glutCreateWindow("Line DDA");
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT );
    glOrtho(-320, 319, -240, 239, -1, 1);
    //Call to the drawing function
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void display(){

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

    int x0, x1, y0, y1;
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);


    draw_line(x0, y0, x1, y1);
    //Draw order
    glFlush();
}


void draw_line(int x0, int y0, int x1, int y1){
    float dx = x1 - x0;
    float dy = y1 - y0;
    float range;
    
    if (fabs(dx) > fabs(dy))
        range = fabs(dx);
    else
        range = fabs(dy);


        float x = x0, y = y0;
        for (int i = 0; i <= range; i++) {
            y += dy / range;
            x+= dx/ range;
            drawPixel((int) (x + .5), (int) (y + .5));
        }

}

