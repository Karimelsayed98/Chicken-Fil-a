#include "Cube.h"



Cube::Cube()
{
	this->texture = NULL;

}

Cube::Cube(string tName)
{
	this->verts = {
		// upper Face
		getVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(vec3(-0.5f, 0.5f, -0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(vec3(0.5f, 0.5f, -0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
		// bottom Face
		getVertex(vec3(-0.5f, -0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(vec3(0.5f, -0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(vec3(-0.5f, -0.5f, -0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(vec3(0.5f, -0.5f, -0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
	};
	this->indices = {
		// Top
		0, 1, 2,
		1, 2, 3, 
		// bottom
		4, 5, 6,
		5, 6, 7,
		// front
		1, 4, 5,
		0, 1, 4,
		// back
		2, 6, 7,
		7, 3, 6,
		//right
		5, 1, 7,
		7, 1, 3,
		//left
		0, 4, 2,
		4, 6, 2,
	};
	
	if (tName != "") {
		this->texture = new Texture(tName, 0);
	}
	this->init();
}

Vertex Cube::getVertex(vec3 p, vec3 c, vec2 uv)
{
	Vertex v;
	v.pos = p;
	v.color = c;
	v.UV = uv;
	return v;
}


Cube::~Cube()
{
}
