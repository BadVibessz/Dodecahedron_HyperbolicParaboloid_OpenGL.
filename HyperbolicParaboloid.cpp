#include "HyperbolicParaboloid.h"

HyperbolicParaboloid::HyperbolicParaboloid(float a, float b, float x1, float x2,
	float y1, float y2, float step1, float step2)
{
	vertices = vector<Point*>();

	this->xMin = x1;
	this->xMax = x2;
	this->yMin = y1;
	this->yMax = y2;

	xStep = step1;
	yStep = step2;

	float x = xMin;
	float y;
	float z;

	while (x <= xMax)
	{
		y = yMin;
		while (y <= yMax)
		{
			z = ((pow(x, 2) / pow(a, 2)) - (pow(y, 2) / pow(b, 2))) / 2.f;

			vertices.push_back(new Point(x, y, z));
			y += yStep;
		}
		x += xStep;
	}
}

