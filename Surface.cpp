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

	// ��������� ��� ����� �����
	float dx = (xMax - xMin) / (columsCount - 1);
	float dy = (yMax - yMin) / (rowsCount - 1);

	float y = yMin;
	// ��������� �� ������� �����
	for (int row = 0; row < rowsCount - 1; row++, y += dy)
	{
		// ������ ������ ����� ��������������� ���� ����� �� �������������
		glBegin(GL_TRIANGLE_STRIP);
		float x = xMin;

		// ��������� �� �������� ������� ������
		for (int column = 0; column <= columsCount; column++, x += dx)
		{
			// ��������� ��������� ������� � ����� ���� �������� ������
			// ����� �� �������������
			auto p0 = GetPoint(x, y + dy);
			auto p1 = GetPoint(x, y);

			// ������ ���������� ������� �� ������ �������
			glVertex3f(p0.x, p0.y, p0.z);

			// ������ ���������� ������� �� �������� �������
			glVertex3f(p1.x, p1.y, p1.z);

		}
		glEnd();
	}






}
