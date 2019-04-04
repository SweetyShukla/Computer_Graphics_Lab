#if 0
//Bezier curve 2D
#include <gl/glut.h>
#include <stdio.h>


float x1, y11, x2, y2, x_1, y_1;



void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void draw_pixel(float x, float y) {
	glColor3f(0, 1, 0.5);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void drawP()
{
	glPointSize(1.0);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2i(x1, y11);
	glVertex2i(x2, y2);
	glEnd();

	

}
void draw_curve() {
	double u, x, y;
	draw_pixel(x1, y11);
	draw_pixel(x_1, y_1);
	float f1, f2, f3;
	for (u = 0.01; u<1; u += 0.01)
	{
		f1 = 1 - (u*u);
		f2 = 2 * u*(1 - u);
		f3 = u*u;
		
		x = f1 * x1 + f2 * x2 + f3 * x_1 ;
		y = f1 * y11 + f2 * y2 + f3 * y_1 ;
		draw_pixel(x, y);
	}


	for (float i = -100; i <= 100; i+=0.01)	//X and Y axis
	{
		glColor3f(1, 0, 0);
		draw_pixel(i, 0);
		draw_pixel(0, i);

	}
}

void myDisplay() {
	draw_curve();
	glFlush();
}

void main(int argc, char **argv) {

	printf("Enter (x1, y1, x2, y2,x3, y3)\n");
	scanf_s("%f %f %f %f %f %f", &x1, &y11, &x2, &y2, &x_1, &y_1);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Hermite Curve");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
#endif
