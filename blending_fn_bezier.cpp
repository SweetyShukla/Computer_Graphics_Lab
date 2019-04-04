#if 0
//Blending function bezier curve
#include <gl/glut.h>
#include <stdio.h>


void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-5, 5, -5, 5);
}

void draw_pixel(float x, float y) {
	glPointSize(1);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}
void draw_curve() {

	float u;
	float f1, f2, f3, f4;
	for (float i = -50; i <= 50; i=i+0.01)	//X and Y axis
	{
		glColor3f(1, 0, 0);
		draw_pixel(i, 0);
		draw_pixel(0, i);

	}
	for (u = 0.01; u < 1; u += 0.01)
	{
		glColor3f(1, 0, 0);
		f1 = (1-u)*(1-u)*(1-u);
		draw_pixel(u, f1);
	}
	for (u = 0.01; u < 1; u += 0.01)
	{
		glColor3f(0, 1, 0);
		f2 = 3 * u*(1 - u)*(1-u);
		draw_pixel(u, f2);
	}
	for (u = 0.01; u < 1; u += 0.01)
	{
		glColor3f(1, 0.6, 0.6);
		f3 = 3 * u*u*(1 - u);
		draw_pixel(u, f3);
	}
	for (u = 0.01; u < 1; u += 0.01)
	{
		glColor3f(0.4, 0.6, 0.6);
		f4 = u*u*u;
		draw_pixel(u, f4);
	}


}
void myDisplay() {
	draw_curve();
	glFlush();
}

void main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Blending Function Hermite Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
#endif
