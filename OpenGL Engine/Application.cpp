#include "Application.h"
#include "Log.h"
#include "ShaderManager.h"
#include "ShaderProgram.h"
#include <GL/glew.h>
#include <GLFW\glfw3.h>

Application::Application()
{
	Log::log("Initializing GLFW...");
	Log::assert(glfwInit() != 0, "Could not initalize GLFW library");

	_mainWindow = 0;
}

Application::~Application()
{
	delete _mainWindow;
}

Application * Application::mainApp()
{
	static Application *app;
	if (!app)
		app = new Application();
	return app;
}

int Application::mainLoop()
{
	Log::log("Application started!");

	_mainWindow->mainLoop();

	return 0;
}

void Application::initWindow(const char * title, int width, int height, WindowController *controller)
{
	Log::log("Creating main window...");
	_mainWindow = new Window(title, width, height, controller);

	Log::log("Initializing GLEW...");
	GLint err = glewInit();
	if (err != GLEW_OK)
		Log::fatalError("Could not initialize GLEW: %s", glewGetErrorString(err));

	_mainWindow->start();
}
