#pragma once
#include "GL/glut.h"
#include "Dodecahedron.h"
#include "HyperbolicParaboloid.h"

class Painter
{
public:
	static void DrawDodecahedron(Dodecahedron dodecahedron);

	static void DrawHyperbolicParaboloid(HyperbolicParaboloid paraboloid, Color color);
};

