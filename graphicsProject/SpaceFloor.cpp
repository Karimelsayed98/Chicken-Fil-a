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
	//this->scaleVector = vec3(1.0f, 5.0f, 5.0f);
	this->init();
	//this->rotateTheObject(-45.0f, 1, 0, 0);
}


SpaceFloor::~SpaceFloor()
{
}
