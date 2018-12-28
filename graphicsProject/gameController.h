#pragma once
#include <gl/glew.h>
#include<vector>
#include <windows.h>
#include<mmsystem.h>
#include "shader.hpp"
#include "Shader.h"
#include "texture.h"
#include "Vertex.h"
#include "FPCamera.h"
#include "NormalChicken.h"
#include "BossChicken.h"
#include "Cube.h"
#include "SpaceFloor.h"
#include "Ship.h"
#include "FlashChicken.h"
#include "Egg.h"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "ShipBullet.h"
#include "Chickens.h"
class gameController
{
	GLuint programID;
	GLuint mvpMatrixID;
	GLuint ProjectionMatrixID;
	glm::mat4 ProjectionMatrix;
	GLuint ViewMatrixID;
	glm::mat4 ViewMatrix;
	FPCamera camera;
	NormalChicken* normalChicken;
	FlashChicken* fChicken;
	BossChicken* bossChicken;
	Cube* c;
	SpaceFloor * spaceFloor;
	Ship * ship;
	vector <Chickens* > Enemies;
	vector <ShipBullet * > ShipBullets;
	vector <Egg *> eggs;
	int level;
	GLfloat pastFrame;
	GLfloat deltaTime;
	void finishedLevel();
	void rebirthNormalChicken(GLfloat, GLfloat, GLfloat, GLfloat);
public:
	void init();
	void draw();
	void drawBullets();
	void drawEggs();
	void drawChickens();
	void update();
	void updateShoots();
	void updateChicken();
	void updateBigChicken();
	void updateShip();
	void checkForAllCollisions();
	void CollisionBetweenShipAndEgg();
	void CollisionBetweenBulletAndEgg();
	void CollisionBetweenBulletAndChickens();
	void CollisionBetweenShipAndChickens();
	bool CheckCollisionWithNormal(int);
	void HandleKeyboardInput(int key);
	void HandleMouseInput(int key);
	void ChickenShoot();
	void UpdateEggs();
	void cameraVP();

	bool thereIsCollision(Object * a, Object * b);

	void Cleanup();
	gameController();
	~gameController();
};

