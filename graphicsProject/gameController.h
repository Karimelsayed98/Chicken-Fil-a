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
	//ship * Ship;
	//vector <normalChicken> chickens;
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

	void Cleanup();
	gameController();
	~gameController();
};

