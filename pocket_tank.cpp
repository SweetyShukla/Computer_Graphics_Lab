#if 1
#include<Windows.h>
#include<iostream>
using namespace std;
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <cstdlib>
#include <time.h> 
#include<string>

#define _USE_MATH_DEFINES
int Points = 0;
float theta = 0.0;
float velocity = 0.0;
float X_ENEMEY = 0.0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1200, 0, 600);
}

float distanceCoor(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool checkCircleIntersection(float x1, float y1, float r1, float x2, float  y2, float r2)
{
	if (distanceCoor(x1, y1, x2, y2) <= r1 + r2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void line_draw(int start, int x, int y) {
	for (int i = start; i <= x; i++)
		glVertex2i(i, y);

}

void drawA(float x, float y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 25, y + 40);
	glVertex2f(x + 10, y + 40);
	glVertex2f(x + 10, y + 37);
	glVertex2f(x + 25, y + 37);
	glEnd();
}

void drawB(float x, float y) {

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 25, y + 40);
	glVertex2f(x + 25, y + 25);
	glVertex2f(x + 22, y + 25);
	glVertex2f(x + 22, y + 40);


	glEnd();
}

void drawC(float x, float y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 25, y + 25);
	glVertex2f(x + 25, y + 10);
	glVertex2f(x + 22, y + 10);
	glVertex2f(x + 22, y + 25);
	glEnd();
}

void drawD(float x, float y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 25, y + 10);
	glVertex2f(x + 10, y + 10);
	glVertex2f(x + 10, y + 13);
	glVertex2f(x + 25, y + 13);
	glEnd();

}

void drawE(float x, float y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 10, y + 25);
	glVertex2f(x + 10, y + 10);
	glVertex2f(x + 13, y + 10);
	glVertex2f(x + 13, y + 25);
	glEnd();

}

void drawF(float x, float y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 10, y + 40);
	glVertex2f(x + 10, y + 25);
	glVertex2f(x + 13, y + 25);
	glVertex2f(x + 13, y + 40);
	glEnd();
}

void drawG(float x, float y) {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x + 25, y + 23.5);
	glVertex2f(x + 10, y + 23.5);
	glVertex2f(x + 10, y + 26.5);
	glVertex2f(x + 25, y + 26.5);
	glEnd();

}

void drawOne(float x, float y) {
	drawB(x, y);
	drawC(x, y);


}

void drawTwo(float x, float y) {
	drawB(x, y);
	drawG(x, y);
	drawA(x, y);
	drawD(x, y);
	drawE(x, y);

}

void drawThree(float x, float y) {

	drawA(x, y);
	drawB(x, y);
	drawG(x, y);
	drawC(x, y);
	drawD(x, y);

}

void drawFour(float x, float y) {
	drawF(x, y);
	drawB(x, y);
	drawG(x, y);
	drawC(x, y);
}

void drawFive(float x, float y) {
	drawA(x, y);
	drawF(x, y);

	drawG(x, y);
	drawC(x, y);
	drawD(x, y);
}

void drawSix(float x, float y) {
	drawA(x, y);
	drawF(x, y);
	drawE(x, y);
	drawD(x, y);
	drawC(x, y);
	drawG(x, y);
}

void drawSeven(float x, float y) {
	drawA(x, y);
	drawB(x, y);
	drawC(x, y);
}

void drawEight(float x, float y) {
	drawA(x, y);
	drawB(x, y);
	drawC(x, y);
	drawD(x, y);
	drawE(x, y);
	drawF(x, y);
	drawG(x, y);
}

void drawNine(float x, float y) {
	drawA(x, y);
	drawB(x, y);
	drawC(x, y);
	drawD(x, y);
	drawF(x, y);
	drawG(x, y);
}

void drawZero(float x, float y) {
	drawA(x, y);
	drawB(x, y);
	drawC(x, y);
	drawD(x, y);
	drawE(x, y);
	drawF(x, y);
}


void printScore(int num) {

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(1050, 600);
	glVertex2f(1200, 600);
	glVertex2f(1200, 550);
	glVertex2f(1050, 550);
	glEnd();

	int n;
	float x = 1150;
	float y = 550;
	while (num>0) {

		n = num % 10;
		num /= 10;
		switch (n) {
		case 0: drawZero(x, y);
			break;
		case 1: drawOne(x, y);
			break;
		case 2: drawTwo(x, y);
			break;
		case 3: drawThree(x, y);
			break;
		case 4: drawFour(x, y);
			break;
		case 5: drawFive(x, y);
			break;
		case 6: drawSix(x, y);
			break;
		case 7: drawSeven(x, y);
			break;
		case 8: drawEight(x, y);
			break;
		case 9: drawNine(x, y);
			break;
		}
		x -= 50;
	}
}

void printText(int x, int y, int z, string s)
{
	glRasterPos2f(x, y);
	int len = (int)(s.length());
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}

void drawCircle(double x, double y, double radius, double r, double g, double b)
{
	glColor3f(r, g, b);

	for (double i = 0.0; i <= 6.28; i = i + 0.01)
	{
		glBegin(GL_TRIANGLES);
		glVertex2f(x, y);
		glVertex2f((radius*cos(i)) + x, (radius*sin(i)) + y);
		glVertex2f((radius*cos(i + 0.01)) + x, (radius*sin(i + 0.01)) + y);
		glEnd();
	}
	glFlush();
}

void feildDraw()
{
	glColor3f(0.0, 1.0, 0.1);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(1200.0, 0.0);
	glVertex2f(1200.0, 50.0);
	glVertex2f(0.0, 50.0);
	glEnd();
	glFlush();
	glColor3f(0.0, 0.0, 0.0);
	//printText(10, 15, 0, "POCKET TANKS - DEVELOPED BY:MONIK(114CS0095) AND DEEPIKA(114CS0088)");
}

void tankBody()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(140.0, 50.0);
	glVertex2f(180.0, 50.0);
	glVertex2f(180.0, 80.0);
	glVertex2f(140.0, 80.0);
	glEnd();
}

void tankNozzle(float angle)
{
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(175.0 + (5.0*sin(angle)), 75.0 - (5.0*cos(angle)));
	glVertex2f(175.0 - (5.0*sin(angle)), 75.0 + (5.0*cos(angle)));
	glVertex2f(175.0 - (5.0*sin(angle) - 20 * cos(angle)), 75.0 + (5.0*cos(angle) + 20 * sin(angle)));
	glVertex2f(175.0 + (5.0*sin(angle) + 20 * cos(angle)), 75.0 - (5.0*cos(angle) - 20 * sin(angle)));
	glEnd();
}

void drawTank(float angle)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(140.0, 50.0);
	glVertex2f(140.0, 100.0);
	glVertex2f(200.0, 100.0);
	glVertex2f(200.0, 50.0);
	glEnd();
	tankNozzle(angle);
	tankBody();
}

void enemyTank()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(200.0, 50.0);
	glVertex2f(200.0, 100.0);
	glVertex2f(1200.0, 100.0);
	glVertex2f(1200.0, 50.0);
	glEnd();
	glFlush();
	double x = rand() % 600 + 350;
	X_ENEMEY = x;
	drawCircle(x, 60.0, 10.0, 0.53, 0.12, 0.44);
	drawCircle(x, 60.0, 5.0, 0.14, 0.82, 0.34);
}

void ballShot()
{
	glColor3f(1.0, 1.0, 1.0);
	float y = 1000.0;
	int flag = 0;
	for (float x = 0.0; y >= -20.0; x = x + 0.5)
	{
		drawCircle(x + 175.0 - 0.5, y + 75.0, 5.0, 0.0, 0.0, 0.0);
		y = x*tan(theta);
		y = y - (9.8*pow(x, 2) / (2.0*pow(velocity, 2)*pow(cos(theta), 2)));
		drawCircle(x + 175.0, y + 75.0, 5.0, 1.0, 0.0, 0.0);
		drawCircle(x + 175.0, y + 75.0, 2.5, 0.0, 0.0, 1.0);
		drawTank(theta);
		if (checkCircleIntersection(x + 175.0, y + 75.0, 5.0, X_ENEMEY, 60.0, 10.0))
		{
			Points = Points + 1;
			drawCircle(X_ENEMEY, 60.0, 20.0, 1.0, 0.95, 0.05);
			Sleep(1500);
			feildDraw();
			drawTank(theta);
			enemyTank();
			printScore(Points);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		Sleep(1000);
		feildDraw();
		drawTank(theta);
		enemyTank();
		printScore(Points);
	}
}

void nozzleMovement(GLubyte keyFromBoard, int x, int y)
{
	int X = x;
	int Y = y;
	if (keyFromBoard == 'w' || keyFromBoard == 'W')
	{
		theta = theta + 0.01;
		if (theta>1.5699)
			theta = 1.5699;
		drawTank(theta);
	}
	if (keyFromBoard == 's' || keyFromBoard == 'S')
	{
		theta = theta - 0.01;
		if (theta<0.0)
			theta = 0.0;
		drawTank(theta);
	}
	if (keyFromBoard == 'd' || keyFromBoard == 'D')
	{
		if (velocity<100.0)
		{
			velocity = velocity + 1.0;
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_QUADS);
			glVertex2f(0.0, 500.0);
			glVertex2f(0.0, 600.0);
			glVertex2f(300.0, 600.0);
			glVertex2f(300.0, 500.0);
			glEnd();
			glColor3f(1.0, 0.0, 0.0);
			printText(5, 570, 0, "VELOCITY : ");
			printText(150, 570, 0, to_string(velocity));
		}
	}
	if (keyFromBoard == 'a' || keyFromBoard == 'A')
	{
		if (velocity>0.0)
		{
			velocity = velocity - 1.0;
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_QUADS);
			glVertex2f(0.0, 500.0);
			glVertex2f(0.0, 600.0);
			glVertex2f(300.0, 600.0);
			glVertex2f(300.0, 500.0);
			glEnd();
			glColor3f(1.0, 0.0, 0.0);
			printText(5, 570, 0, "VELOCITY : ");
			printText(150, 570, 0, to_string(velocity));
		}
	}
	if (keyFromBoard == 'p' || keyFromBoard == 'P')
	{
		ballShot();
	}
	glFlush();
}

void drawCanvas()
{
	feildDraw();
	glColor3f(1.0, 0.0, 0.0);
	printText(5, 570, 0, "VELOCITY : ");
	printText(150, 570, 0, to_string(velocity));
	drawTank(0.0);
	enemyTank();
	printScore(Points);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Pocket Tanks");
	init();
	glutDisplayFunc(drawCanvas);
	glutKeyboardFunc(nozzleMovement);
	glutMainLoop();
}
#endif
