#include "Chickens.h"

#include<time.h>

Chickens::Chickens()
{

}
Chickens::Chickens(string textureName) : Rect(textureName)
{
	this->init();
	pos = false;
	this->health = 1;
	nextChange = 0;
	timebetweenshoot = 15.0f;
	next_timetoshoot = rand()% int(timebetweenshoot);
}

void Chickens::Update(GLfloat deltaTime)
{
	next_timetoshoot -= deltaTime;
}
bool Chickens::abletoshoot() 
{
	if (next_timetoshoot <= 0.0f) 
	{
		next_timetoshoot = timebetweenshoot;
		return true;
	}

}
void Chickens::shoot(Cube* newEgg) 
{

}
Chickens::~Chickens()
{

}
