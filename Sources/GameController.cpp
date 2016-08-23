#include "GameController.h"
#include "ShaderManager.h"
#include "TextureLoader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

GameController::GameController()
{
}

void GameController::windowDidLoad()
{
	_texture = TextureLoader::loadPNG("/Users/adilsontavares/Desktop/Hello.png");
	_rotation = 0;

	glEnable(GL_TEXTURE_2D);

	glGenTextures(1, &_textureId);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _texture->getWidth(), _texture->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, _texture->getData());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

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

}

void GameController::update(float dt)
{
	_rotation += glm::radians(360.0) * dt;
}

void GameController::render()
{
	_program->use();

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, _vb[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, _vb[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, _vb[2]);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	GLuint tex = glGetUniformLocation(_program->getId(), "mainTexture");
	glUniform1i(tex, 0);

	GLuint mvploc = glGetUniformLocation(_program->getId(), "MVP");
	glm::mat4 mvp = glm::mat4(1.0f);
	mvp = glm::scale(mvp, glm::vec3(0.6, 0.6, 0.6));
	mvp = glm::rotate(mvp, _rotation, glm::vec3(0, 1, 0));
	
	glUniformMatrix4fv(mvploc, 1, GL_FALSE, &mvp[0][0]);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}
