#include "HyperbolicParaboloid.h"

HyperbolicParaboloid::HyperbolicParaboloid(float a, float b, int columns, int rows,
	float xMin, float xMax, float yMin, float yMax) : Surface(xMin, xMax, yMin, yMax, columns, rows)
{

	this->a = a;
	this->b = b;

}

Point HyperbolicParaboloid::GetPoint(double x, double y)
{
	double z = ((pow(x, 2) / pow(a, 2)) - (pow(y, 2) / pow(b, 2))) / 2.f;
	return Point(x, y, z);
}
