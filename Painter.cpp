#include "Painter.h"

void Painter::DrawDodecahedron(Dodecahedron dodecahedron)
{
	for (int i = 0; i < 12; i++)
	{
		Color currentColor = dodecahedron.colors[i];
		glColor3f(currentColor.R, currentColor.G, currentColor.B);

		// ������ �����
		glBegin(GL_TRIANGLE_FAN);
		for (int j = 0; j < 5; j++)
			glVertex3dv(dodecahedron.points[dodecahedron.faces[i][j]]);
		glEnd();

		glLineWidth(3);
		glColor3f(0, 0, 0);

		// ������ �����
		glBegin(GL_LINE_STRIP);
		for (int x = 0; x < 5; x++)
			glVertex3dv(dodecahedron.points[dodecahedron.faces[i][x]]);
		glEnd();
	}
}

void Painter::DrawHyperbolicParaboloid(HyperbolicParaboloid paraboloid, Color color)
{
	glColor4f(color.R, color.G, color.B, 0.5f);
	paraboloid.Draw();
}
