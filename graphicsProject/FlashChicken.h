#pragma once
#include "NormalChicken.h"
class FlashChicken :
	public NormalChicken
{
	GLfloat stepDistance;
public:
	FlashChicken();
	FlashChicken(string);
	void Update(GLfloat deltaTime);
	~FlashChicken();
};

