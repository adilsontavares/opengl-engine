#include "GameController.h"
#include "ShaderManager.h"

GameController::GameController()
{
	Shader *vert = ShaderManager::instance()->findShader("Vertex");
	Shader *frag = ShaderManager::instance()->findShader("Fragment");

	_program = new ShaderProgram(vert, frag);

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	const GLfloat data[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f
	};

	const GLfloat colors[] =
	{
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};

	const GLfloat uvs[] = 
	{
		0, 0,
		1, 0,
		0.5f, 0
	};

	glGenBuffers(3, _vb);

	glBindBuffer(GL_ARRAY_BUFFER, _vb[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, _vb[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, _vb[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), colors, GL_STATIC_DRAW);

	setBackgroundColor(1, 1, 1);
}

void GameController::update(float dt)
{
}

void GameController::render()
{
	_program->use();

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, _vb[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, _vb[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}
