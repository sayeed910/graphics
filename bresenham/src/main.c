

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

int getZone(int dx, int dy){
    if (dy >= 0 && dx >= 0){
        if (dx > dy) return 0;
        return 1;
    } else if(dy > 0 && dx < 0){
        if (abs(dx) > dy) return 3;
        return 2;
    } else if(dy < 0 && dx < 0){
        if (dx > abs(dy)) return 4;
        return 5;
    } else {
        if (dx > abs(dy)) return 7;
        return 6;
    }
}

void draw_line0(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = 2 * dy - dx;
    int dE = 2 * dy;
    int dNE = 2 *(dy - dx);

    drawPixel(x0, y0);
    int x = x0, y = y0;

    while(x <= x1){
        if (d > 0){
            x++;
            y++;
            d += dNE;
        } else{
            x++;
            d += dE;
        }
    }
}
void draw_line1(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = dy - 2  * dx;
    int dN = -dx;
    int dNE = 2 *(dy - dx);

    drawPixel(x0, y0);
    int x = x0, y = y0;

    while(x <= x1){
        if (d > 0){
            x++;
            y++;
            d += dNE;
        } else{
            y++;
            d += dN;
        }
    }
}
void draw_line2(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = -dy - 2 * dx;
    int dN = -2 * dx;
    int dNW = 2 * (-dy + dx);

    drawPixel(x0, y0);
    int x = x0, y = y0;

    while(x <= x1){
        if (d > 0){
            x--;
            y++;
            d += dNW;
        } else{
            y++;
            d += dN;
        }
    }
}
void draw_line3(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = -2 * (dy + dx);
    int dW = 2 * (-dy);
    int dNW = 2 *(-dy + dx);

    drawPixel(x0, y0);
    int x = x0, y = y0;

    while(x <= x1){
        if (d > 0){
            x--;
            y++;
            d += dNW;
        } else{
            x--;
            d += dW;
        }
    }
}
// void draw_line0(int x0, int y0, int x1, int y1){
//     int dx = x1 - x0;
//     int dy = y1 - y0;
//     int d = 2 * dy - dx;
//     int dE = 2 * dy;
//     int dNE = 2 *(dy - dx);

//     drawPixel(x0, y0);
//     int x = x0, y = y0;

//     while(x <= x1){
//         if (d > 0){
//             x++;
//             y++;
//             d += dNE;
//         } else{
//             x++;
//             d += dE;
//         }
//     }
// }
// void draw_line0(int x0, int y0, int x1, int y1){
//     int dx = x1 - x0;
//     int dy = y1 - y0;
//     int d = 2 * dy - dx;
//     int dE = 2 * dy;
//     int dNE = 2 *(dy - dx);

//     drawPixel(x0, y0);
//     int x = x0, y = y0;

//     while(x <= x1){
//         if (d > 0){
//             x++;
//             y++;
//             d += dNE;
//         } else{
//             x++;
//             d += dE;
//         }
//     }
// }
// void draw_line0(int x0, int y0, int x1, int y1){
//     int dx = x1 - x0;
//     int dy = y1 - y0;
//     int d = 2 * dy - dx;
//     int dE = 2 * dy;
//     int dNE = 2 *(dy - dx);

//     drawPixel(x0, y0);
//     int x = x0, y = y0;

//     while(x <= x1){
//         if (d > 0){
//             x++;
//             y++;
//             d += dNE;
//         } else{
//             x++;
//             d += dE;
//         }
//     }
// }

void draw_line(int x0, int y0, int x1, int y1){
    float dx = x1 - x0;
    float dy = y1 - y0;
    switch( getZone(dx, dy)){
        case 0: 
            draw_line0(x0, y0, x1, y1);
            break;
        case 1: 
            draw_line1(x0, y0, x1, y1);
            break;
        case 2: 
            draw_line2(x0, y0, x1, y1);
            break;
        case 3: 
            draw_line3(x0, y0, x1, y1);
            break;
        // case 4: 
        //     draw_line4(x0, y0, x1, y1);
        //     break;
        // case 5: 
        //     draw_line5(x0, y0, x1, y1);
        //     break;
        // case 6: 
        //     draw_line6(x0, y0, x1, y1);
        //     break;
        // case 7: 
        //     draw_line7(x0, y0, x1, y1);
        //     break;
    }

}

