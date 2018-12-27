#include "Egg.h"



Egg::Egg()
{
}

Egg::Egg(string texture , GLfloat x , GLfloat y , GLfloat z):Cube(texture)
{
	this->translateTheObject(x, y, z);
	speed = 0.1;
}
void Egg::update(GLfloat deltatime)
{
	if (this->posY > -0.37f)
	{
		this->translateTheObject(0.0f, -(speed*deltatime), (speed*2.5f*deltatime));
	}
	else 
	{
		isdead = true;
	}
}

Egg::~Egg()
{
}
