#include "FlashChicken.h"



FlashChicken::FlashChicken()
{
}

FlashChicken::FlashChicken(string tname) : NormalChicken(tname)
{
	this->init();
	pos = false;
	this->health = 1;
	nextChange = 0;
	stepDistance = 1.0f;
}

void FlashChicken::Update(GLfloat deltaTime)
{
	
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
