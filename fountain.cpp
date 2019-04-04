#if 0
#include <GL/glut.h>
#include <stdlib.h>		
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#define PI 3.14152653597689786
#define RandomFactor 2.0
unsigned int i;
int flag = 0, f = 2;
int vflag = 0;
GLfloat xt = 0.0, yt = 0.0, zt = 0.0;
GLfloat xangle = 0.0, yangle = 0.0, zangle = 0.0;
GLfloat X[3];
GLint ListNum;
GLfloat OuterRadius = 1.4;
GLfloat InnerRadius = 1.0;
GLint NumOfVerticesStone = 1000;
GLfloat StoneHeight = 0.45;
GLfloat WaterHeight = 0.35;

struct SVertex
{
	GLfloat x, y, z;
};
class CDrop
{
private:
	GLfloat time;
	SVertex ConstantSpeed;
	GLfloat AccFactor;
public:
	void SetConstantSpeed(SVertex NewSpeed);
	void SetAccFactor(GLfloat NewAccFactor);
	void SetTime(GLfloat NewTime);
	void GetNewPosition(SVertex * PositionVertex);
};

void CDrop::SetConstantSpeed(SVertex NewSpeed)
{
	ConstantSpeed = NewSpeed;
}

void CDrop::SetAccFactor(GLfloat NewAccFactor)
{
	AccFactor = NewAccFactor;
}

void CDrop::SetTime(GLfloat NewTime)
{
	time = NewTime;
}

void CDrop::GetNewPosition(SVertex * PositionVertex)
{
	SVertex Position;
	time += 0.15;
	Position.x = ConstantSpeed.x * time;
	Position.y = ConstantSpeed.y * time - AccFactor * time *time;
	Position.z = ConstantSpeed.z * time;
	PositionVertex->x = Position.x;
	PositionVertex->y = Position.y + WaterHeight;
	PositionVertex->z = Position.z;
	if (Position.y < 0.0)
	{
		time = time - int(time);
		if (time > 0.0) time -= 1.0;
	}

}

CDrop * FountainDrops;
SVertex * FountainVertices;
GLint Steps = 5;
GLint RaysPerStep = 8;
GLint DropsPerRay = 90;
GLfloat DropsComplete = Steps * RaysPerStep * DropsPerRay;
GLfloat AngleOfDeepestStep = 80;
GLfloat AccFactor = 0.011;

void CreateList(void)
{
	SVertex * Vertices = new SVertex[NumOfVerticesStone * 3];
	ListNum = glGenLists(1);
	for (GLint i = 0; i<NumOfVerticesStone; i++)
	{
		Vertices[i].x = cos(2.0 * PI / NumOfVerticesStone * i) * OuterRadius;
		Vertices[i].y = StoneHeight;
		Vertices[i].z = sin(2.0 * PI / NumOfVerticesStone * i) * OuterRadius;
	}
	for (i = 0; i<NumOfVerticesStone; i++)
	{
		Vertices[i + NumOfVerticesStone * 1].x = cos(2.0 * PI / NumOfVerticesStone * i) * InnerRadius;
		Vertices[i + NumOfVerticesStone * 1].y = StoneHeight;
		Vertices[i + NumOfVerticesStone * 1].z = sin(2.0 * PI / NumOfVerticesStone * i) * InnerRadius;
	}
	for (i = 0; i<NumOfVerticesStone; i++)
	{
		Vertices[i + NumOfVerticesStone * 2].x = cos(2.0 * PI / NumOfVerticesStone * i) * OuterRadius;
		Vertices[i + NumOfVerticesStone * 2].y = 0.0;
		Vertices[i + NumOfVerticesStone * 2].z = sin(2.0 * PI / NumOfVerticesStone * i) * OuterRadius;
	}


	glNewList(ListNum, GL_COMPILE);

	glBegin(GL_QUADS);
	glColor3ub(0, 150, 0);
	glVertex3f(-OuterRadius*10.0, 0.0, OuterRadius*10.0);
	glVertex3f(-OuterRadius*10.0, 0.0, -OuterRadius*10.0);
	glVertex3f(OuterRadius*10.0, 0.0, -OuterRadius*10.0);
	glVertex3f(OuterRadius*10.0, 0.0, OuterRadius*10.0);

	for (int j = 1; j < 3; j++)
	{
		if (j == 1) glColor3f(0.2, 0.1, 0.3);
		if (j == 2) glColor3f(0.0, 0.0, 0.0);
		for (i = 0; i<NumOfVerticesStone - 1; i++)
		{
			glVertex3fv(&Vertices[i + NumOfVerticesStone*j].x);
			glVertex3fv(&Vertices[i].x);
			glVertex3fv(&Vertices[i + 1].x);
			glVertex3fv(&Vertices[i + NumOfVerticesStone*j + 1].x);
		}
		glVertex3fv(&Vertices[i + NumOfVerticesStone*j].x);
		glVertex3fv(&Vertices[i].x);
		glVertex3fv(&Vertices[0].x);
		glVertex3fv(&Vertices[NumOfVerticesStone*j].x);
	}
	glEnd();
	glTranslatef(0.0, WaterHeight - StoneHeight, 0.0);
	glBegin(GL_POLYGON);
	for (i = 0; i<NumOfVerticesStone; i++)
	{
		glVertex3fv(&Vertices[i + NumOfVerticesStone].x);
		GLint m1, n1, p1;
		m1 = rand() % 255;
		n1 = rand() % 255;
		p1 = rand() % 255;

		glColor3ub(m1, n1, p1);


	}

	glEnd();

	glColor3ub(255, 255, 255);

	glTranslatef(8.0, 8.0, -10.0);

	glutSolidSphere(1.0, 20, 20);


	glEndList();
}
GLfloat GetRandomFloat(GLfloat range)
{
	return (GLfloat)rand() / (GLfloat)RAND_MAX * range * RandomFactor;
}

void InitFountain(void)
{

	FountainDrops = new CDrop[(int)DropsComplete];
	FountainVertices = new SVertex[(int)DropsComplete];
	SVertex NewSpeed;
	GLfloat DropAccFactor;
	GLfloat TimeNeeded;
	GLfloat StepAngle;
	GLfloat RayAngle;
	GLint i, j, k;
	for (k = 0; k <Steps; k++)
	{
		for (j = 0; j < RaysPerStep; j++)
		{
			for (i = 0; i < DropsPerRay; i++)
			{
				DropAccFactor = AccFactor + GetRandomFloat(0.0005);
				StepAngle = AngleOfDeepestStep + (90.0 - AngleOfDeepestStep)
					* GLfloat(k) / (Steps - 1) + GetRandomFloat(0.2 + 0.8*(Steps - k - 1) / (Steps - 1));

				NewSpeed.x = cos(StepAngle * PI / 180.0) * (0.2 + 0.04*k);
				NewSpeed.y = sin(StepAngle * PI / 180.0) * (0.2 + 0.04*k);


				RayAngle = (GLfloat)j / (GLfloat)RaysPerStep * 360.0;

				NewSpeed.z = NewSpeed.x * sin(RayAngle * PI / 180.0);
				NewSpeed.x = NewSpeed.x * cos(RayAngle * PI / 180.0);


				TimeNeeded = NewSpeed.y / DropAccFactor;
				FountainDrops[i + j*DropsPerRay + k*DropsPerRay*RaysPerStep].SetConstantSpeed(NewSpeed);
				FountainDrops[i + j*DropsPerRay + k*DropsPerRay*RaysPerStep].SetAccFactor(DropAccFactor);
				FountainDrops[i + j*DropsPerRay + k*DropsPerRay*RaysPerStep].SetTime(TimeNeeded * i / DropsPerRay);
			}
		}
	}


	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3,
		GL_FLOAT,
		0,
		FountainVertices);

}

void randcolor()
{
	GLint a, b, c;
	a = rand() % 240;
	b = rand() % 240;
	c = rand() % 240;
	X[0] = (GLfloat)a / 100.0;
	X[1] = (GLfloat)b / 100.0;
	X[2] = (GLfloat)c / 100.0;

}

void DrawFountain(void)
{
	if (flag == 0)
		glColor3f(1.0, 1.0, 1.0);
	else if (flag == 1)
		glColor3fv(X);
	else if (flag == 2)
		glColor3f(0.0, 0.0, 0.0);
	else
		glColor3f(0.0, 0.0, 0.0);

	for (int i = 0; i < DropsComplete; i++)
	{
		FountainDrops[i].GetNewPosition(&FountainVertices[i]);
	}
	glDrawArrays(GL_POINTS,
		0,
		DropsComplete);
	glutPostRedisplay();
}

void colours(int id)
{

	flag = id;
	if (flag == 1)
		randcolor();
	glutPostRedisplay();
}

void flow(int id)
{
	RaysPerStep = id;
	glutPostRedisplay();
}

void Display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(0, 0, 0, 0.0);
	glTranslatef(0.0, 0.0, -6.0);
	glTranslatef(0.0, -1.3, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(xangle, 0.0, 0.0, 0.0);
	glRotatef(45.0, 0.0, 0.0, 0.0);
	glPushMatrix();
	glCallList(ListNum);
	glPopMatrix();
	DrawFountain();
	glFlush();
	glutSwapBuffers();


}
void Reshape(int x, int y)
{

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, (GLdouble)x / (GLdouble)y, 1.10, 80.0);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(GLfloat(x) / 500.0);
}
int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Flowing Fountain");
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 100, 0, 1.0);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glLineWidth(2.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	InitFountain();
	CreateList();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
	return 0;
}
#endif
