#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h> 
#include <random>
#include <functional>

#include "Color.h"

using namespace std;

bool isMouseDown = false;

float xRotation = 100.f;
float yRotation = -100.f;

float xDiff = 100.f;
float yDiff = 100.f;

float closeness = -4.f; // from -20 to - 4


void DrawDodecahedron()
{
	int faces[12][5] =
	{
		{0, 16, 2, 10, 8},
		{0, 8, 4, 14, 12},
		{16, 17, 1, 12, 0},
		{1, 9, 11, 3, 17},
		{1, 12, 14, 5, 9},
		{2, 13, 15, 6, 10},
		{13, 3, 17, 16, 2},
		{3, 11, 7, 15, 13},
		{4, 8, 10, 6, 18},
		{14, 5, 19, 18, 4},
		{5, 19, 7, 11, 9},
		{15, 7, 19, 18, 6}
	};
	double points[20][3] =
	{
		{1, 1, 1},
		{1, 1, -1},
		{1, -1, 1},
		{1, -1, -1},
		{-1, 1, 1},
		{-1, 1, -1},
		{-1, -1, 1},
		{-1, -1, -1},
		{0, 0.618, 1.618},
		{0, 0.618, -1.618},
		{0, -0.618, 1.618},
		{0, -0.618, -1.618},
		{0.618, 1.618, 0},
		{0.618, -1.618, 0},
		{-0.618, 1.618, 0},
		{-0.618, -1.618, 0},
		{1.618, 0, 0.618},
		{1.618, 0, -0.618},
		{-1.618, 0, 0.618},
		{-1.618, 0, -0.618}
	};


	Color colors[5]{
		Color(167 / 255.f, 201 / 255.f, 87 / 255.f),
		Color(242 / 255.f, 233 / 255.f, 207 / 255.f),
		Color(188 / 255.f, 71 / 255.f, 73 / 255.f),
		Color(201 / 255.f, 173 / 255.f, 167 / 255.f),
		Color(74 / 255.f, 78 / 255.f, 105 / 255.f),
	};

	for (int i = 0; i < 12; i++)
	{
		Color currentColor = colors[i % 5];
		glColor3f(currentColor.R, currentColor.G, currentColor.B);

		glBegin(GL_TRIANGLE_FAN);
		for (int j = 0; j < 5; j++)
			glVertex3dv(points[faces[i][j]]);
		glEnd();


		glLineWidth(3);
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_STRIP);
		for (int x = 0; x < 5; x++)
			glVertex3dv(points[faces[i][x]]);
		glVertex3dv(points[faces[i][0]]);
		glEnd();
	}

	glDisableClientState(GL_VERTEX_ARRAY);

}

void DrawIcosahedron(float x, float z)
{
	const float vertices[12][3] = {
		{-x, 0.0, z}, {x, 0.0, z}, {-x, 0.0, -z}, {x, 0.0, -z},
   {0.0, z, x}, {0.0, z, -x}, {0.0, -z, x}, {0.0, -z, -x},
   {z, x, 0.0}, {-z, x, 0.0}, {z, -x, 0.0}, {-z, -x, 0.0}
	};

	const int faces[20][3] = {
		{0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},
   {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},
   {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6},
   {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11}
	};


	Color colors[3]{
		Color(228 / 255.f, 230 / 255.f, 195 / 255.f),
		Color(137 / 255.f, 152 / 255.f, 120 / 255.f),
		Color(34 / 255.f, 39 / 255.f, 37 / 255.f)
	};


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glEnableClientState(GL_VERTEX_ARRAY);

	for (int i = 0; i < 20; i++)
	{
		Color currentColor = colors[i % 3];
		glColor3f(currentColor.R, currentColor.G, currentColor.B);

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &faces[i]);

		glLineWidth(3);
		glColor3f(0, 0, 0);
		glDrawElements(GL_LINE_STRIP, 3, GL_UNSIGNED_INT, &faces[i]);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
}


static void Resize(int width, int height)
{
	const float aspectRatio = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, 2.0, 100.0); // умножает текущую матрицу на матрицу перспективы.

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void DisplayInit()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищаем буффер

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0, 0, closeness); // приближаем/отдаляем
	//glScaled(1, 1, 1); // коэффициенты масштабирования по осям x y z 

	glRotatef(xRotation, 1.0f, 0.0f, 0.0f);  // поворот вокруг оси x
	glRotatef(yRotation, 0.0f, 1.0f, 0.0f); // поворот вокруг оси y

}

static void DisplayIcosahedron()
{
	DisplayInit();
	DrawIcosahedron(1.25, 1.25);
	glutSwapBuffers(); // отрисовываем
}

static void DisplayDodecahedron()
{
	DisplayInit();
	DrawDodecahedron();
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

	InitializeWindow(600, 480, 100, 100, "Icosahedron", &DisplayIcosahedron);
	InitializeWindow(600, 480, 800, 100, "Dodecahedron", &DisplayDodecahedron);

	glutMainLoop();
	return 0;
}