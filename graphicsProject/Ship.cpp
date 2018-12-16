#include "Ship.h"



Ship::Ship()
{
}
Ship::Ship(string textureName) : Rect(textureName)
{
	this->init();
	this->rotateTheObject(-70.0f, 1, 0, 0);
	//cout << sizeX << ' ' << sizeY << ' ' << sizeZ << endl;
	//this->scaleVector *= scale(vec3(0.5f, 0.5f, 0.5f));
	//translateTheObject(-0.5f, -0.0f, -0.0f);
	scaleTheObject(0.5f, 0.5f, 0.5f);
	//cout << sizeX << ' ' << sizeY << ' ' << sizeZ << endl;
	
}

void Ship::HandleKeyboardInput(int key)
{
	//step on y = el height * el step
	//step on z = el slope bta3 el floor * el step
	// step on x = el width * el step
	GLfloat step = 0.0005f;
	GLfloat stepX = 2.6f* step;
	GLfloat stepY = 1.0f* step;
	GLfloat stepZ = 2.5f* step;
	//cout << posX << ' ' << posY << ' '<< posZ << endl;
	//vec4 vec = this->translateVector*vec4(1.0f, 1.0f, 1.0f ,1.0f)  ; // *vec4(0.0f, 0.0f, 0.0f, 1.0f);
	switch (key)
	{
		//Moving forward
	case GLFW_KEY_UP:
		
		if (posY+stepY <= 0.55f)
			translateTheObject(0.0f, stepY, -stepZ);
		break;
		//Moving backword
	case GLFW_KEY_DOWN:
		if (posY - stepY >= -0.3f)
			translateTheObject(0.0f, -stepY, stepZ);
		break;
		// Moving right
	case GLFW_KEY_RIGHT:
		if (posX +stepX <= 1.11f)
			translateTheObject(stepX,0.0f, 0.0f);
		break;
		// Moving left
	case GLFW_KEY_LEFT:
		if (posX - stepX >= -1.11f)
			translateTheObject(-stepX, 0.0f, 0.0f);
		break;
		// Moving up
	default:
		break;
	}
}

Ship::~Ship()
{
}
