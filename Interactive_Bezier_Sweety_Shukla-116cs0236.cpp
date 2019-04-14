//Interactive Bezier Curve
//Sweety Shukla
//116CS0236
#if 1
#include <Windows.h>
#include <GL\freeglut.h>
#include <math.h>
#include <iostream>
#include<string.h>
using namespace std;

float pa[2], pb[2], pc[2], pd[2];
void BezierCurve()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPointSize(3);

	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(pa[0], pa[1]);
	glVertex2f(pb[0], pb[1]);
	glVertex2f(pc[0], pc[1]);
	glVertex2f(pd[0], pd[1]);
	glEnd();

	glPointSize(3);
	glBegin(GL_LINES);
	glColor3f(0, 0, 1);
	glVertex2f(pa[0], pa[1]);
	glVertex2f(pb[0], pb[1]);
	glVertex2f(pc[0], pc[1]);
	glVertex2f(pd[0], pd[1]);
	glVertex2f(pb[0], pb[1]);
	glVertex2f(pc[0], pc[1]);
	glEnd();

	glPointSize(2);
	for (float u = 0; u<1; u += 0.001)
	{
		glBegin(GL_POINTS);
		glColor3f(0, 1, 0);
		float x, y;
		x = (1 - u)*(1 - u)*(1 - u)*pa[0] + (1 - u)*(1 - u) * 3 * u*pb[0] + (1 - u) * 3 * u*u*pc[0] + u*u*u*pd[0];
		y = (1 - u)*(1 - u)*(1 - u)*pa[1] + (1 - u)*(1 - u) * 3 * u*pb[1] + (1 - u) * 3 * u*u*pc[1] + u*u*u*pd[1];
		glVertex2f(x, y);
		glEnd();
	}
	glFlush();
}

int calculate(int a, int b)
{
	int d1, d2, d3, d4, minimum = 100000000;;
	d1 = sqrt(((a - pa[0])*(a - pa[0])) + ((b - pa[1])*(b - pa[1])));
	d2 = sqrt(((a - pb[0])*(a - pb[0])) + ((b - pb[1])*(b - pb[1])));
	d3 = sqrt(((a - pc[0])*(a - pc[0])) + ((b - pc[1])*(b - pc[1])));
	d4 = sqrt(((a - pd[0])*(a - pd[0])) + ((b - pd[1])*(b - pd[1])));


	minimum = min(d1, minimum);
	minimum = min(d2, minimum);
	minimum = min(d3, minimum);
	minimum = min(d4, minimum);

	if (minimum == d1) return 1;
	if (minimum == d2) return 2;
	if (minimum == d3) return 3;
	if (minimum == d4) return 4;

}

void mouse(int button, int state, int mouse_x, int mouse_y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int p = calculate(mouse_x, 1000 - mouse_y);
		switch (p)
		{
		case 1:
			pa[0] = mouse_x;
			pa[1] = 1000 - mouse_y;
			break;
		case 2:
			pb[0] = mouse_x; glEnd();
			pb[1] = 1000 - mouse_y;
			break;
		case 3:
			pc[0] = mouse_x;
			pc[1] = 1000 - mouse_y;
			break;
		case 4:
			pd[0] = mouse_x;
			pd[1] = 1000 - mouse_y;
			break;
		}
		glutPostRedisplay();
	}

}


int main(int argc, char *argv[]) //Driver Function
{
	cout << "Enter any four control points for the Bezier Curve: " << endl;
	cout << "(Note: Preferred Points for better visualisation: { 100,150 }, { 350,450 }, { 450,450 },  { 700,150 })" << endl;
	cin >> pa[0] >> pa[1] >> pb[0] >> pb[1] >> pc[0] >> pc[1] >> pd[0] >> pd[1];
	cout << endl << "Displaying the Bezier Curve..." << endl;
	cout << "Drag any of the control points to visualize the curves" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("INTERACTIVE BEZIER CURVE");
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(BezierCurve);
	glutMouseFunc(mouse);
	glutMainLoop();
}
#endif
