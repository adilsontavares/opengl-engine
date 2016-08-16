#pragma once

#include "Shader.h"

class ShaderProgram
{
private:

	GLboolean _ok;
	GLuint _id;
	Shader *_vertex;
	Shader *_fragment;

	void link();

public:

	ShaderProgram(Shader * vertex, Shader * fragment);
	~ShaderProgram();

	void use();
	bool ok();
};

