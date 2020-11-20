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

static int task; // номер задания

static int w = 0, h = 0; //Глобальные статические переменные — хранят текущий размер экрана

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;

float Angle = 0;

//Функция вызываемая перед вхождением в главный цикл
void Init(void)
{
	if (task == 1)
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // фон в синий цвет
	else if (task == 7)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // фон в чёрный цвет
		glPointSize(10.0f); // Изменяем размер точки на значение 10 пикселей
	}
	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // фон в чёрный цвет
	}
}

//Функция вызываемая каждый кадр — для его отрисовки, вычислений и т. д.
void Update(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // Очистка буфера цвета
	GLfloat BlueCol[3] = { 0 , 0 , 1 }; // используется только для 9 задания (эта штуковина не хочет в метке работать)
	if (task > 4)
	{
		glMatrixMode(GL_MODELVIEW); // Текущая — матрица видового преобразования
		glLoadIdentity(); // Загружаем единичную матрицу
	}
	switch (task)
	{
	case 5:
		Angle += 0.05f; //Увеличиваем угол поворота
		gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // Задание позиции камеры, точки наблюдения и вектор вверх
		glRotatef(Angle, 0.0f, 1.0f, 0.0f); // Применение матрицы поворота к текущей матрице
		glutWireSphere(50.0f, 10, 10); 	// Рисование сферы радиусом 50 ед, размером 10 x 10 полигонов
		//Сбросить все данные на обработку в конвейер преобразования
		// OpenGL без ожидания завершения предыдущих инструкций
		glFlush(); // Результат команд, которые мы послали раньше, показывает пользователю (сбрасывает все данные на обработку в конвейер преобразований
		// OpenGL без ожидания завершения предыдущих инструкций
		break;
	case 6:

		Angle += 0.05f;
		gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(Angle, 0.0f, 1.0f, 0.0f);
		glutWireTeapot(50.0f); // Рисуем чайник размером 50 единиц
		glFlush();
		break;
	case 7:
		Angle += 0.005f;
		gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(Angle, 0.0f, 1.0f, 0.0f);

		// Отрисовка точек
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

		// Рисуем два треугольника
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f); //Текущим - делаем красный цвет по (RGB)
		//Первый красный треугольник
		glVertex3f(-75.0f, 0.0f, -50.0f);
		glVertex3f(-75.0f, 0.0f, 50.0f);
		glVertex3f(75.0f, 0.0f, 50.0f);

		glColor3f(0.0f, 0.0f, 1.0f); //Текущим - делаем синий цвет по( RGB)
		//Рисуем второй синий треугольник
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

		// Рисуем градиентный треугольник
		//GLfloat BlueCol[3] = { 0 , 0 , 1 };
		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0); /* красный */
		glVertex3f(0.0, 0.0, 0.0);
		glColor3ub(0, 255, 0); /* зеленый */
		glVertex3f(75.0, 0.0, 0.0);
		glColor3fv(BlueCol); /* синий */
		glVertex3f(75.0, 75.0, 0.0);
		glEnd();

		glFlush();
		break;
	default:
		break;
	}
	glutSwapBuffers(); // Так как включена двойная буферизация, то все рисуется на скрытом от пользователя буфере, а затем происходит смена буферов. 
	// Делается это для получения плавной анимации и для того, чтобы не было эффекта мерцания экрана.
}

//Функця вызываемая при изменении размеров окна
void Reshape(int width, int height)
{
	w = width;
	h = height;
	if (task > 4)
	{
		glViewport(0, 0, w, h); // область для отрисовки — в данном случае: всё окно
		glMatrixMode(GL_PROJECTION); // Текущая матрица - матрица проективного преобразования
		glLoadIdentity(); // Сделаем матрицу проективного преобразования единичной
		gluPerspective(65.0f, w / h, 1.0f, 1000.0f); // Применим матрицу перспективного преобразования 
													 // исходя из заданного угла обзора, отношения ширины к высоте и 
													 //расстояния ближней и дальней отсекающих плоскостей
	}
}

void renderRectangle()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_z, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS); // рисование квадрата
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

	std::cout << "1 — синий экран (стр. 29 в презентации)" << std::endl;
	std::cout << "2 — вращение в 2D квадрата с градиентной закраской вокруг центра экрана (стр. 45 в презентации)" << std::endl;
	std::cout << "3 — вращение в 3D каркасного куба в ортографической проекции (стр. 47 в презентации)" << std::endl;
	std::cout << "4 — вращение в 3D твёрдотельного куба в ортографической проекции (стр. 49 в презентации)" << std::endl;
	std::cout << "5 — вращение в 3D сферы в перспективной проекции (стр. 52 в презентации)" << std::endl;
	std::cout << "6 — вращение в 3D чайника в перспективной проекции (стр. 59 в презентации)" << std::endl;
	std::cout << "7 — вывод размерных точек (стр. 62 в презентации)" << std::endl;
	std::cout << "8 — два треугольника разного цвета (стр. 65 в презентации)" << std::endl;
	std::cout << "9 — вращение в 3D треугольника (с градиентной закраской) вокруг осей координат (стр. 70 в презентации)" << std::endl;

	std::cin >> task;

	glutInit(&argc, argv); 	// Инициализация glut
	glutInitWindowPosition(100, 100); 	// Начальное положение окна
	glutInitWindowSize(600, 600); // Начальные размеры окна

	if (task == 1)
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // Установка параметров окна — двойная буфферизация и поддержка цвета RGBA
	else glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); // то же, что и в предыдущем, но + буфферизация глубины

	glutCreateWindow("OpenGL");  // Создаёт окно с заголовком OpenGL

	switch (task)
	{
	case 1:
		glutIdleFunc(Update); // Укажем glut функцию, которая будет вызываться каждый кадр
		glutDisplayFunc(Update); // Укажем glut функцию, которая будет рисовать каждый кадр
		glutReshapeFunc(Reshape); // Укажем glut функцию, которая будет вызываться при изменении размера окна приложения
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

	//Войти в главный цикл приложения
	glutMainLoop();
	return 0;
}