#include "ApplicationController.h"

ApplicationController::ApplicationController()
{
}

ApplicationController::~ApplicationController()
{
}

void ApplicationController::onApplicationStart()
{
}

void ApplicationController::onApplicationEnd()
{
}

void ApplicationController::onWindowResize(int width, int height)
{
}

void ApplicationController::update(float dt)
{
}

void ApplicationController::render()
{
}

void ApplicationController::setBackgroundColor(GLfloat r, GLfloat g, GLfloat b)
{
	setBackgroundColor(r, g, b, 1);
}

void ApplicationController::setBackgroundColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}
