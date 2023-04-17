#pragma once
#include "Point.h"
#include "GL/glut.h"


class Surface
{
private:
	float xMin, xMax;
	float yMin, yMax;

	int columsCount, rowsCount;


protected:
	virtual Point GetPoint(double x, double y) = 0;

public:

	Surface(float xMin, float xMax, float yMin,
		float yMax, int columns, int rows);

	void Draw();




};

