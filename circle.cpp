#include <GL/glut.h>
#include <iostream>

int radius, xc, yc;
void displayMe(void)
{
    glLoadIdentity();
    int  x, y;
    float pk;
    gluOrtho2D(-300, 300, -300, 300);
    glClear(GL_COLOR_BUFFER_BIT);
   
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    
    glColor3f(1.0,1.0,1.0);
        
        x=0;
        y=radius;
        glVertex2i(xc+x,yc+y);
	glVertex2i(xc+y,yc+x);
	glVertex2i(xc+x,yc-y);
	glVertex2i(xc-y,yc+x);
 	
        pk = 1-radius;
        while(x < y)
	{
		if(pk <= 0)
		{
			glVertex2i(xc+x+1,yc+y);
			glVertex2i(xc+y,yc+x+1);
			glVertex2i(xc-(x+1),yc+y);
			glVertex2i(xc+y,yc+(-(x+1)));
			glVertex2i(xc+x+1,yc-y);
			glVertex2i(xc-y, yc+x+1);
			glVertex2i(xc-(x+1),yc-y);
			glVertex2i(xc-y,yc-(x+1));
                        pk = pk+ 2*x +3;
 			x=x+1;
                        
		}
		else
		{
			glVertex2i(xc+x+1,yc+y-1);
			glVertex2i(xc+y-1,yc+x+1);
			glVertex2i(xc+-(x+1),yc+y-1);
			glVertex2i(xc+y-1,yc-(x+1));
			glVertex2i(xc+x+1,yc-(y-1));
			glVertex2i(xc-(y-1), yc+x+1);
			glVertex2i(xc-(x+1),yc-(y-1));
			glVertex2i(xc-(y-1), yc-(x+1));
			pk = pk+2*x+5-2*y;
			x= x+1;
			y= y-1;
				
       		}
	
	}
    glEnd();
    glutPostRedisplay();
    glFlush();
}
 
int main(int argc, char** argv)
{
    std::cout<<"Give x and y coordinate of center of circle"<<std::endl;
    std::cin>>xc>>yc;
    std::cout<<"Give radius of circle"<<std::endl;
    std::cin>>radius;  
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glMatrixMode(GL_PROJECTION);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
