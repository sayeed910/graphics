#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

int a0, b0, a1, b1;

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-320, 319, -240, 239, -1, 1);
}

// int _round(float x)
// {
// 	double dif = x - (int) x;
// 	if(dif >= 0.5) return (int)x + 1;
// 	else return (int) x;
// }

int getZone(int dx, int dy)
{

	if(dx > 0 && dy > 0)
	{
		if(dx >= dy)
			return 0;
		else
			return 1;
	}
	
	else if(dx < 0 && dy > 0)
	{
		if(abs(dx) >= dy)
			return 3;
		else
			return 2;
	}
	
	else if(dx < 0 && dy < 0)
	{
		if(abs(dx) >= abs(dy))
			return 4;
		else
			return 5;
	}
	
	else if(dx > 0 && dy < 0)
	{
		if(dx >= abs(dy))
			return 7;
		else
			return 6;
	}
}

void drawLine(void)
{
	puts("61:");
	int dx = a1 - a0;
	int dy = b1 - b0;
	int zone = getZone(dx, dy);
    printf("63: %d %d\n", dx, dy);
	double m = dy/dx;

	
	
	// if(zone == 0)
	{
	printf("ffijkfjanf\n");
		int d = 2 * dy - dx;
		int dE = 2 * dy;
		int dNE = 2 * (dy - dx);
		int x = a0, y = b0;
		glVertex2i(x, y);
		
		while(x < a1)
		{
			if ( d < 0)
			{
				//East
				x++; 
				d += dE;
			}
			
			else
			{
				//North-East
				x++;
				y++;
				d += dNE;
			}
			glVertex2i(x, y);
		}
	}
		
	
}

void renderScene(void) {
	
	
	glBegin(GL_POINTS);
	glColor3f(0, 1.0, 0);
		drawLine();
	glEnd();
	glFlush();
	// glutSwapBuffers();
}

int main(int argc, char** argv)
{
	scanf("%d %d %d %d", &a0, &a1, &b0, &b1);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Pixel Draw");
	myInit();
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT );
	//Call to the drawing function
	glutDisplayFunc(renderScene);
	
	glutMainLoop();
	return 1;
}