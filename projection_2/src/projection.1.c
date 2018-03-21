#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int width = 1300, height = 700, xax, yax, zax;
double d, xc, yc, zc;
double x[8];
double y[8];
double z[8];

void drawLine(int x0, int y0, int x1, int y1)
{
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}

void drawAxis()
{
	glBegin(GL_LINES);
	glVertex2i(-width/2, 0);
	glVertex2i(width/2, 0);
	glVertex2i(0, -height/2);
	glVertex2i(0, height/2);
	glEnd();
}

void drawCube()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);

	drawAxis();

	double tx[8], ty[8];
	int i;
	for(i=0; i<8; i++)
	{
		tx[i] = x[i]/(1+z[i]/d);
		ty[i] = y[i]/(1+z[i]/d);
	}

	drawLine(tx[0], ty[0], tx[1], ty[1]);
	drawLine(tx[1], ty[1], tx[2], ty[2]);
	drawLine(tx[2], ty[2], tx[3], ty[3]);
	drawLine(tx[3], ty[3], tx[0], ty[0]);

	drawLine(tx[4], ty[4], tx[5], ty[5]);
	drawLine(tx[5], ty[5], tx[6], ty[6]);
	drawLine(tx[6], ty[6], tx[7], ty[7]);
	drawLine(tx[7], ty[7], tx[4], ty[4]);

	drawLine(tx[0], ty[0], tx[4], ty[4]);
	drawLine(tx[1], ty[1], tx[5], ty[5]);
	drawLine(tx[2], ty[2], tx[6], ty[6]);
	drawLine(tx[3], ty[3], tx[7], ty[7]);
}

void rotateZ(double angle)
{
	int i;
	angle = angle * 3.1416 / 180;
	for(i=0; i<8; i++)
	{
		double dx = x[i] - xc;
		double dy = y[i] - yc, tmp;

		tmp = dx*cos(angle) - dy*sin(angle);
		dy = dy*cos(angle) + dx*sin(angle);
		dx = tmp;

		x[i] = xc + dx;
		y[i] = yc + dy;
	}
}

void rotateY(double angle)
{
	int i;
	angle = angle * 3.1416 / 180;
	for(i=0; i<8; i++)
	{
		double dx = x[i] - xc;
		double dz = z[i] - zc, tmp;

		tmp = dz*cos(angle) - dx*sin(angle);
		dx = dx*cos(angle) + dz*sin(angle);
		dz = tmp;

		x[i] = xc + dx;
		z[i] = zc + dz;
	}
}

void rotateX(double angle)
{
	int i;
	angle = angle * 3.1416 / 180;
	for(i=0; i<8; i++)
	{
		double dy = y[i] - yc;
		double dz = z[i] - zc, tmp;

		tmp = dy*cos(angle) - dz*sin(angle);
		dz = dz*cos(angle) + dy*sin(angle);
		dy = tmp;

		y[i] = yc + dy;
		z[i] = zc + dz;
	}
}

void display()
{

	drawCube();

	glFlush();
}

void keyL(unsigned char key, int xa, int ya)
{
	int i, del = 5;
	if(key == 27) exit(0);
	else if(key == 'i')
	{
		for(i=0; i<8; i++) z[i]+=del;
	}
	else if(key == 'o')
	{
		for(i=0; i<8; i++) z[i]-=del;
	}
	else if(key == 'd')
	{
		for(i=0; i<8; i++)
			x[i] = x[i] + del;
	}
	else if(key == 'a')
	{
		for(i=0; i<8; i++)
			x[i] = x[i] - del;
	}
	else if(key == 'w')
	{
		for(i=0; i<8; i++) y[i]+=del;
	}
	else if(key == 's')
	{
		for(i=0; i<8; i++) y[i]-=del;
	}
	else if(key == 'x')
	{
		xax = 1;
		yax = 0;
		zax = 0;
	}
	else if(key == 'y')
	{
		xax = 0;
		yax = 1;
		zax = 0;
	}
	else if(key == 'z')
	{
		xax = 0;
		yax = 0;
		zax = 1;
	}
	drawCube();
	glFlush();
}

void spec(int key, int xa, int ya)
{
	/*xc = (x[0] + x[3])/2;
	yc = (y[0] + y[4])/2;
	zc = (z[0] + z[1])/2;*/
	xc = 0, yc = 0, zc = 0;
	double angle = 10;

	if(key == GLUT_KEY_RIGHT)
	{
		if(xax) rotateX(-angle);
		else if(yax) rotateY(-angle);
		else if(zax) rotateZ(-angle);
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(xax) rotateX(angle);
		else if(yax) rotateY(angle);
		else if(zax) rotateZ(angle);
	}
	drawCube();
	glFlush();
}

int main(int argc, char *argv[])
{
	double xx[8] = {100, 100, -100, -100, 100, 100, -100, -100};
	memcpy(x, xx, sizeof(xx));
	double yy[8] = {100, 100, 100, 100, -100, -100, -100, -100};
	memcpy(y, yy, sizeof(yy));
	double zz[8] = {100, 200, 200, 100, 100, 200, 200, 100};
	memcpy(z, zz, sizeof(zz));
	d = 1000;
	xc = 0, yc = 0, zc = 0;
	xax = 0, yax = 0, zax = 1;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Projection");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width/2, width/2, -height/2, height/2);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyL);
	glutSpecialFunc(spec);
	glutMainLoop();
	return 0;
}
