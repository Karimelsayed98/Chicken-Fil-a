#pragma once
#include "Rect.h"
#include "Cube.h"
class Chickens :
	public Rect
{
protected:
	bool pos;
	GLuint nextChange;
public:
	GLfloat timebetweenshoot;
	GLfloat next_timetoshoot;
	bool anotherLife;
	Chickens();
	Chickens(string);
	virtual void Update(GLfloat deltaTime);
	bool abletoshoot();
	void shoot(Cube*);
	void Attack();
	~Chickens();
};

