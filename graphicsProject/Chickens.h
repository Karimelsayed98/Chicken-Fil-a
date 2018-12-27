#pragma once
#include "Rect.h"
#include "Cube.h"
class Chickens :
	public Rect
{
protected:
	bool pos;
	GLuint nextChange;
	GLfloat timebetweenshoot;
	GLfloat next_timetoshoot;
public:
	bool anotherLife;
	Chickens();
	Chickens(string);
	virtual void Update(GLfloat deltaTime);
	bool abletoshoot();
	void shoot(Cube*);
	void Attack();
	~Chickens();
};

