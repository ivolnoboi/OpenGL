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

static int task; // ����� �������

static int w = 0, h = 0; //���������� ����������� ���������� � ������ ������� ������ ������

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;

float Angle = 0;

//������� ���������� ����� ���������� � ������� ����
void Init(void)
{
	if (task == 1)
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // ��� � ����� ����
	else if (task == 7)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ��� � ������ ����
		glPointSize(10.0f); // �������� ������ ����� �� �������� 10 ��������
	}
	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ��� � ������ ����
	}
}

//������� ���������� ������ ���� � ��� ��� ���������, ���������� � �. �.
void Update(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // ������� ������ �����
	GLfloat BlueCol[3] = { 0 , 0 , 1 }; // ������������ ������ ��� 9 ������� (��� ��������� �� ����� � ����� ��������)
	if (task > 4)
	{
		glMatrixMode(GL_MODELVIEW); // ������� � ������� �������� ��������������
		glLoadIdentity(); // ��������� ��������� �������
	}
	switch (task)
	{
	case 5:
		Angle += 0.05f; //����������� ���� ��������
		gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // ������� ������� ������, ����� ���������� � ������ �����
		glRotatef(Angle, 0.0f, 1.0f, 0.0f); // ���������� ������� �������� � ������� �������
		glutWireSphere(50.0f, 10, 10); 	// ��������� ����� �������� 50 ��, �������� 10 x 10 ���������
		//�������� ��� ������ �� ��������� � �������� ��������������
		// OpenGL ��� �������� ���������� ���������� ����������
		glFlush(); // ��������� ������, ������� �� ������� ������, ���������� ������������ (���������� ��� ������ �� ��������� � �������� ��������������
		// OpenGL ��� �������� ���������� ���������� ����������
		break;
	case 6:

		Angle += 0.05f;
		gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(Angle, 0.0f, 1.0f, 0.0f);
		glutWireTeapot(50.0f); // ������ ������ �������� 50 ������
		glFlush();
		break;
	case 7:
		Angle += 0.005f;
		gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(Angle, 0.0f, 1.0f, 0.0f);

		// ��������� �����
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

		glFlush();
		break;
	case 8:
		Angle += 0.005f;
		gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(Angle, 0.0f, 1.0f, 0.0f);

		// ������ ��� ������������
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f); //������� - ������ ������� ���� �� (RGB)
		//������ ������� �����������
		glVertex3f(-75.0f, 0.0f, -50.0f);
		glVertex3f(-75.0f, 0.0f, 50.0f);
		glVertex3f(75.0f, 0.0f, 50.0f);

		glColor3f(0.0f, 0.0f, 1.0f); //������� - ������ ����� ���� ��( RGB)
		//������ ������ ����� �����������
		glVertex3f(-75.0f, 0.0f, -50.0f);
		glVertex3f(75.0f, 0.0f, -50.0f);
		glVertex3f(75.0f, 0.0f, 50.0f);
		glEnd();

		glFlush();
		break;
	case 9:
		Angle += 0.05f;
		gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(Angle, 0.0f, 1.0f, 0.0f);

		// ������ ����������� �����������
		//GLfloat BlueCol[3] = { 0 , 0 , 1 };
		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0); /* ������� */
		glVertex3f(0.0, 0.0, 0.0);
		glColor3ub(0, 255, 0); /* ������� */
		glVertex3f(75.0, 0.0, 0.0);
		glColor3fv(BlueCol); /* ����� */
		glVertex3f(75.0, 75.0, 0.0);
		glEnd();

		glFlush();
		break;
	default:
		break;
	}
	glutSwapBuffers(); // ��� ��� �������� ������� �����������, �� ��� �������� �� ������� �� ������������ ������, � ����� ���������� ����� �������. 
	// �������� ��� ��� ��������� ������� �������� � ��� ����, ����� �� ���� ������� �������� ������.
}

//������ ���������� ��� ��������� �������� ����
void Reshape(int width, int height)
{
	w = width;
	h = height;
	if (task > 4)
	{
		glViewport(0, 0, w, h); // ������� ��� ��������� � � ������ ������: �� ����
		glMatrixMode(GL_PROJECTION); // ������� ������� - ������� ������������ ��������������
		glLoadIdentity(); // ������� ������� ������������ �������������� ���������
		gluPerspective(65.0f, w / h, 1.0f, 1000.0f); // �������� ������� �������������� �������������� 
													 // ������ �� ��������� ���� ������, ��������� ������ � ������ � 
													 //���������� ������� � ������� ���������� ����������
	}
}

void renderRectangle()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS); // ��������� ��������
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

void renderSolidCube()
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

	std::cin >> task;

	glutInit(&argc, argv); 	// ������������� glut
	glutInitWindowPosition(100, 100); 	// ��������� ��������� ����
	glutInitWindowSize(600, 600); // ��������� ������� ����

	if (task == 1)
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // ��������� ���������� ���� � ������� ������������ � ��������� ����� RGBA
	else glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); // �� ��, ��� � � ����������, �� + ������������ �������

	glutCreateWindow("OpenGL");  // ������ ���� � ���������� OpenGL

	switch (task)
	{
	case 1:
		glutIdleFunc(Update); // ������ glut �������, ������� ����� ���������� ������ ����
		glutDisplayFunc(Update); // ������ glut �������, ������� ����� �������� ������ ����
		glutReshapeFunc(Reshape); // ������ glut �������, ������� ����� ���������� ��� ��������� ������� ���� ����������
		Init();
		break;
	case 2:
		glutDisplayFunc(renderRectangle);
		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);
		Init();
		break;
	case 3:
		glutDisplayFunc(renderWireCube);
		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);
		Init();
		break;
	case 4:
		glutDisplayFunc(renderSolidCube);
		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);
		Init();
		break;
	case 5:
		glutIdleFunc(Update);
		glutDisplayFunc(Update);
		glutReshapeFunc(Reshape);
		Init();
		break;
	case 6:
		glutIdleFunc(Update);
		glutDisplayFunc(Update);
		glutReshapeFunc(Reshape);
		Init();
		break;
	case 7:
		glutIdleFunc(Update);
		glutDisplayFunc(Update);
		glutReshapeFunc(Reshape);
		Init();
		break;
	case 8:
		glutIdleFunc(Update);
		glutDisplayFunc(Update);
		glutReshapeFunc(Reshape);
		Init();
		break;
	case 9:
		glutIdleFunc(Update);
		glutDisplayFunc(Update);
		glutReshapeFunc(Reshape);
		Init();
		break;
	default:
		break;
	}

	//����� � ������� ���� ����������
	glutMainLoop();
	return 0;
}