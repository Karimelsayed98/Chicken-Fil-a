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
	srand(glfwGetTime()*100000);
	timebetweenshoot = rand() %20;
	next_timetoshoot = (rand()% int(timebetweenshoot) );
	cout << next_timetoshoot << endl;
}

void Chickens::Update(GLfloat deltaTime)
{
	next_timetoshoot -= deltaTime;
}
bool Chickens::abletoshoot() 
{
	if (next_timetoshoot <= 0.0f)
	{
		return true;
	}
	return false;
}
void Chickens::shoot(Cube* newEgg) 
{

}
Chickens::~Chickens()
{

}
