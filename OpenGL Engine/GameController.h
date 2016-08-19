#pragma once

#include "ApplicationController.h"
#include "ShaderProgram.h"

class GameController : public ApplicationController
{
private:

	GLuint _vao;
	GLuint _vb[3];
	ShaderProgram *_program;

public:
	GameController();

	virtual void update(float dt);
	virtual void render();
};

