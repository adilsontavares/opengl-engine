#pragma once
	
#include <iostream>
#include "ShaderProgram.h"
#include "Window.h"
#include "WindowController.h"

class Application
{
private:

	Window *_mainWindow;

	Application();
	~Application();

public:

	static Application *mainApp();

	int mainLoop();

	void initWindow(const char *title, int width, int height, WindowController *controller);
};