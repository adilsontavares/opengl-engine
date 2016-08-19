#pragma once
	
#include <iostream>
#include "ShaderProgram.h"
#include "ApplicationController.h"

class Application
{
private:

	static void init();
	static void update();
	static void loop();
	static void display();
	static void reshape(int width, int height);

	static ShaderProgram *_defaultProgram;
	static ApplicationController *_controller;

	Application(const std::string& windowTitle);
	~Application();

	static void preloadShaders();

public:

	static Application *mainApp();

	void useController(ApplicationController *controller);
	int mainLoop();
};

