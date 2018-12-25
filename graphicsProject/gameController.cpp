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

void gameController::finishedLevel()
{
	if (Enemies.size() == 0 && level == 1)
	{
		level++;
		fChicken = new FlashChicken("flasChicken.png");
		Enemies.push_back(fChicken);
	}
	else if (Enemies.size() == 0 && level == 2)
	{
		level++;
		fChicken = new FlashChicken("flasChicken.png");
		Enemies.push_back(fChicken);
	}
	else if (Enemies.size() == 0 && level == 3)
	{
		level++;
		printf("WINNER WINNER CHICKEN DINNER");
	}
}



void gameController::init()
{
	level = 1;
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	programID = LoadShaders("VertexShader.vertexshader", "FragmentShader.fragmentshader");
	glUseProgram(programID);
	ProjectionMatrixID = glGetUniformLocation(programID, "ProjectionMatrix");
	ViewMatrixID = glGetUniformLocation(programID, "ViewMatrix");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	for (float i = -0.8f; i <= 0.8f; i += 0.8f)
	{
		normalChicken = new NormalChicken("chicken2.png");
		normalChicken->translateTheObject(i, 0.42, -1.0);
		Enemies.push_back(normalChicken);

	}
	
	//bossChicken = new BossChicken ("Bosschicken2.png");
	//bossChicken->translateVector = vec3(0.5f, 0.0f, 0.0f);
	//bossChicken->scaleVector = vec3(3.0f, 3.0f, 1.0f);
	ship = new Ship("ship.png");
	c = new Cube("white-egg.png");
	eggs.push_back(c);
	spaceFloor = new SpaceFloor("space.png");
	fChicken = new FlashChicken("flasChicken.png");
}

void gameController::draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	cameraVP();
	spaceFloor->draw(programID);
	
	if (ship->Died == false) {
		ship->draw(programID);
		//drawChickens();
		drawEggs();
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
void gameController::drawEggs()
{
	for (int i = 0; i < eggs.size(); i++)
	{
		eggs[i]->draw(programID);
	}
}
void gameController::drawChickens()
{
	for (int i = 0; i < Enemies.size(); i++) {
		Enemies[i]->draw(programID);
	}
}
void gameController::update()
{
	if (camera.firstPesron)
		camera.UpdateFirsrtPersonViewMatrix(vec3(ship->posX, ship->posY, ship->posZ));
	if (ship->Died == false) {
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
	for (int i = 0; i < Enemies.size(); i++)
	{
		Enemies[i]->Update(deltaTime);
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
	CollisionBetweenShipAndEgg();
	CollisionBetweenBulletAndEgg();
	CollisionBetweenBulletAndChickens();
}
void gameController::CollisionBetweenShipAndEgg()
{
	for (int i = 0; i < eggs.size() ; i++)
	{
		if (thereIsCollision(ship, eggs[i]))
		{
			cout << "LOOSE";
			//lose();
		}
	}
}
void gameController::CollisionBetweenBulletAndEgg()
{
	for (int i = 0; i < ShipBullets.size(); i++)
	{
		for (int j = 0; j < eggs.size(); j++)
		{
			if (thereIsCollision(ShipBullets[i], eggs[j]) )
			{
				ShipBullets[i]->Died = true;
				ShipBullets[i] = ShipBullets[ShipBullets.size() - 1];
				ShipBullets.pop_back();
				i--;
				eggs[j]->Died = true;
				eggs[j] = eggs[eggs.size() - 1];
				eggs.pop_back();
				break;
			}
		}

		//checkcollisionwithboss();
	}
}
void gameController::CollisionBetweenBulletAndChickens() 
{
	for (int i = 0; i < ShipBullets.size(); i++) 
	{
		if (CheckCollisionWithNormal(i))
		{
			ShipBullets[i]->Died = true;
			ShipBullets[i] = ShipBullets[ShipBullets.size() - 1];
			ShipBullets.pop_back();
			i--;
		}

		//checkcollisionwithboss();
	}
}
bool gameController::CheckCollisionWithNormal(int index) 
{
	for (int i = 0; i < Enemies.size(); i++)
	{
		if (thereIsCollision(ShipBullets[index], Enemies[i]))
		{
			Enemies[i]->health--;
			printf(" Current Health %d \n", Enemies[i]->health);
			if (Enemies[i]->health == 0) {
				if (Enemies[i]->anotherLife == true)
				{
					if (typeid(*Enemies[i]) == typeid(NormalChicken))
					{
						GLfloat tmpPosX = Enemies[i]->posX;
						GLfloat tmpPosY = Enemies[i]->posY;
						GLfloat tmpPosZ = Enemies[i]->posZ;
						GLfloat tmpSizeX = Enemies[i]->sizeX;
						rebirthNormalChicken(tmpPosX, tmpPosY, tmpPosZ, tmpSizeX);		
					}
				}
				printf("Cluck Cluck \n");
				Enemies[i]->Died = true;
				Enemies[i] = Enemies[Enemies.size() - 1];
				Enemies.pop_back();
				finishedLevel();
			}
			return true;
		}

	}
	return false;
}
void gameController::rebirthNormalChicken(GLfloat tmpPosX, GLfloat tmpPosY, GLfloat tmpPosZ, GLfloat tmpSizeX)
{
	normalChicken = new NormalChicken("chicken2.png");
	normalChicken->scaleTheObject(0.5, 0.5, 0.5);
	normalChicken->translateTheObject(tmpPosX + tmpSizeX, tmpPosY, tmpPosZ);
	normalChicken->anotherLife = false;
	Enemies.push_back(normalChicken);

	normalChicken = new NormalChicken("chicken2.png");
	normalChicken->translateTheObject(tmpPosX - tmpSizeX, tmpPosY, tmpPosZ);
	normalChicken->scaleTheObject(0.5, 0.5, 0.5);
	normalChicken->anotherLife = false;
	Enemies.push_back(normalChicken);
}
void gameController::CollisionBetweenShipAndChickens()
{
	for (int i = 0; i < Enemies.size(); i++)
	{

		if (thereIsCollision(ship, Enemies[i]))
		{
			Enemies[i]->Died = true;
			Enemies[i] = Enemies[Enemies.size() - 1];
			Enemies.pop_back();
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
		if (camera.firstPesron)
			camera.UpdateFirsrtPersonViewMatrix(vec3(ship->posX, ship->posY, ship->posZ));
		else
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
	GLfloat dx = abs(a->posX - b->posX);
	dx *= dx;
	GLfloat dy = abs(a->posY - b->posY);
	dy *= dy;
	GLfloat dz = abs(a->posZ - b->posZ);
	dz *= dz;
	
	GLfloat aRadius = (a->sizeX*a->sizeX) + (a->sizeY*a->sizeY) + (a->sizeZ*a->sizeZ);
	GLfloat bRadius = (b->sizeX*b->sizeX) + (b->sizeY*b->sizeY) + (b->sizeZ*b->sizeZ);
	

	bool col = sqrt(dx + dz + dy) <= sqrt( aRadius+bRadius);
	
	

	
	
	/*bool collisionX = abs(a->posX - b->posX) <= ((a->sizeX ) + (b->sizeX ));
	bool collisionY = abs(a->posY - b->posY) <= ((a->sizeY ) + (b->sizeY ));
	bool collisionZ = abs(a->posZ - b->posZ) <= ((a->sizeZ ) + (b->sizeZ ));
	*/

	return col;
	//return collisionX && collisionY&&collisionZ;
}

gameController::~gameController()
{
	Cleanup();
}
