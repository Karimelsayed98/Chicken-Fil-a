#include "NormalChicken.h"



NormalChicken::NormalChicken()
{
}

NormalChicken::NormalChicken(string textureName) : Rect (textureName)
{
	this->init();
	this->rotateTheObject(-70.0f, 1, 0, 0);

}

void NormalChicken::Update()
{
}

void NormalChicken::Shoot()
{
}


NormalChicken::~NormalChicken()
{
}
