#pragma once
#include "Rect.h"
class Ship :
	public Rect
{
public:
	Ship();
	Ship(string textureName);
	void HandleKeyboardInput(int key);
	~Ship();
};

