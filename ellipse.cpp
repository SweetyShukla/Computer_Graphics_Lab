#include <GL/glut.h>
#include <iostream>
#include <math.h>

int a, b, xc, yc;
void displayMe(void)
{
    glLoadIdentity();
    int  x, y;
    float pk;
    gluOrtho2D(-300, 300, -300, 300);
    glClear(GL_COLOR_BUFFER_BIT);
   
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    
    glColor3f(1.0,1.0,1.0);
        
        x=0;
        y=b;
        glVertex2i(xc+x,yc+y);
	glVertex2i(xc+x,yc-y);
 	
        pk = pow(b,2) + pow((b-0.5),2) * pow(a,2)- pow(a,2) * pow(b,2);
        if(a>b)
	{
		while(pow(b,2)*x <= pow(a,2)*y)
		{
			if(pk <= 0)
			{
                                x++;
				glVertex2i(xc+x, yc+y);	
				glVertex2i(xc+x, yc-y);
				glVertex2i(xc-x, yc+y);	
				glVertex2i(xc-x, yc-y);
				pk = pk+ pow(b,2)*(2*x + 3);	
				std::cout<<"Hello\n";	
			}
			else
			{
				y = y-1;
				x++;
				glVertex2i(xc+x, yc+y);	
				glVertex2i(xc+x, yc-y);
				glVertex2i(xc-x, yc+y);	
				glVertex2i(xc-x, yc-y);
				pk = pk+ pow(b,2) * (2*x + 3) - pow(a,2) * (2*y - 2);
				std::cout<<"Hello\n";	
			}

		}
		
		while(y>yc)
		{
			if(pk <= 0)
			{
						
		                y--;
				glVertex2i(xc+x, yc+y);	
				glVertex2i(xc+x, yc-y);
				glVertex2i(xc-x, yc+y);	
				glVertex2i(xc-x, yc-y);
				std::cout<<"Hello\n";
				pk = pk+ pow(a,2)*(2*y - 2)*(-1);
			}
			else
			{
				
				y--;
				x++;
				glVertex2i(xc+x, yc+y);	
				glVertex2i(xc+x, yc-y);
				glVertex2i(xc-x, yc+y);	
				glVertex2i(xc-x, yc-y);
				pk = pk+ pow(a,2)*(2*y - 2)*(-1) + pow(b,2)*(2*x+2);	
				std::cout<<"Hello\n";
			}
		std::cout<<"inside while\n";

		}
	
	}
        std::cout<<"Out\n";
    glEnd();
    glutPostRedisplay();
    glFlush();
}
 
int main(int argc, char** argv)
{
    std::cout<<"Give x and y coordinate of center of ellipse"<<std::endl;
    std::cin>>xc>>yc;
    std::cout<<"Give value of a and b"<<std::endl;
    std::cin>>a>>b;  
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glMatrixMode(GL_PROJECTION);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ellipse Drawing");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}


