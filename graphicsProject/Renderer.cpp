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
	GameController->update();
}

void Renderer::HandleKeyboardInput(int key)
{
	GameController->HandleKeyboardInput(key);
}
void Renderer::HandleMouseInput(int key) 
{
	GameController->HandleMouseInput(key);
}
Renderer::~Renderer()
{
	GameController->Cleanup();
}
