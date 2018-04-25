#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int width = 1300, height = 700, xax, yax, zax;
double d, m, xc, yc, zc;
int points, edges;
float x[10000];
float y[10000];
float z[10000];

typedef struct Bucket{
	int ymax;
	float slopeInv, curx;
} bucket;

int findZone(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;

	if(dx>=0 && dy>=0)//first quadrant
	{
		if(dx>dy)return 0;
		return 1;
	}else if(dx>=0 && dy<0)//fourth quadrant
	{
		if(dx>abs(dy))return 7;
		return 6;
	}else if(dx<0 && dy>=0)//second quadrant
	{
		if(abs(dx)>dy)return 3;
		return 2;
	}else//third quadrant
	{
		if(dx<dy)return 4;
		return 5;
	}
}

void drawLine(int x0, int y0, int x1, int y1)
{
	int zone = findZone(x0, y0, x1, y1);
	int dx = x1-x0;
	int dy = y1-y0;
	glBegin(GL_POINTS);
	if(zone == 0){
		int d = 2*dy-dx;
		int dE = 2*dy;
		int dNE = 2*(dy-dx);
		int x = x0, y = y0;
		do{
			glVertex2i(x,y);
			if(d<0){
				x++;
				d+=dE;
			}else{
				x++;
				y++;
				d+=dNE;
			}
		}while(x<x1);
	}
	else if(zone == 1){
		int d = dy-2*dx;
		int dN = -2*dx;
		int dNE = 2*(dy-dx);
		int x = x0, y = y0;
		do{
			glVertex2i(x,y);
			if(d<0){
				x++;
				y++;
				d+=dNE;
			}else{
				y++;
				d+=dN;
			}
		}while(y<y1);
	}
	else if(zone == 2){
		int d = -dy-2*dx;
		int dN = -dx*2;
		int dNW = -2*(dy+dx);
		int x = x0, y = y0;
		do{
			glVertex2i(x,y);
			if(d<0){
				y++;
				d += dN;
			}
			else{
				x--;
				y++;
				d+=dNW;
			}
		}while(y<y1);
	}
	else if(zone == 3){
		int d = -2*dy-dx;
		int dW = -2*dy;
		int dWN = -2*(dx+dy);
		int x=x0, y=y0;
		do{
			glVertex2i(x,y);
			if(d<0){
				x--;
				y++;
				d+=dWN;
			}
			else{
				x--;
				d+=dW;
			}
		}while(x>x1);
	}
	else if(zone == 4){
		int d = dx - 2*dy;
		int dW = -2*dy;
		int dWS = 2*(dx-dy);
		int x=x0, y=y0;
		do{
			glVertex2i(x,y);
			if(d<0){
				x--;
				d+=dW;
			}else{
				x--;
				y--;
				d+=dWS;
			}
		}while(x>x1);
	}
	else if(zone == 5){
		int d = 2*dx-dy;
		int dS = 2*dx;
		int dSW = 2*(dx-dy);
		int x=x0, y=y0;
		do{
			glVertex2i(x,y);
			if(d<0){
				x--;
				y--;
				d+=dSW;
			}else{
				y--;
				d+=dS;
			}
		}while(y>y1);
	}
	else if(zone == 6){
		int d = 2*dx+dy;
		int dS = 2*dx;
		int dSW = 2*(dx+dy);
		int x=x0, y=y0;
		do{
			glVertex2i(x,y);
			if(d<0){
				y--;
				d+=dS;
			}else{
				x++;
				y--;
				d+=dSW;
			}
		}while(y>y1);
	}
	else if(zone == 7){
		int d = 2*dy+dx;
		int dE = 2*dy;
		int dES = 2*(dx+dy);
		int x=x0, y=y0;
		do{
			glVertex2i(x,y);
			if(d<0){
				x++;
				y--;
				d+=dES;
			}else{
				x++;
				d+=dE;
			}
		}while(x<x1);
	}
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

int setColor(int a, int b, int c)
{
	float ux = x[b] - x[a];
	float uy = y[b] - y[a];
	float uz = z[b] - z[a];

	float vx = x[c] - x[b];
	float vy = y[c] - y[b];
	float vz = z[c] - z[b];

	float nx = uy*vz - uz*vy;
	float ny = uz*vx - ux*vz;
	float nz = ux*vy - uy*vz;

	float lenn = sqrt(nx*nx + ny*ny + nz*nz);
	if(lenn == 0) return 0;
	nx /= lenn;
	ny /= lenn;
	nz /= lenn;

	float lx = -(x[a] + x[b] + x[c])/3;
	float ly = -(y[a] + y[b] + y[c])/3;
	float lz = (d+m) - (z[a] + z[b] + z[c])/3;

	float ll = sqrt(lx*lx + ly*ly + lz*lz);
	lx /= ll;
	ly /= ll;
	lz /= ll;

	float sum = nx*lx + ny*ly + nz*lz;
	if(sum>=0)
	{
		glColor3f(sum, sum, sum);
		return 1;
	}
	else
	{
		glColor3f(1, 0, 0);
		return 0;
	}
}

void fillTri(int x0, int y0, int x1, int y1, int x2, int y2)
{
	int tmp;
	if(y0>y1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}
	if(y0>y2)
	{
		tmp = x0;
		x0 = x2;
		x2 = tmp;
		tmp = y0;
		y0 = y2;
		y2 = tmp;
	}
	if(y1>y2)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	bucket b01, b02, b12;
	b01.ymax = y1;
	b01.curx = x0*1.0;
	b01.slopeInv = (float)(x0-x1)/(y0-y1);

	b02.ymax = y2;
	b02.curx = x0*1.0;
	b02.slopeInv = (float)(x0-x2)/(y0-y2);

	b12.ymax = y2;
	b12.curx = x1*1.0;
	b12.slopeInv = (float)(x1-x2)/(y1-y2);

	int y;
	for(y=y0; y<y1; y++)
	{
		drawLine(b01.curx, y, b02.curx, y);
		b01.curx += b01.slopeInv;
		b02.curx += b02.slopeInv;
	}

	while(y<y2)
	{
		drawLine(b12.curx, y, b02.curx, y);
		b12.curx += b12.slopeInv;
		b02.curx += b02.slopeInv;
		y++;
	}
}

void drawCube()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);

//	drawAxis();

	double tx[3000], ty[3000];
	int i;
	for(i=0; i<points; i++)
	{
		tx[i] = x[i]*d/(z[i] + d + m);
		ty[i] = y[i]*d/(z[i] + d + m);
	}
	for(i=0; i<edges; i++)
	{
		int a = (int)x[i+points];
		int b = (int)y[i+points];
		int c = (int)z[i+points];

		glColor3f(1, 1, 1);
		glBegin(GL_TRIANGLES);
		glVertex2d(tx[a], ty[a]);
		glVertex2d(tx[b], ty[b]);
		glVertex2d(tx[c], ty[c]);
		glEnd();

		int s = setColor(a, b, c);
		fillTri(tx[a], ty[a], tx[b], ty[b], tx[c], ty[c]);
	}
}

void rotateZ(double angle)
{
	int i;
	angle = angle * 3.1416 / 180;
	for(i=0; i<points; i++)
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
	for(i=0; i<points; i++)
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
	for(i=0; i<points; i++)
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
	int i, del = 20;
	if(key == 27) exit(0);
	else if(key == 'i')
	{
		for(i=0; i<points; i++) z[i]+=del;
	}
	else if(key == 'o')
	{
		for(i=0; i<points; i++) z[i]-=del;
	}
	else if(key == 'd')
	{
		for(i=0; i<points; i++)
			x[i] = x[i] + del;
	}
	else if(key == 'a')
	{
		for(i=0; i<points; i++)
			x[i] = x[i] - del;
	}
	else if(key == 'w')
	{
		for(i=0; i<points; i++) y[i]+=del;
	}
	else if(key == 's')
	{
		for(i=0; i<points; i++) y[i]-=del;
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
	double angle = 1;

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

void load()
{
	FILE *fp;
	printf("What do you want?\n");
	printf("1. Airplane\n2. Cow\n3. Apple\n4. Hammer Head\n");
	int n, p;
	float scale;
	scanf("%d", &n);
	if(n==1)
	{
		p = 1335;
		fp = fopen("airplane.ply", "r");
		scale = 0.4;
	}
	else if(n==2)
	{
		p = 2903;
		fp = fopen("cow.ply", "r");
		scale = 100;
	}
	else if(n==3)
	{
		p = 867;
		fp = fopen("apple.ply", "r");
		scale = 4000;
	}
	else if(n==4)
	{
		p = 2564;
		fp = fopen("hammerhead.ply", "r");
		scale = 6;
	}
	else
	{
		printf("Invalid choice\n");
		exit(0);
	}
	points = 0;
	edges = 0;
	int i;
	char buffer[100];
	for(i=0; i<9; i++)
	{
		fgets(buffer, 100, fp);
	}
	do{
		fscanf(fp,"%f%f%f",&x[points], &y[points], &z[points]);
		x[points] *= scale;
		y[points] *= scale;
		z[points] *= scale;
		points++;
	}while(points<p);

	int term;
	i = p;
	do
	{
		fscanf(fp, "%d%f%f%f", &term, &x[i], &y[i], &z[i]);
		i++;
		edges++;
	}
	while(!feof(fp));
	fclose(fp);
}

int main(int argc, char *argv[])
{
	d = -2500;
	m = -1500;
	xc = 0, yc = 0, zc = 0;
	xax = 0, yax = 0, zax = 1;

	load();

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
