#pragma once
#include "Chickens.h"
class BossChicken :
	public Chickens
{
public:
	vec3 Target;
	vec3 Origin;
	vec3 Distance;
	GLfloat BeforeNextAttack;
	bool isAttacking;
	bool isReturning;
	BossChicken();
	BossChicken(string);
	void Update(GLfloat deltaTime);
	vec3 getDistance(vec3 t);
	void Update(GLfloat deltaTime, vec3 target);
	void Shoot(GLfloat deltaTime);
	~BossChicken();
};

