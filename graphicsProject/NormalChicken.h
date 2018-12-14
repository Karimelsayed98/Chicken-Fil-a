#pragma once
#include "Rect.h"
class NormalChicken :
	public Rect
{
public:
	NormalChicken();
	NormalChicken(string);
	void Update();
	void Shoot();
	~NormalChicken();
};

