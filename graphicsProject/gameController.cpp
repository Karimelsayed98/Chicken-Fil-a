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
	//normalChicken = new NormalChicken ("chicken2.png");
	//bossChicken = new BossChicken ("Bosschicken2.png");
	c = new Cube("Bosschicken2.png");
	spaceFloor = new SpaceFloor("space.png");
}

void gameController::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	cameraVP();
	spaceFloor->draw(programID);
	//normalChicken->draw(programID);
	//bossChicken->draw(programID);
	//bossChicken->translateVector = vec3(0.5f, 0.0f, 0.0f);
	//bossChicken->scaleVector = vec3(3.0f, 3.0f, 1.0f);
	c->draw(programID);
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
	printf("key : %d \n", key);
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

gameController::~gameController()
{
	Cleanup();
}
