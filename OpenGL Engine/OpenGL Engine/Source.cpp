#include <iostream>

#include "Application.h"
#include "ApplicationController.h"

using namespace std;

int main(int argc, char *args[])
{
	glutInit(&argc, args);

	Application *app = Application::mainApp();
	app->useController(new ApplicationController());
	return app->mainLoop();
}