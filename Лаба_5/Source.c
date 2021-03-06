#include <windows.h>

#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glu32.lib")
#pragma comment (lib,"glut32.lib")
#define PI 3.1415926535898

struct Vector
{
	float x, y;
};

struct Vector v1, v2, v3, v4;
struct Vector pos;
float angle;

//------------------------------------------------------------------------------------
void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, 2, 12);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
//------------------------------------------------------------------------------------

struct Vector Rotate(struct Vector v, float a) // ������� �������� ������� �� ���� �.
{
	struct Vector r;

	a = a * (PI / 180.0);
	r.x = (v.x * cos(a)) + (v.y * sin(a));
	r.y = (v.x * -sin(a)) + (v.y * cos(a));

	return r;
}
//------------------------------------------------------------------------------------

void init() // ������ ��������� �����
{
	v1.x = 2; v1.y = 2; // ���������� ����������� ��������� ������
	v2.x = -2; v2.y = 2;
	v3.x = -2; v3.y = -2;
	v4.x = 2; v4.y = -2;
}
//------------------------------------------------------------------------------------

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (GetAsyncKeyState(VK_LEFT))  angle += 10; // ������ ����� � ������ ������ ������! 
	if (GetAsyncKeyState(VK_RIGHT)) angle -= 10;

	if (GetAsyncKeyState(VK_UP))      pos.y += 0.01;   // ������ ����� � ���� ������ ������� ������! 
	if (GetAsyncKeyState(VK_DOWN))  pos.y -= 0.01;

	struct Vector tv1 = Rotate(v1, angle); // ������� �������� ������  ��� �������� ���������� ��������
	struct Vector tv2 = Rotate(v2, angle);
	struct Vector tv3 = Rotate(v3, angle);
	struct Vector tv4 = Rotate(v4, angle);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(tv1.x + pos.x, tv1.y + pos.y); // ������ ������ � ��������� �������
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(tv2.x + pos.x, tv2.y + pos.y);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(tv3.x + pos.x, tv3.y + pos.y);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(tv4.x + pos.x, tv4.y + pos.y);

	glEnd();


	glutSwapBuffers();
	glutPostRedisplay();


}

//------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{

	init();
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("���� �� ����!");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);



	glutMainLoop();
}