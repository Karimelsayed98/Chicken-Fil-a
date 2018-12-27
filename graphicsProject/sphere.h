#pragma once
#include "Object.h"
class sphere :
	public Object
{
public:
	sphere();
	Vertex getVertex(vec3 p, vec3 c, vec2 uv);
	~sphere();
};


