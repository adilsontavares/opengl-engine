#include "Application.h"
#include "GameController.h"
#include "Window.h"

#include <iostream>

using namespace std;

int main(int argc, char *args[])
{
	Application *app = Application::mainApp();
	app->initWindow("Hello, OpenGL!", 800, 600, new GameController());
	return app->mainLoop();

	return 0;
};