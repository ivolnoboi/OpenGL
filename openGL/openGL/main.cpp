#include <iostream>
#include <Windows.h>
#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>

//���������� ����������
# pragma comment (lib ,"opengl32.lib")
# pragma comment (lib ,"glu32.lib")
//# pragma comment (lib ,"glut32.lib") //- �� ��� ������ ��������
# pragma comment (lib ,"freeglut.lib")

//���������� ����������� ���������� � ������ ������� ������ ������
static int w = 0, h = 0;

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;

float Angle = 0;

//������� ���������� ����� ���������� � ������� ����
void Init(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

//������� ���������� ����� ���������� � ������� ����
void Init2(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//������� ���������� ����� ���������� � ������� ����
void Init3(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//�������� ������ ����� �� �������� 10 ��������
	glPointSize(10.0f);
}

//������� ���������� ������ ���� � ��� ��� ���������, ���������� � �. �.
void Update(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

//������� ���������� ������ ���� � ��� ��� ���������, ���������� � �. �.
void Update2(void)
{
	//������� � ������� �������� ��������������
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f; //����������� ���� ��������
	glClear(GL_COLOR_BUFFER_BIT); //������� ����� �����
	glLoadIdentity(); //�������� ���������. ����
	//������� ������� ������, ����� ������. � ������ �����
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//�������� ������� �������� �� ������� �������
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);
	//�������� ����� �������� 50 ��, �������� 10 x10 ���������
	glutWireSphere(50.0f, 10, 10);
	//�������� ��� ������ �� ��������� � �������� ��������������
	// OpenGL ��� �������� ���������� ���������� ����������
	glFlush();
	glutSwapBuffers();
}

//������� ���������� ������ ���� � ��� ��� ���������, ���������� � �. �.
void Update3(void)
{
	//������� � ������� �������� ��������������
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f; //����������� ���� ��������
	glClear(GL_COLOR_BUFFER_BIT); //������� ����� �����
	glLoadIdentity(); //�������� ���������. ����
	//������� ������� ������, ����� ������. � ������ �����
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//�������� ������� �������� �� ������� �������
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);
	//�������� ����� �������� 50 ��, �������� 10 x10 ���������
	glutWireTeapot(50.0f);
	//�������� ��� ������ �� ��������� � �������� ��������������
	// OpenGL ��� �������� ���������� ���������� ����������
	glFlush();
	glutSwapBuffers();
}

//������� ���������� ������ ���� � ��� ��� ���������, ���������� � �. �.
void Update4(void)
{
	//������� � ������� �������� ��������������
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.005f; //����������� ���� ��������
	glClear(GL_COLOR_BUFFER_BIT); //������� ����� �����
	glLoadIdentity(); //�������� ���������. ����
	//������� ������� ������, ����� ������. � ������ �����
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//�������� ������� �������� �� ������� �������
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);
	//�������� ����� �������� 50 ��, �������� 10 x10 ���������
	glBegin(GL_POINTS);
	glVertex3f(-50.0f, -50.0f, -50.0f);
	glVertex3f(-50.0f, -50.0f, 50.0f);
	glVertex3f(-50.0f, 50.0f, -50.0f);
	glVertex3f(-50.0f, 50.0f, 50.0f);
	glVertex3f(50.0f, -50.0f, -50.0f);
	glVertex3f(50.0f, -50.0f, 50.0f);
	glVertex3f(50.0f, 50.0f, -50.0f);
	glVertex3f(50.0f, 50.0f, 50.0f);
	glEnd();

	//�������� ��� ������ �� ��������� � �������� ��������������
	// OpenGL ��� �������� ���������� ���������� ����������
	glFlush();
	glutSwapBuffers();
}

//������� ���������� ������ ���� � ��� ��� ���������, ���������� � �. �.
void Update5(void)
{
	//������� � ������� �������� ��������������
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.005f; //����������� ���� ��������
	glClear(GL_COLOR_BUFFER_BIT); //������� ����� �����
	glLoadIdentity(); //�������� ���������. ����
	//������� ������� ������, ����� ������. � ������ �����
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//�������� ������� �������� �� ������� �������
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLES);
	//������� - ������ ������� ���� �� (RGB)
	glColor3f(1.0f, 0.0f, 0.0f);
	//������ ������� �����������
	glVertex3f(-75.0f, 0.0f, -50.0f);
	glVertex3f(-75.0f, 0.0f, 50.0f);
	glVertex3f(75.0f, 0.0f, 50.0f);
	//������� - ������ ����� ���� ��( RGB)
	glColor3f(0.0f, 0.0f, 1.0f);
	//������ ������ ����� �����������
	glVertex3f(-75.0f, 0.0f, -50.0f);
	glVertex3f(75.0f, 0.0f, -50.0f);
	glVertex3f(75.0f, 0.0f, 50.0f);
	glEnd();

	//�������� ��� ������ �� ��������� � �������� ��������������
	// OpenGL ��� �������� ���������� ���������� ����������
	glFlush();
	glutSwapBuffers();
}

//������� ���������� ������ ���� � ��� ��� ���������, ���������� � �. �.
void Update6(void)
{
	//������� � ������� �������� ��������������
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f; //����������� ���� ��������
	glClear(GL_COLOR_BUFFER_BIT); //������� ����� �����
	glLoadIdentity(); //�������� ���������. ����
	//������� ������� ������, ����� ������. � ������ �����
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//�������� ������� �������� �� ������� �������
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);

	GLfloat BlueCol[3] = { 0 , 0 , 1 };
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); /* ������� */
	glVertex3f(0.0, 0.0, 0.0);
	glColor3ub(0, 255, 0); /* ������� */
	glVertex3f(75.0, 0.0, 0.0);
	glColor3fv(BlueCol); /* ����� */
	glVertex3f(75.0, 75.0, 0.0);
	glEnd();

	//�������� ��� ������ �� ��������� � �������� ��������������
	// OpenGL ��� �������� ���������� ���������� ����������
	glFlush();
	glutSwapBuffers();
}

//������ ���������� ��� ��������� �������� ����
void Reshape2(int width, int height)
{
	w = width;
	h = height;
	// ������� ��� ��������� � � ������ ������: �� ����
	glViewport(0, 0, w, h);
	// ������� ������� - ������� ������������ ��������������
	glMatrixMode(GL_PROJECTION);
	// ������� ������� ������������ �������������� ���������
	glLoadIdentity();
	// �������� ������� �������������� �������������� ������ �� ��������� ���� ������, ��������� ������ � ������ � ���������� ������� � ������� ���������� ����������
	gluPerspective(65.0f, w / h, 1.0f, 1000.0f);
}

//������ ���������� ��� ��������� �������� ����
void Reshape(int width, int height)
{
	w = width;
	h = height;
}

void renderRectangle()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5f, -0.5f);
	glColor3f(0.0, 1.0, 0.0); glVertex2f(-0.5f, 0.5f);
	glColor3f(0.0, 0.0, 1.0); glVertex2f(0.5f, 0.5f);
	glColor3f(1.0, 1.0, 1.0); glVertex2f(0.5f, -0.5f);
	glEnd();
	glFlush(); glutSwapBuffers();
}

void renderWireCube()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glutWireCube(1);
	glFlush();
	glutSwapBuffers();
}

void renderWireCube2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glutSolidCube(1);
	glFlush();
	glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: rotate_x += 5; break;
	case GLUT_KEY_DOWN: rotate_x -= 5; break;
	case GLUT_KEY_RIGHT: rotate_y += 5; break;
	case GLUT_KEY_LEFT: rotate_y -= 5; break;
	case GLUT_KEY_PAGE_UP: rotate_z += 5; break;
	case GLUT_KEY_PAGE_DOWN: rotate_z -= 5; break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	std::cout << "1 � ����� ����� (���. 29 � �����������)" << std::endl;
	std::cout << "2 � �������� � 2D �������� � ����������� ��������� ������ ������ ������ (���. 45 � �����������)" << std::endl;
	std::cout << "3 � �������� � 3D ���������� ���� � ��������������� �������� (���. 47 � �����������)" << std::endl;
	std::cout << "4 � �������� � 3D ������������� ���� � ��������������� �������� (���. 49 � �����������)" << std::endl;
	std::cout << "5 � �������� � 3D ����� � ������������� �������� (���. 52 � �����������)" << std::endl;
	std::cout << "6 � �������� � 3D ������� � ������������� �������� (���. 59 � �����������)" << std::endl;
	std::cout << "7 � ����� ��������� ����� (���. 62 � �����������)" << std::endl;
	std::cout << "8 � ��� ������������ ������� ����� (���. 65 � �����������)" << std::endl;
	std::cout << "9 � �������� � 3D ������������ (� ����������� ���������) ������ ���� ��������� (���. 70 � �����������)" << std::endl;

	int number;
	std::cin >> number;
	switch (number)
	{
	case 1:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(800, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL");

		//������ glut �������, ������� ����� ���������� ������ ����
		glutIdleFunc(Update);

		//������ glut �������, ������� ����� �������� ������ ����
		glutDisplayFunc(Update);

		//������ glut �������, ������� ����� ���������� ��� ��������� ������� ���� ����������
		glutReshapeFunc(Reshape);
		Init();

		break;
	case 2:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(600, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL_HelloWorld");

		glutDisplayFunc(renderRectangle);

		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);

		break;
	case 3:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(600, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL_HelloWorld");

		glutDisplayFunc(renderWireCube);

		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);

		break;
	case 4:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(600, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL_HelloWorld");

		glutDisplayFunc(renderWireCube2);

		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);

		break;
	case 5:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(800, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL");

		//������ glut �������, ������� ����� ���������� ������ ����
		glutIdleFunc(Update2);

		//������ glut �������, ������� ����� �������� ������ ����
		glutDisplayFunc(Update2);

		//������ glut �������, ������� ����� ���������� ��� ��������� ������� ���� ����������
		glutReshapeFunc(Reshape2);
		Init2();

		break;
	case 6:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(800, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL");

		//������ glut �������, ������� ����� ���������� ������ ����
		glutIdleFunc(Update3);

		//������ glut �������, ������� ����� �������� ������ ����
		glutDisplayFunc(Update3);

		//������ glut �������, ������� ����� ���������� ��� ��������� ������� ���� ����������
		glutReshapeFunc(Reshape2);
		Init2();

		break;
	case 7:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(800, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL");

		//������ glut �������, ������� ����� ���������� ������ ����
		glutIdleFunc(Update4);

		//������ glut �������, ������� ����� �������� ������ ����
		glutDisplayFunc(Update4);

		//������ glut �������, ������� ����� ���������� ��� ��������� ������� ���� ����������
		glutReshapeFunc(Reshape2);
		Init3();

		break;
	case 8:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(800, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL");

		//������ glut �������, ������� ����� ���������� ������ ����
		glutIdleFunc(Update5);

		//������ glut �������, ������� ����� �������� ������ ����
		glutDisplayFunc(Update5);

		//������ glut �������, ������� ����� ���������� ��� ��������� ������� ���� ����������
		glutReshapeFunc(Reshape2);
		Init3();

		break;
	case 9:
		//���������������� ��� glut
		glutInit(&argc, argv);

		//���������� ��������� ��������� ����
		glutInitWindowPosition(100, 100);

		//���������� ��������� ������� ����
		glutInitWindowSize(800, 600);

		//���������� ��������� ���� � ������� ������������ � ��������� ����� RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//������� ���� � ���������� OpenGL
		glutCreateWindow("OpenGL");

		//������ glut �������, ������� ����� ���������� ������ ����
		glutIdleFunc(Update6);

		//������ glut �������, ������� ����� �������� ������ ����
		glutDisplayFunc(Update6);

		//������ glut �������, ������� ����� ���������� ��� ��������� ������� ���� ����������
		glutReshapeFunc(Reshape2);
		Init3();

		break;
	default:
		break;
	}

	//����� � ������� ���� ����������
	glutMainLoop();
	return 0;
}