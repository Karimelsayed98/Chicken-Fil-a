#include "BossChicken.h"



BossChicken::BossChicken()
{
}

BossChicken::BossChicken(string textureName) : Chickens(textureName)
{
	this->init();
	//pos = false;
	scaleTheObject(1.5, 1.5, 1.5);
	this->health = 5;

	isAttacking = false;
	isReturning = false;
	BeforeNextAttack = 5.0f;
}
void BossChicken::Update(GLfloat deltaTime)
{
}
vec3 BossChicken::getDistance(vec3 t)
{
	return vec3(t.x - posX, t.y - posY, t.z - posZ);
}
void BossChicken::Update(GLfloat deltaTime, vec3 target)
{
	if (isAttacking == false && isReturning == false)
	{
		if (BeforeNextAttack <= 0)
		{
			isAttacking = true;
			Target = target;
			Distance = getDistance(target);
			Origin = vec3(posX, posY, posZ);
			BeforeNextAttack = 5.0f;
		}
		else
		{
			BeforeNextAttack -= deltaTime;
		}

	}
	else
		Shoot(deltaTime);
}

void BossChicken::Shoot(GLfloat deltaTime)
{
	if (abs(posX - Target.x) <= 0.01 && abs(posY - Target.y) <= 0.01&& abs(posZ - Target.z) <= 0.01&& isAttacking == true)
	{
		isReturning = true;
		isAttacking = false;
		Target = Origin;
		Distance = getDistance(Origin);
	}
	else if (abs(posX - Target.x) <= 0.01 && abs(posY - Target.y) <= 0.01&& abs(posZ - Target.z) <= 0.01&& isReturning == true)
	{
		isReturning = false;
	}
	else
	{
		translateTheObject(Distance.x*deltaTime, Distance.y*deltaTime, Distance.z*deltaTime);

	}
}


BossChicken::~BossChicken()
{
}
