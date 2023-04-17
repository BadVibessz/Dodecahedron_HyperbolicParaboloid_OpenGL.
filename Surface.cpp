#include "Surface.h"

Surface::Surface(float xMin, float xMax, float yMin, float yMax, int columns, int rows)
{

	this->xMin = xMin;
	this->xMax = xMax;
	this->yMin = yMin;
	this->yMax = yMax;
	this->columsCount = columns;
	this->rowsCount = rows;
}

void Surface::Draw()
{

	// вычисляем шаг узлов сетки
	float dx = (xMax - xMin) / (columsCount - 1);
	float dy = (yMax - yMin) / (rowsCount - 1);

	float y = yMin;
	// пробегаем по строкам сетки
	for (int row = 0; row < rowsCount - 1; row++, y += dy)
	{
		// каждой строке будет соответствовать своя лента из треугольников
		glBegin(GL_TRIANGLE_STRIP);
		float x = xMin;

		// пробегаем по столбцам текущей строки
		for (int column = 0; column <= columsCount; column++, x += dx)
		{
			// вычисляем параметры вершины в узлах пары соседних вершин
			// ленты из треугольников
			auto p0 = GetPoint(x, y + dy);
			auto p1 = GetPoint(x, y);

			// задаем координаты вершины на четной позиции
			glVertex3f(p0.x, p0.y, p0.z);

			// задаем координаты вершины на нечетной позиции
			glVertex3f(p1.x, p1.y, p1.z);

		}
		glEnd();
	}






}
