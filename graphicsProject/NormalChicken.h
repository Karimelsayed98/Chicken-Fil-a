#pragma once
#include "Rect.h"
#include "Chickens.h"
class NormalChicken :
	public Chickens
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

