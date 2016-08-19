#include "Application.h"
#include "GameController.h"

#include <iostream>
#include <GLFW\glfw3.h>

using namespace std;

int main(int argc, char *args[])
{
	glutInit(&argc, args);
	glfwInit();

	Application *app = Application::mainApp();
	app->useController(new GameController());
	return app->mainLoop();
}