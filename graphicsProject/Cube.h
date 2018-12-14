#pragma once
#include "Object.h"
class Cube :
	public Object
{
public:
	Cube();
	Cube(string);
	Vertex getVertex(vec3 p, vec3 c, vec2 uv);
	~Cube();
};

