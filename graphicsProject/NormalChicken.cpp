#include "NormalChicken.h"



NormalChicken::NormalChicken()
{
}

NormalChicken::NormalChicken(string textureName) : Chickens (textureName)
{
	anotherLife = true;
	/*
	this->init();
	pos = false;
	this->health = 1;
	nextChange = 0;
	*/
}

void NormalChicken::Update(GLfloat deltaTime)
{
	next_timetoshoot -= deltaTime;
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
