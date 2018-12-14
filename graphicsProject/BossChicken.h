#pragma once
#include "Rect.h"
class BossChicken :
	public Rect
{
public:
	BossChicken();
	BossChicken(string);
	void Update();
	void Shoot();
	~BossChicken();
};

