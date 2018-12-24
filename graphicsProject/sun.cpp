#include "sun.h"



sun::sun()
{
	this->verts = {
		getVertex(vec3(-0.25f, -0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(vec3(-0.25f, 0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(vec3(0.25f, -0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(vec3(0.25f, 0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
	};
	//TypeID = 2;
	this->init(2);
}


sun::~sun()
{
}
