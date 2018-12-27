#include "ShipBullet.h"



ShipBullet::ShipBullet()
{

}
ShipBullet::ShipBullet(string TextureName) : Rect(TextureName)
{
	this->init();
	this->rotateTheObject(-70.0f, 1, 0, 0);
	this->scaleTheObject(0.3f, 0.3f, 0.3f);
	speed = 1.0f;
}
void ShipBullet::Update(GLfloat deltatime) 
{
	if(this->posY < 0.55f)
	this->translateTheObject(0.0f, speed*deltatime, -(speed*2.5f*deltatime));
}
ShipBullet::~ShipBullet()
{
}
