#include <iostream>

#include "Application.h"
#include "GameController.h"

using namespace std;

int main(int argc, char *args[])
{
	glutInit(&argc, args);

	Application *app = Application::mainApp();
	app->useController(new GameController());
	return app->mainLoop();
}