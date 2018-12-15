#include "gameController.h"



void gameController::Cleanup()
{
	glDeleteProgram(programID);
}

gameController::gameController()
{
}

void gameController::init()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	programID = LoadShaders("VertexShader.vertexshader", "FragmentShader.fragmentshader");
	glUseProgram(programID);
	ProjectionMatrixID = glGetUniformLocation(programID, "ProjectionMatrix");
	ViewMatrixID = glGetUniformLocation(programID, "ViewMatrix");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	normalChicken = new NormalChicken ("chicken2.png");
	normalChickens.push_back(normalChicken);
	//normalChicken = new NormalChicken("chicken2.png");
	//normalChicken->translateTheObject(-0.25f, 0, 0);
	//normalChickens.push_back(normalChicken);
	//bossChicken = new BossChicken ("Bosschicken2.png");
	ship = new Ship("ship.png");
	//c = new Cube("Bosschicken2.png");
	spaceFloor = new SpaceFloor("space.png");
}

void gameController::draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	cameraVP();

	spaceFloor->draw(programID);
	for (int i = 0; i < normalChickens.size(); i++)
	{
	normalChickens[i]->draw(programID);

	}
	ship->draw(programID);
	//bossChicken->draw(programID);
	//bossChicken->translateVector = vec3(0.5f, 0.0f, 0.0f);
	//bossChicken->scaleVector = vec3(3.0f, 3.0f, 1.0f);
	//c->draw(programID);
}

void gameController::update()
{
}

void gameController::detectCollisions()
{
}

void gameController::HandleKeyboardInput(int key)
{
	if (key == -1)
		return;
	for (int i = 0; i < normalChickens.size(); i++)
	{

		if (thereIsCollision(ship, normalChickens[i]))
		{
			//normalChickens[i]->Died = true;
			//normalChickens[i] = normalChickens[normalChickens.size() - 1];
			//normalChickens.pop_back();
			cout << i << endl;
			//i--;
		}
	}
	//printf("key : %d \n", key);
	ship->HandleKeyboardInput(key);
	switch (key)
	{
		//Moving forward
	case GLFW_KEY_W:
		camera.Walk(0.01);
		break;
		//Moving backword
	case GLFW_KEY_S:
		camera.Walk(-0.01);
		break;
		// Moving right
	case GLFW_KEY_D:
		camera.Strafe(0.01);
		break;
		// Moving left
	case GLFW_KEY_A:
		camera.Strafe(-0.01);
		break;
		// Moving up
	case GLFW_KEY_R:
		camera.Fly(0.01);
		break;
		// Moving down
	case GLFW_KEY_F:
		camera.Fly(-0.01);
		break;
	case GLFW_KEY_E:
		camera.Yaw(0.5f);
		break;
	case GLFW_KEY_Q:
		camera.Yaw(-0.5f);
		break;
	default:
		break;
	}
	//continue the remaining movements.
	camera.UpdateViewMatrix();
}

void gameController::cameraVP()
{
	this->ViewMatrix = camera.GetViewMatrix();
	this->ProjectionMatrix = camera.GetProjectionMatrix();
	glUniformMatrix4fv(ProjectionMatrixID, 1, GL_FALSE, &ProjectionMatrix[0][0]);
	glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);
}

bool gameController::thereIsCollision(Object * a, Object * b)
{
	/*
	bool collisionX = a->posX + a->sizeX / 2.0 >= b->posX && b->posX + b->sizeX / 2.0 >= a->posX ;
	bool collisionY = a->posY + a->sizeY / 2.0 >= b->posY && b->posY + b->sizeY / 2.0 >= a->posY;
	bool collisionZ = a->posZ + a->sizeZ / 2.0 >= b->posZ && b->posZ + b->sizeZ / 2.0 >= a->posZ;
	*/
	
	GLfloat dx = abs(a->posX - b->posX);
	dx *= dx;
	GLfloat dy = abs(a->posY - b->posY);
	dy *= dy;
	GLfloat dz = abs(a->posZ - b->posZ);
	dz *= dz;
	//bool col = sqrt(dx + dz + dy) <= ((a->sizeX+b->sizeX)/2.0)+ ((a->sizeY + b->sizeY ) / 2.0) + ((a->sizeZ + b->sizeZ ) / 2.0);
	GLfloat aRadius = (a->sizeX*a->sizeX) + (a->sizeY*a->sizeY) + (a->sizeZ*a->sizeZ);
	GLfloat bRadius = (b->sizeX*b->sizeX) + (b->sizeY*b->sizeY) + (b->sizeZ*b->sizeZ);

	bool col = sqrt(dx + dz + dy) <= sqrt( aRadius+bRadius);

	
	//bool collisionX = abs(a->posX - b->posX) <= ((a->sizeX ) + (b->sizeX ));
	//bool collisionY = abs(a->posY - b->posY) <= ((a->sizeY ) + (b->sizeY ));
	//bool collisionZ = abs(a->posZ - b->posZ) <= ((a->sizeZ ) + (b->sizeZ ));
	
	
	return col;
	//return collisionX && collisionY;// &collisionZ;
}

gameController::~gameController()
{
	Cleanup();
}
