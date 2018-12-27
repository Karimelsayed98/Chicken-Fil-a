#include "ShipBullet.h"



ShipBullet::ShipBullet()
{

}
ShipBullet::ShipBullet(string textureName) :Rect(textureName)
{
	this->init();
	this->rotateTheObject(-70.0f, 1, 0, 0);
	this->scaleTheObject(0.5, 0.5, 0.5);
}
void ShipBullet::HandleMouseInput(int key) 
{
	if (key == -1)
		return;
	//lw das 3al left click yeb2 ye3ml translate lel bullet
	switch (key)
	{
	case GLFW_KEY_UP:
		this->Update();
	default:
		return;
	}
}
void ShipBullet::Update() 
{
	
	if (this->posZ < 1 && this->posY<0.5)
	translateTheObject(0.0f, 0.001f, -(0.001f*2.5f));
}
ShipBullet::~ShipBullet()
{
}
