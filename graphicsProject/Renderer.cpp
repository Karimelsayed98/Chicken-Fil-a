#include "Renderer.h"



Renderer::Renderer()
{
}

void Renderer::Initialize()
{
	GameController->init();
}

void Renderer::Draw()
{
	GameController->draw();
}

void Renderer::cameraVP()
{
	GameController->cameraVP();
}


void Renderer::Update()
{
	GameController->detectCollisions();
	GameController->update();
}

void Renderer::HandleKeyboardInput(int key)
{
	GameController->HandleKeyboardInput(key);
}
Renderer::~Renderer()
{
	GameController->Cleanup();
}
