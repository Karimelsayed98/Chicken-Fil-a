#pragma once
#include "Rect.h"
class NormalChicken :
	public Rect
{
	bool pos;
	GLuint nextChange;
public:
	NormalChicken();
	NormalChicken(string);
	void Update(GLfloat deltaTime);
	void Shoot();
	~NormalChicken();
};

