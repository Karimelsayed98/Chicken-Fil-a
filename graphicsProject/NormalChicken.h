#pragma once
#include "Rect.h"
class NormalChicken :
	public Rect
{
protected:
	bool pos;
	GLuint nextChange;
public:
	NormalChicken();
	NormalChicken(string);
	virtual void Update(GLfloat deltaTime);
	void Shoot();
	~NormalChicken();
};

