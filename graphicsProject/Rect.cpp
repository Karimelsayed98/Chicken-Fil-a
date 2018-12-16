#include "Rect.h"


Rect::Rect()
{
	this->texture = NULL;
}

Rect::Rect(string tName)
{
	this->verts = {
		getVertex(vec3(-0.25f, -0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(vec3(-0.25f, 0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(vec3(0.25f, -0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(vec3(0.25f, 0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
	};
	this->indices = {
		0, 1, 2,
		1, 2, 3
	};
	if (tName != "") {
		this->texture = new Texture(tName, 0);
	}
	//this->init();
}
Vertex Rect::getVertex(vec3 p, vec3 c, vec2 uv)
{
	Vertex v;
	v.pos = p;
	v.color = c;
	v.UV = uv;
	return v;
}
Rect::~Rect()
{
}
