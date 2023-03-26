#include "Icosahedron.h"

Icosahedron::Icosahedron(float x, float z)
{
	_vertices = new float*[12];
	for (int i = 0; i < 12; i++)
		_vertices[i] = new float[3];

	//_vertices[0][0] = { -x, 0, z }; // TODO: c++ ����� ����� �����

	/*_vertices = {
		{-x, 0, z}, {x, 0, z}, {-x, 0, -z}, {x, 0, -z},
   {0, z, x}, {0, z, -x}, {0, -z, x}, {0, -z, -x},
   {z, x, 0}, {-z, x, 0}, {z, -x, 0}, {-z, -x, 0}
	};*/

	auto vertices = new float[12][3];


	// order of faces
	const int faces[20][3] = {
		{0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},
   {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},
   {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6},
   {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11}
	};

	//_indexes = indexes;

}
