#pragma once
#include "Chickens.h"
class FlashChicken :
	public Chickens
{
	GLfloat stepDistance;
public:
	FlashChicken();
	FlashChicken(string);
	void Update(GLfloat deltaTime);
	~FlashChicken();
};

