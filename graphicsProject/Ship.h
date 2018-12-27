#pragma once
#include "Rect.h"
class Ship :
	public Rect
{
public:
	GLfloat nextShoot;
	GLfloat timeBetweenShoots;
	GLfloat stepDistance;
	GLfloat stepX ;
	GLfloat stepY ;
	GLfloat stepZ ;
	Ship();
	Ship(string textureName);
	bool HandleKeyboardInput(int key , GLfloat deltaTime);
	~Ship();
};

