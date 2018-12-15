#include "SpaceFloor.h"


SpaceFloor::SpaceFloor() 
{
}
SpaceFloor::SpaceFloor(string textureName) : Rect(textureName)
{
	//this->translateVector = vec3(0.0f, 0.0f, -1.0f);
	this->verts[0].pos = vec3(-1.3f,-0.5f,1.0f);
	this->verts[1].pos = vec3(-1.3f, 0.5f, -1.5f);
	this->verts[2].pos = vec3(1.3f, -0.5f, 1.0f);
	this->verts[3].pos = vec3(1.3f, 0.5f, -1.5f);
	this->init();
	//this->scaleTheObject(5.2f, 2.0f, 2.5f);
	//this->translateTheObject(0.0f, 0.0f, 0.0f);

	//this->rotateTheObject(-45.0f, 1, 0, 0);
}


SpaceFloor::~SpaceFloor()
{
}
