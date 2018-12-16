#pragma once
#include <gl/glew.h>
#include<vector>
#include "shader.hpp"
#include "Shader.h"
#include "texture.h"
#include "Vertex.h"
#include "FPCamera.h"
#include "Rect.h"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "gameController.h"
class Renderer
{
	gameController * GameController = new gameController();
public:
	Renderer();

	void Initialize();
	void Draw();
	void cameraVP();
	void HandleKeyboardInput(int key);
	void HandleMouseInput(int key);
	void Update();
	~Renderer();
};

