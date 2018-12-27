#include "Cube.h"



Cube::Cube()
{
	this->texture = NULL;
}

Cube::Cube(string tName)
{
	vec3 v1 = vec3(-0.25f, 0.25f, -0.25f);
	vec3 v2 = vec3( 0.25f, 0.25f, -0.25f);
	vec3 v3 = vec3( 0.25f, 0.25f,  0.25f);
	vec3 v4 = vec3(-0.25f, 0.25f,  0.25f);

	vec3 v5 = vec3(-0.25f, -0.25f, -0.25f);
	vec3 v6 = vec3(0.25f, -0.25f, -0.25f);
	vec3 v7 = vec3(0.25f, -0.25f, 0.25f);
	vec3 v8 = vec3(-0.25f, -0.25f, 0.25f);
	this->verts = {
		//upper face
		getVertex(v1, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(v2, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(v4, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(v3, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
		//right face
		getVertex(v2, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(v3, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(v6, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(v7, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
		//left face
		getVertex(v1, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(v5, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(v4, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(v8, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
		//back face
		getVertex(v1, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(v5, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(v2, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(v6, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
		//front face
		getVertex(v4, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(v8, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(v3, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(v7, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
		//bottom face
		getVertex(v5, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
		getVertex(v6, vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
		getVertex(v8, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),
		getVertex(v7, vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
	};

	this->indices = {
		0,1,2,
		1,2,3,

		4,5,6,
		5,6,7,

		8,9,10,
		9,10,11,

		12,13,14,
		13,14,15,

		16,17,18,
		17,18,19,

		20,21,22,
		21,22,23
	};

	posX = 0.0f;
	posY = 0.0f; 
	posZ = 0.0f;
	sizeX = 0.5f;
	sizeY = 0.5f;
	sizeZ = 0.5f;
	/*
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
	
	*/
	if (tName != "") {
		this->texture = new Texture(tName, 0);
	}
	this->init();
	scaleTheObject(0.15, 0.15, 0.15);
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
