#pragma once
#include <vector>

#include "Surface.h"

using namespace std;

class HyperbolicParaboloid : public Surface
{
public:

	float a, b;

	HyperbolicParaboloid(float a, float b, int columns, int rows, float xMin = -2.f, float xMax = 2.f,
		float yMin = -2.f, float yMax = 2.f);

	Point GetPoint(double x, double y) override;


private:



};

