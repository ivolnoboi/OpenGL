#include <iostream>
#include <Windows.h>
#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>

//Подключает библиотеки
# pragma comment (lib ,"opengl32.lib")
# pragma comment (lib ,"glu32.lib")
//# pragma comment (lib ,"glut32.lib") //- НА ЭТУ СТРОКУ РУГАЕТСЯ
# pragma comment (lib ,"freeglut.lib")

//Глобальные статические переменные — хранят текущий размер экрана
static int w = 0, h = 0;

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;

float Angle = 0;

//Функция вызываемая перед вхождением в главный цикл
void Init(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

//Функция вызываемая перед вхождением в главный цикл
void Init2(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//Функция вызываемая перед вхождением в главный цикл
void Init3(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//Изменяем размер точки на значение 10 пикселей
	glPointSize(10.0f);
}

//Функция вызываемая каждый кадр — для его отрисовки, вычислений и т. д.
void Update(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

//Функция вызываемая каждый кадр — для его отрисовки, вычислений и т. д.
void Update2(void)
{
	//Текущая — матрица видового преобразования
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f; //Увеличиваем угол поворота
	glClear(GL_COLOR_BUFFER_BIT); //Очистим буфер цвета
	glLoadIdentity(); //Загрузим едматрицу. вида
	//Зададим позицию камеры, точку наблюд. и вектор вверх
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//Применим матрицу поворота на текущую матрицу
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);
	//Отрисуем сферу радиусом 50 ед, размером 10 x10 полигонов
	glutWireSphere(50.0f, 10, 10);
	//Сбросить все данные на обработку в конвейер преобразования
	// OpenGL без ожидания завершения предыдущих инструкций
	glFlush();
	glutSwapBuffers();
}

//Функция вызываемая каждый кадр — для его отрисовки, вычислений и т. д.
void Update3(void)
{
	//Текущая — матрица видового преобразования
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f; //Увеличиваем угол поворота
	glClear(GL_COLOR_BUFFER_BIT); //Очистим буфер цвета
	glLoadIdentity(); //Загрузим едматрицу. вида
	//Зададим позицию камеры, точку наблюд. и вектор вверх
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//Применим матрицу поворота на текущую матрицу
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);
	//Отрисуем сферу радиусом 50 ед, размером 10 x10 полигонов
	glutWireTeapot(50.0f);
	//Сбросить все данные на обработку в конвейер преобразования
	// OpenGL без ожидания завершения предыдущих инструкций
	glFlush();
	glutSwapBuffers();
}

//Функция вызываемая каждый кадр — для его отрисовки, вычислений и т. д.
void Update4(void)
{
	//Текущая — матрица видового преобразования
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.005f; //Увеличиваем угол поворота
	glClear(GL_COLOR_BUFFER_BIT); //Очистим буфер цвета
	glLoadIdentity(); //Загрузим едматрицу. вида
	//Зададим позицию камеры, точку наблюд. и вектор вверх
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//Применим матрицу поворота на текущую матрицу
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);
	//Отрисуем сферу радиусом 50 ед, размером 10 x10 полигонов
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

	//Сбросить все данные на обработку в конвейер преобразования
	// OpenGL без ожидания завершения предыдущих инструкций
	glFlush();
	glutSwapBuffers();
}

//Функция вызываемая каждый кадр — для его отрисовки, вычислений и т. д.
void Update5(void)
{
	//Текущая — матрица видового преобразования
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.005f; //Увеличиваем угол поворота
	glClear(GL_COLOR_BUFFER_BIT); //Очистим буфер цвета
	glLoadIdentity(); //Загрузим едматрицу. вида
	//Зададим позицию камеры, точку наблюд. и вектор вверх
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//Применим матрицу поворота на текущую матрицу
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLES);
	//Текущим - делаем красный цвет по (RGB)
	glColor3f(1.0f, 0.0f, 0.0f);
	//Первый красный треугольник
	glVertex3f(-75.0f, 0.0f, -50.0f);
	glVertex3f(-75.0f, 0.0f, 50.0f);
	glVertex3f(75.0f, 0.0f, 50.0f);
	//Текущим - делаем синий цвет по( RGB)
	glColor3f(0.0f, 0.0f, 1.0f);
	//Рисуем второй синий треугольник
	glVertex3f(-75.0f, 0.0f, -50.0f);
	glVertex3f(75.0f, 0.0f, -50.0f);
	glVertex3f(75.0f, 0.0f, 50.0f);
	glEnd();

	//Сбросить все данные на обработку в конвейер преобразования
	// OpenGL без ожидания завершения предыдущих инструкций
	glFlush();
	glutSwapBuffers();
}

//Функция вызываемая каждый кадр — для его отрисовки, вычислений и т. д.
void Update6(void)
{
	//Текущая — матрица видового преобразования
	glMatrixMode(GL_MODELVIEW);
	Angle += 0.05f; //Увеличиваем угол поворота
	glClear(GL_COLOR_BUFFER_BIT); //Очистим буфер цвета
	glLoadIdentity(); //Загрузим едматрицу. вида
	//Зададим позицию камеры, точку наблюд. и вектор вверх
	gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	//Применим матрицу поворота на текущую матрицу
	glRotatef(Angle, 0.0f, 1.0f, 0.0f);

	GLfloat BlueCol[3] = { 0 , 0 , 1 };
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); /* красный */
	glVertex3f(0.0, 0.0, 0.0);
	glColor3ub(0, 255, 0); /* зеленый */
	glVertex3f(75.0, 0.0, 0.0);
	glColor3fv(BlueCol); /* синий */
	glVertex3f(75.0, 75.0, 0.0);
	glEnd();

	//Сбросить все данные на обработку в конвейер преобразования
	// OpenGL без ожидания завершения предыдущих инструкций
	glFlush();
	glutSwapBuffers();
}

//Функця вызываемая при изменении размеров окна
void Reshape2(int width, int height)
{
	w = width;
	h = height;
	// область для отрисовки — в данном случае: всё окно
	glViewport(0, 0, w, h);
	// Текущая матрица - матрица проективного преобразования
	glMatrixMode(GL_PROJECTION);
	// Сделаем матрицу проективного преобразования единичной
	glLoadIdentity();
	// Применим матрицу перспективного преобразования исходя из заданного угла обзора, отношения ширины к высоте и расстояния ближней и дальней отсекающих плоскостей
	gluPerspective(65.0f, w / h, 1.0f, 1000.0f);
}

//Функця вызываемая при изменении размеров окна
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

	std::cout << "1 — синий экран (стр. 29 в презентации)" << std::endl;
	std::cout << "2 — вращение в 2D квадрата с градиентной закраской вокруг центра экрана (стр. 45 в презентации)" << std::endl;
	std::cout << "3 — вращение в 3D каркасного куба в ортографической проекции (стр. 47 в презентации)" << std::endl;
	std::cout << "4 — вращение в 3D твёрдотельного куба в ортографической проекции (стр. 49 в презентации)" << std::endl;
	std::cout << "5 — вращение в 3D сферы в перспективной проекции (стр. 52 в презентации)" << std::endl;
	std::cout << "6 — вращение в 3D чайника в перспективной проекции (стр. 59 в презентации)" << std::endl;
	std::cout << "7 — вывод размерных точек (стр. 62 в презентации)" << std::endl;
	std::cout << "8 — два треугольника разного цвета (стр. 65 в презентации)" << std::endl;
	std::cout << "9 — вращение в 3D треугольника (с градиентной закраской) вокруг осей координат (стр. 70 в презентации)" << std::endl;

	int number;
	std::cin >> number;
	switch (number)
	{
	case 1:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(800, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL");

		//Укажем glut функцию, которая будет вызываться каждый кадр
		glutIdleFunc(Update);

		//Укажем glut функцию, которая будет рисовать каждый кадр
		glutDisplayFunc(Update);

		//Укажем glut функцию, которая будет вызываться при изменении размера окна приложения
		glutReshapeFunc(Reshape);
		Init();

		break;
	case 2:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(600, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL_HelloWorld");

		glutDisplayFunc(renderRectangle);

		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);

		break;
	case 3:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(600, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL_HelloWorld");

		glutDisplayFunc(renderWireCube);

		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);

		break;
	case 4:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(600, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL_HelloWorld");

		glutDisplayFunc(renderWireCube2);

		glutSpecialFunc(specialKeys);
		glutReshapeFunc(Reshape);

		break;
	case 5:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(800, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL");

		//Укажем glut функцию, которая будет вызываться каждый кадр
		glutIdleFunc(Update2);

		//Укажем glut функцию, которая будет рисовать каждый кадр
		glutDisplayFunc(Update2);

		//Укажем glut функцию, которая будет вызываться при изменении размера окна приложения
		glutReshapeFunc(Reshape2);
		Init2();

		break;
	case 6:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(800, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL");

		//Укажем glut функцию, которая будет вызываться каждый кадр
		glutIdleFunc(Update3);

		//Укажем glut функцию, которая будет рисовать каждый кадр
		glutDisplayFunc(Update3);

		//Укажем glut функцию, которая будет вызываться при изменении размера окна приложения
		glutReshapeFunc(Reshape2);
		Init2();

		break;
	case 7:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(800, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL");

		//Укажем glut функцию, которая будет вызываться каждый кадр
		glutIdleFunc(Update4);

		//Укажем glut функцию, которая будет рисовать каждый кадр
		glutDisplayFunc(Update4);

		//Укажем glut функцию, которая будет вызываться при изменении размера окна приложения
		glutReshapeFunc(Reshape2);
		Init3();

		break;
	case 8:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(800, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL");

		//Укажем glut функцию, которая будет вызываться каждый кадр
		glutIdleFunc(Update5);

		//Укажем glut функцию, которая будет рисовать каждый кадр
		glutDisplayFunc(Update5);

		//Укажем glut функцию, которая будет вызываться при изменении размера окна приложения
		glutReshapeFunc(Reshape2);
		Init3();

		break;
	case 9:
		//Инициализировать сам glut
		glutInit(&argc, argv);

		//Установить начальное положение окна
		glutInitWindowPosition(100, 100);

		//Установить начальные размеры окна
		glutInitWindowSize(800, 600);

		//Установить параметры окна — двойная буфферизация и поддержка цвета RGBA
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

		//Создать окно с заголовком OpenGL
		glutCreateWindow("OpenGL");

		//Укажем glut функцию, которая будет вызываться каждый кадр
		glutIdleFunc(Update6);

		//Укажем glut функцию, которая будет рисовать каждый кадр
		glutDisplayFunc(Update6);

		//Укажем glut функцию, которая будет вызываться при изменении размера окна приложения
		glutReshapeFunc(Reshape2);
		Init3();

		break;
	default:
		break;
	}

	//Войти в главный цикл приложения
	glutMainLoop();
	return 0;
}