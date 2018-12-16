#include "Ship.h"



Ship::Ship()
{
}
Ship::Ship(string textureName) : Rect(textureName)
{
	this->init();
	this->rotateTheObject(-70.0f, 1, 0, 0);
	
	//cout << sizeX << ' ' << sizeY << ' ' << sizeZ << endl;
	translateTheObject(-0.5f, -0.0f, -0.0f);
	scaleTheObject(0.5f, 0.5f, 0.5f);


	//step on y = el height * el step
	//step on z = el slope bta3 el floor * el step
	// step on x = el width * el step
	stepDistance = 1.0f;
	stepX = 2.6f* stepDistance;
	stepY = 1.0f* stepDistance;
	stepZ = 2.5f* stepDistance;
	timeBetweenShoots = 0.5f;
	nextShoot = 0;
}

bool Ship::HandleKeyboardInput(int key, GLfloat deltaTime)
{
	//cout << posX << ' ' << posY << ' '<< posZ << endl;
	switch (key)
	{
		//Moving forward
	case GLFW_KEY_UP:
		
		if (posY+(stepY *deltaTime )<= 0.48f)
			translateTheObject(0.0f, stepY*deltaTime, -stepZ * deltaTime);
		
		break;
		//Moving backward
	case GLFW_KEY_DOWN:
		if (posY - (stepY *deltaTime )>= -0.39f)
			translateTheObject(0.0f, -stepY * deltaTime, stepZ*deltaTime);
		
		break;
		// Moving right
	case GLFW_KEY_RIGHT:
		if (posX +(stepX *deltaTime )<= 1.11f)
			translateTheObject(stepX*deltaTime,0.0f, 0.0f);
		
		break;
		// Moving left
	case GLFW_KEY_LEFT:
		if (posX - (stepX *deltaTime )>= -1.11f)
			translateTheObject(-stepX * deltaTime, 0.0f, 0.0f);
		
		break;
		// Moving up
	default:
		return false;
		break;
	}
	return true;
}

Ship::~Ship()
{
}
