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
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

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
	BossChicken* bossChicken;
	Cube* c;
	SpaceFloor * spaceFloor;
	Ship * ship;
	vector <NormalChicken * > normalChickens;
	//vector <bossChicken> bosses;
	//vector <bullet> bullets;
	//vector <egg> eggs;
public:
	void init();
	void draw();
	void update();
	void detectCollisions();
	void HandleKeyboardInput(int key);
	void cameraVP();

	bool thereIsCollision(Object * a, Object * b);

	void Cleanup();
	gameController();
	~gameController();
};

