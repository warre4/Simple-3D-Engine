// ---------------------------------------------------------------------------------------------------------------------------
// -- This file started out as a copy from this one: https://github.com/3DSage/OpenGL-Starter_v1/blob/main/3DSage_Starter.c --
// -- but is meant to change drastically -------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------------------------

#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

#include "color.h"

#define res											1														//0=160x120 1=360x240 4=640x480
#define SW											160*res													//screen width
#define SH											120*res													//screen height
#define SW2											(SW/2)													//half of screen width
#define SH2											(SH/2)													//half of screen height
#define pixelScale									4/res													//OpenGL pixel scale
#define GLSW										(SW*pixelScale)											//OpenGL window width
#define GLSH										(SH*pixelScale)											//OpenGL window height

// ---------------------------------------------------------------------------------------------------------------------------

typedef struct
{
	int fr1, fr2;				//frame 1 frame 2, to create constant frame rate
}Time; Time T;

typedef struct
{
	int w, s, a, d;				//move up, down, left, right
	int sl, sr;					//strafe left, right
	int m;						//move up, down, look up, down
}Keys; Keys K;

// ---------------------------------------------------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------------------------------------------------

void pixel(int x, int y, int c)			//draw a pixel at x/y with rgb
{
	Color color;
	color.a = 0xFF;
	
	if (c == 0)	{ SetColorRGB(&color, Yellow		); }
	if (c == 1)	{ SetColorRGB(&color, YellowDark	); }
	if (c == 2)	{ SetColorRGB(&color, Green			); }
	if (c == 3)	{ SetColorRGB(&color, GreenDark		); }
	if (c == 4)	{ SetColorRGB(&color, Cyan			); }
	if (c == 5)	{ SetColorRGB(&color, CyanDark		); }
	if (c == 6)	{ SetColorRGB(&color, Brown			); }
	if (c == 7)	{ SetColorRGB(&color, BrownDark		); }
	if (c == 8)	{ SetColorRGB(&color, DefaultBlue	); }

	glColor3ub(color.r, color.g, color.b);
	
	glBegin(GL_POINTS);
	glVertex2i(x * pixelScale + 2, y * pixelScale + 2);
	glEnd();
}

void movePlayer()
{
	//move up, down, left, right
	if (K.a == 1 && K.m == 0) { printf("left\n"); }
	if (K.d == 1 && K.m == 0) { printf("right\n"); }
	if (K.w == 1 && K.m == 0) { printf("up\n"); }
	if (K.s == 1 && K.m == 0) { printf("down\n"); }
	//strafe left, right
	if (K.sr == 1) { printf("strafe left\n"); }
	if (K.sl == 1) { printf("strafe right\n"); }
	//move up, down, look up, look down
	if (K.a == 1 && K.m == 1) { printf("look up\n"); }
	if (K.d == 1 && K.m == 1) { printf("look down\n"); }
	if (K.w == 1 && K.m == 1) { printf("move up\n"); }
	if (K.s == 1 && K.m == 1) { printf("move down\n"); }
}

void clearBackground()
{
	int x, y;
	for (y = 0; y < SH; y++)
	{
		for (x = 0; x < SW; x++) { pixel(x, y, 8); } //clear background color
	}
}

int tick;
void draw3D()
{
	int x, y, c = 0;
	for (y = 0; y < SH2; y++)
	{
		for (x = 0; x < SW2; x++)
		{
			pixel(x, y, c);
			c += 1; if (c > 8) { c = 0; }
		}
	}
	//frame rate
	tick += 1; if (tick > 20) { tick = 0; } pixel(SW2, SH2 + tick, 0);
}

void display(void)
{
	int x, y;
	if (T.fr1 - T.fr2 >= 50)                       //only draw 20 frames/second
	{
		clearBackground();
		movePlayer();
		draw3D();

		T.fr2 = T.fr1;
		glutSwapBuffers();
		glutReshapeWindow(GLSW, GLSH);             //prevent window scaling
	}

	T.fr1 = glutGet(GLUT_ELAPSED_TIME);            //1000 Milliseconds per second
	glutPostRedisplay();
}

void KeysDown(unsigned char key, int x, int y)
{
	if (key == 'w') { K.w = 1; }
	if (key == 's') { K.s = 1; }
	if (key == 'a') { K.a = 1; }
	if (key == 'd') { K.d = 1; }
	if (key == 'm') { K.m = 1; }
	if (key == ',') { K.sr = 1; }
	if (key == '.') { K.sl = 1; }
}
void KeysUp(unsigned char key, int x, int y)
{
	if (key == 'w') { K.w = 0; }
	if (key == 's') { K.s = 0; }
	if (key == 'a') { K.a = 0; }
	if (key == 'd') { K.d = 0; }
	if (key == 'm') { K.m = 0; }
	if (key == ',') { K.sr = 0; }
	if (key == '.') { K.sl = 0; }
}

void init()
{
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(GLSW / 2, GLSH / 2);
	glutInitWindowSize(GLSW, GLSH);
	glutCreateWindow("");
	glPointSize(pixelScale);                        //pixel size
	gluOrtho2D(0, GLSW, 0, GLSH);                      //origin bottom left
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(KeysDown);
	glutKeyboardUpFunc(KeysUp);
	glutMainLoop();
	return 0;
}