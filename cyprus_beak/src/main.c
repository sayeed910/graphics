

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>

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

void drawPixelC(int x, int y, double r, double g, double b){
    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    glVertex2i(x, y);
    glEnd();
}

// void drawLine(int x0, int y0, int x1, int y1, int _x0, int _y0, int _x1, int _y1)
void drawLine(int x0, int y0, int x1, int y1)
{
    glBegin(GL_LINES);
    glColor3f(1, 1.0, 1);
    glVertex2i(x0, y0);
    glVertex2i(x1, y1);
    // glColor3f(.5, 1.0, .5);
    // glVertex2i(x0, y0);
    // glVertex2i(x1, y1);
    // glColor3f(1, 1.0, 1);
    // glVertex2i(x1, y1);
    // glVertex2i(_x1, _y1);
    glEnd();
    glFlush();
}

void cyprus_( int x0, int y0, int x1, int y1){
    double tet = -(y0 - ymax)/(double)(y1 - y0);
    // printf("tet %d %d %lf \n",y0 - ymax, y1 - y0, tet);
    double teb = -(y0 - ymin)/(double)(y1 - y0);
    // printf("teb %d %d %lf \n",y0 - ymin, y1 - y0, teb);
    double tel = -(x0 - xmin)/(double)(x1 - x0);
    // printf("tel%d %d %lf \n",x0 - xmin, x1 - x0, tel);

    double ter = -(x0 - xmax)/(double)(x1 - x0);
    // printf("ter %d %d %lf \n",x0 - xmax, x1 - x0, ter);

    double dt = y1 - y0;
    double db = -y1 + y0;
    double dr = x1 - x0;
    double dl = -x1 + x0;

    double tEntering = -10000;
    double tLeaving = 10000000;

    printf("tet: %lf teb: %lf tel: %lf ter:%lf\n", tet, teb, tel, ter);
    printf("dt: %lf db: %lf dl: %lf dr:%lf\n", dt, db, dl, dr);

    if (dt > 0){//leaving
        if (tet < tLeaving)
            tLeaving = tet;
    } else {//entering
        if (tet > tEntering){
            tEntering = tet;
        }
    }

    if (db > 0){//leaving
        if (teb < tLeaving)
            tLeaving = teb;
    } else {//entering
        if (teb > tEntering){
            tEntering = teb;
        }
    }

   if (dl > 0){//leaving
        if (tel < tLeaving)
            tLeaving = tel;
    } else {//entering
        if (tel > tEntering){
            tEntering = tel;
        }
    }

    if (dr > 0){//leaving
        if (ter < tLeaving)
            tLeaving = ter;
    } else {//entering
        if (ter > tEntering){
            tEntering = ter;
        }
    }

    printf("tent: %lf tleav: %lf\n", tEntering, tLeaving);

    if (tEntering >= 0 && tEntering <= 1){
        double ptx1 = x0 + tEntering * (x1 - x0);
        double pty1 = y0 + tEntering * (y1 - y0);
        drawPixelC(ptx1, pty1, 1.0, 0, 0);
        printf("Updated P1: %lf %lf\n", ptx1, pty1);
    }

    if (tLeaving >= 0 && tLeaving <= 1){
        double ptx0 = x0 + tLeaving * (x1 - x0);
        double pty0 = y0 + tLeaving * (y1 - y0);
        drawPixelC(ptx0, pty0, 1.0, 0, 0);

        printf("Updated P0: %lf %lf\n", ptx0, pty0);
    }

    puts("");
    


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

    for (int i = 0; i < 10; i++)
    {
        int x0 = rand() % 640 - 320;
        int x1 = rand() % 640 - 320;
        int y0 = rand() % 480 - 240;
        int y1 = rand() % 480 - 240;
        
        drawLine(x0, y0, x1, y1);
        printf("x0:%d y0: %d x0: %d y1:%d\n", x0, y0, x1, y1);
        cyprus_(x0, y0, x1, y1);
        glFlush();
    }
    // // int x0 = -217, y0 =57, x1 = 6, y1 = -125;
    // int x0 = -317, y0 =57, x1 = 6, y1 = -225;
    // drawLine(x0, y0, x1, y1);
    //     printf("x0:%d y0: %d x0: %d y1:%d\n", x0, y0, x1, y1);
    //     cyprus_(x0, y0, x1, y1);

   
    glFlush();
}