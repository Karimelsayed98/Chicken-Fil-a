#include "NormalChicken.h"



NormalChicken::NormalChicken()
{
}

NormalChicken::NormalChicken(string textureName) : Rect (textureName)
{
	this->init();
	this->rotateTheObject(-70.0f, 1, 0, 0);
	pos = false;
	this->health = 3;
	nextChange = 0;
}

void NormalChicken::Update(GLfloat deltaTime)
{
	GLfloat dis = 0.005f;
	if (pos == 0 && nextChange <= 450)
	{
		this->translateTheObject(dis, dis, -dis);
		pos = true;
	}
	else if (pos == 1 && nextChange<=900)
	{
		this->translateTheObject(-dis, -dis, dis);
		pos = false;
		nextChange = 0;
	}
	nextChange++;
}

void NormalChicken::Shoot()
{
}


NormalChicken::~NormalChicken()
{
}
