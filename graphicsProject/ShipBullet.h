#pragma once
#include"Rect.h"
class ShipBullet :
	public Rect
{
public:
	ShipBullet();
	ShipBullet(string);
	void HandleMouseInput(int key);
	void Update();
	~ShipBullet();
};

