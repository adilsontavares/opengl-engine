#pragma once

#include <GL/glew.h>

class ApplicationController
{
public:

	ApplicationController();
	~ApplicationController();

	virtual void onApplicationStart();
	virtual void onApplicationEnd();
	virtual void onWindowResize(int width, int height);
	virtual void update(float dt);
	virtual void render();

	void setBackgroundColor(GLfloat r, GLfloat g, GLfloat b);
	void setBackgroundColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
};

