#pragma once
#include "Rect.h"
class ShipBullet :
	public Rect
{
public:
	GLfloat speed;
	ShipBullet();
	ShipBullet(string);
	void Update(GLfloat);
	~ShipBullet();
};

