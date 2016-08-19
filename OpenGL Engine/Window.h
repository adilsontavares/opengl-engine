#pragma once

#include "WindowController.h"
#include "ShaderProgram.h"
#include <GLFW\glfw3.h>

class Window
{
private:
	
	GLFWwindow *_window;
	WindowController *_controller;
	ShaderProgram *_defaultProgram;
	double _time;

	void init();
	void update();

public:
	
	Window(const char *title, int width, int height, WindowController *controller);
	~Window();

	void onResize(int width, int height);

	void setController(WindowController *controller);
	void mainLoop();

	bool shouldClose();

	void setBackgroundColor(GLfloat r, GLfloat g, GLfloat b);
	void setBackgroundColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

	void start();
};