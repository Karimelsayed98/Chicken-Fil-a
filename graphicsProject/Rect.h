#pragma once
#include "Object.h"
class Rect :
	public Object
{
public:
	Rect();
	Rect(string);
	Vertex getVertex(vec3 p, vec3 c, vec2 uv);
	~Rect();
};

