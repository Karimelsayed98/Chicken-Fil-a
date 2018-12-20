#include "Chickens.h"



Chickens::Chickens()
{

}
Chickens::Chickens(string textureName) : Rect(textureName)
{
	this->init();
	pos = false;
	this->health = 1;
	nextChange = 0;
}

void Chickens::Update(GLfloat deltaTime)
{
}

Chickens::~Chickens()
{
}
