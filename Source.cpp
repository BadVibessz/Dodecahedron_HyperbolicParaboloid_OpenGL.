#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h> 
#include <random>
#include <functional>

#include "Painter.h"
#include "HyperbolicParaboloid.h"

using namespace std;

bool isMouseDown = false;

float xRotation = 100.f;
float yRotation = -100.f;

float xDiff = 100.f;
float yDiff = 100.f;

float closeness = -4.f; // from -20 to - 4

auto dodecahedron = Dodecahedron();
auto paraboloid = HyperbolicParaboloid(1, 1);



static void Resize(int width, int height)
{
	const float aspectRatio = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// умножает текущую матрицу на матрицу перспективы.
	glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DisplayInit()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищаем буффер

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0, 0, closeness); // приближаем/отдаляем

	glRotatef(xRotation, 1.0f, 0.0f, 0.0f);  // поворот вокруг оси x
	glRotatef(yRotation, 0.0f, 1.0f, 0.0f); // поворот вокруг оси y
}

void DisplayDodecahedron()
{
	DisplayInit();

	Painter::DrawDodecahedron(dodecahedron);
	glutSwapBuffers();
}

void DisplayHyperbolicParaboloid()
{
	DisplayInit();

	Painter::DrawHyperbolicParaboloid(paraboloid,
		Color(21 / 255.f, 152 / 255.f, 149 / 255.f));
	glutSwapBuffers();
}

void MouseFunction(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			isMouseDown = true;

			xDiff = x - yRotation;
			yDiff = -y + xRotation;
			break;
		}
	}
	else
		isMouseDown = false;
}

void MouseMotionFunction(int x, int y)
{
	if (isMouseDown)
	{
		yRotation = x - xDiff;
		xRotation = y + yDiff;

		glutPostRedisplay();
	}
}

void KeyboardFunction(unsigned char key, int x, int y)
{
	float speed = 0.5f;
	switch (key)
	{
	case 'w':
		if (closeness + speed <= -4)
			closeness += speed;
		break;
	case 's':
		if (closeness - speed >= -20)
			closeness -= speed;
		break;
	}

	glutPostRedisplay(); // repaints active window
}

static void InitializeWindow(int width, int height, int x, int y, const char* title, void(*displayFunction)())
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutInitWindowSize(width, height);
	glutInitWindowPosition(x, y);

	glutCreateWindow(title);
	glutDisplayFunc(displayFunction);

	// mouse
	glutMouseFunc(&MouseFunction);
	glutMotionFunc(&MouseMotionFunction);

	// keyboard
	glutKeyboardFunc(&KeyboardFunction);

	glutReshapeFunc(&Resize);

	glEnable(GLUT_MULTISAMPLE); // сглаживание
	glEnable(GL_DEPTH_TEST); // включает сравнивания глубин и запись в буффер глубины
	glDepthFunc(GL_LESS); // Передает значение, если входящее z-значение меньше сохраненного значения z

	glClearColor(1, 1, 1, 1);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	InitializeWindow(600, 480, 100, 100, "Dodecahedron", &DisplayDodecahedron);
	InitializeWindow(600, 480, 800, 100, "Hyperbolic Paraboloid", &DisplayHyperbolicParaboloid);

	glutMainLoop();
	return 0;
}