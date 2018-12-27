#pragma once
#include "Cube.h"
class Egg :
	public Cube
{
	GLfloat speed;
public:
	bool isdead;
	Egg();
	Egg(string);
	Egg(string,GLfloat,GLfloat,GLfloat);
	void update(GLfloat deltatime);
	~Egg();
};

