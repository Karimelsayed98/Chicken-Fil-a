#include "FlashChicken.h"



FlashChicken::FlashChicken()
{
}

FlashChicken::FlashChicken(string tname) : Chickens(tname)
{
	this->init();
	pos = false;
	this->health = 1;
	nextChange = 0;
	stepDistance = 1.0f;
	this->translateTheObject(0.0f, 0.45, -1.0);
}

void FlashChicken::Update(GLfloat deltaTime)
{
	next_timetoshoot -= deltaTime;
	if (pos && this->posX <= 1.11f) {
		translateTheObject(stepDistance * deltaTime, 0.0f, 0.0f);
		if (posX > 1.11f)
			pos = !pos;
	}
	else if (!pos && this->posX >= -1.11f) {
		translateTheObject(-(stepDistance * deltaTime), 0.0f, 0.0f);
		if (posX < -1.11f)
			pos = !pos;
	}
}



FlashChicken::~FlashChicken()
{
}
