#pragma once
#include "Rect.h"
class Chickens :
	public Rect
{
protected:
	bool pos;
	GLuint nextChange;
public:
	bool anotherLife;
	Chickens();
	Chickens(string);
	virtual void Update(GLfloat deltaTime);
	void Attack();
	~Chickens();
};

