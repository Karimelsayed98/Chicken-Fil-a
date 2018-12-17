#include "gameController.h"



void gameController::Cleanup()
{
	glDeleteProgram(programID);
}

gameController::gameController()
{
	pastFrame = glfwGetTime();
	deltaTime = 0;
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

	
	for (float i = -1.0f; i <= 1.0f; i += 0.6f)
	{
		normalChicken = new NormalChicken("chicken2.png");
		normalChicken->translateTheObject(i, 0.42, -1.0);
		normalChickens.push_back(normalChicken);

	}
	
	normalChicken = new NormalChicken ("chicken2.png");
	normalChickens.push_back(normalChicken);
	//bossChicken = new BossChicken ("Bosschicken2.png");
	//bossChicken->translateVector = vec3(0.5f, 0.0f, 0.0f);
	//bossChicken->scaleVector = vec3(3.0f, 3.0f, 1.0f);
	ship = new Ship("ship.png");
	c = new Cube("Bosschicken2.png");
	spaceFloor = new SpaceFloor("space.png");
}

void gameController::draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	cameraVP();

	spaceFloor->draw(programID);
	if (ship->Died == false) {
		ship->draw(programID);
		drawChickens();
		drawBullets();
	}
	
	//drawEggs();

	//bossChicken->draw(programID);
	//c->draw(programID);
}
void gameController::drawBullets()
{
	for (int i = 0; i < ShipBullets.size(); i++)
	{
		ShipBullets[i]->draw(programID);
	}
}
void gameController::drawChickens()
{
	for (int i = 0; i < normalChickens.size(); i++)
	{
		normalChickens[i]->draw(programID);
	}
}
void gameController::update()
{
	if (ship->Died == false ) {
		GLfloat temp = glfwGetTime();
		deltaTime = temp - pastFrame;
		pastFrame = temp;
		updateShip();
		updateChicken();
		updateShoots();
		checkForAllCollisions();
		
	}

}
void gameController::updateShoots()
{
	for (int i = 0; i < ShipBullets.size(); i++)
	{
		if (ShipBullets[i]->posY > 0.55f)
		{
			ShipBullets[i]->Died = true;
			ShipBullets[i] = ShipBullets[ShipBullets.size() - 1];
			ShipBullets.pop_back();
			i--;
		}
		else
			ShipBullets[i]->Update(deltaTime);
	}
}
void gameController::updateChicken()
{
	for (int i = 0; i < normalChickens.size(); i++)
	{
		normalChickens[i]->Update(deltaTime);
	}
}
void gameController::updateShip()
{
	if (ship->nextShoot > 0)
		ship->nextShoot -= deltaTime;

}

void gameController::checkForAllCollisions()
{
	CollisionBetweenShipAndChickens();
	//CollisionBetweenShipAndEgg();
	CollisionBetweenBulletAndChickens();
	
}
void gameController::CollisionBetweenBulletAndChickens() 
{
	for (int i = 0; i < ShipBullets.size(); i++) 
	{
		for (int j = 0; j < normalChickens.size(); j++) 
		{
			if (thereIsCollision(ShipBullets[i], normalChickens[j])) 
			{
				normalChickens[j]->health--;
				printf(" Current Health %d \n", normalChickens[j]->health);
				if (normalChickens[j]->health == 0) {
					printf("Cluck Cluck \n");
					normalChickens[j]->Died = true;
					normalChickens[j] = normalChickens[normalChickens.size() - 1];
					normalChickens.pop_back();
				}
				ShipBullets[i]->Died = true;
				ShipBullets[i] = ShipBullets[ShipBullets.size() - 1];
				ShipBullets.pop_back();
				i--;
				if (normalChickens.size()== 0)
					printf("WINNER WINNER CHICKEN DINNER");
				break;
			}
		}
	}
}
void gameController::CollisionBetweenShipAndChickens()
{
	for (int i = 0; i < normalChickens.size(); i++)
	{

		if (thereIsCollision(ship, normalChickens[i]))
		{
			normalChickens[i]->Died = true;
			normalChickens[i] = normalChickens[normalChickens.size() - 1];
			normalChickens.pop_back();
			ship->Died = true;
			printf("CHICKEN FILA LOST :(( \n");
			break;
		}
	}
}


void gameController::HandleKeyboardInput(int key)
{
	if (key == -1)
		return;
	
	if (ship->HandleKeyboardInput(key , deltaTime))
	{
		return;
	}
	else if (camera.HandleKeyboardInput(key))
	{
		camera.UpdateViewMatrix();
		return;
	}
	//continue the remaining movements.
	
}
void gameController::HandleMouseInput(int key) 
{
	ShipBullet* tempBullet;
	switch (key)
	{
	case GLFW_KEY_SPACE:
		if (ship->nextShoot <= 0)
		{
			ship->nextShoot = ship->timeBetweenShoots;
		tempBullet = new ShipBullet("Ship_Bullet.png");
		tempBullet->translateTheObject(ship->posX, (ship->posY + ship->sizeY), (ship->posZ + ship->sizeZ));
		ShipBullets.push_back(tempBullet);
		}
		break;
	default:
		break;
	}
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
	

	
	/*
	bool collisionX = abs(a->posX - b->posX) <= ((a->sizeX ) + (b->sizeX ));
	bool collisionY = abs(a->posY - b->posY) <= ((a->sizeY ) + (b->sizeY ));
	//bool collisionZ = abs(a->posZ - b->posZ) <= ((a->sizeZ ) + (b->sizeZ ));
	*/
	
	
	
	return col;
	//return collisionX && collisionY;// &&collisionZ;
}

gameController::~gameController()
{
	Cleanup();
}
