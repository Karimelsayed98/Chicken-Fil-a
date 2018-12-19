#pragma once
#include <gl/glew.h>
#include<vector>
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
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "ShipBullet.h"
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
	vector <NormalChicken * > normalChickens;
	vector <ShipBullet * > ShipBullets;
	int level;
	GLfloat pastFrame;
	GLfloat deltaTime;
	void finishedLevel();
	//vector <bossChicken> bosses;
	//vector <bullet> bullets;
	//vector <egg> eggs;
public:
	void init();
	void draw();
	void drawBullets();
	void drawChickens();
	void update();
	void updateShoots();
	void updateChicken();
	void updateShip();
	void checkForAllCollisions();
	void CollisionBetweenBulletAndChickens();
	void CollisionBetweenShipAndChickens();
	bool CheckCollisionWithNormal(int);
	void HandleKeyboardInput(int key);
	void HandleMouseInput(int key);
	void cameraVP();

	bool thereIsCollision(Object * a, Object * b);

	void Cleanup();
	gameController();
	~gameController();
};

