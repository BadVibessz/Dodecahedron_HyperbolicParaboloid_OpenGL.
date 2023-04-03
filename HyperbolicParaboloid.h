#pragma once
#include <vector>

#include "GL/glut.h"
#include "Point.h"

using namespace std;

class HyperbolicParaboloid
{
public:
	vector<Point*> vertices;

	float xMin, xMax, yMin, yMax;
	float a, b;

	float yStep, xStep;

	HyperbolicParaboloid(float a, float b, float x1 = -2.f, float x2 = 2.f,
		float y1 = -2.f, float y2 = 2.f, float step1 = 0.01f, float step2 = 0.01f);
};

