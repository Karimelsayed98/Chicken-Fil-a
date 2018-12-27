#include "sphere.h"
#include <iostream>


sphere::sphere()
{
	/*float x = 50, z = 50;
	x = -0.50f;
	//z = -0.50f;
	//sqrt(0.5f*0.5f - x * x - (0.5f*0.5f - x * x - z * z))
	for (int i = 0; i < 101; i ++)
	{
	     getVertex(vec3(x, sqrt(0.5f*0.5f - x * x - z * z),-3), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f));
	     x += 0.010f;
		// z += 0.010f;
	}
	 x = 0.50f;
	// z = 0.50f;
	for (int i = 103; i < 201; i ++)
    {
		getVertex(vec3(x,-sqrt(0.5f*0.5f - x * x - z * z), -3), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f));
		x -= 0.010f;
		//z -= 0.010f;
	}
	
	for (int i = 0; i < 603; i +=3) {
		normals.push_back(0);
		normals.push_back(1);
		normals.push_back(0);
	}*/
	/*for (int i = 0; i < 4; i++) {
		getVertex(vec3(-0.25f, -0.25f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f));
	}*/
	for (int i = 0; i < 201; i++) {
		indices.push_back(i);
	}
	for (int i = 0; i < 603; i++) {
		normals.push_back(0);
		normals.push_back(1);
		normals.push_back(0);
	}
}

Vertex sphere::getVertex(vec3 p, vec3 c, vec2 uv)
{
	Vertex v;
	v.pos = p;
	v.color = c;
	v.UV = uv;
	return v;
}

sphere::~sphere()
{
}
