#include "ShaderProgram.h"
#include "Log.h"
#include <vector>

using namespace std;

ShaderProgram::ShaderProgram(Shader * vertex, Shader * fragment)
{
	Log::assert(vertex && fragment, "Could not create a shader program because one of the shaders is null.");
	Log::assert(vertex->ready() && fragment->ready(), "Could not create a shader program because one of the shaders is not ready.");

	_id = -1;
	_ok = false;
	_vertex = vertex;
	_fragment = fragment;

	link();
}

void ShaderProgram::link()
{
	_id = glCreateProgram();

	glAttachShader(_id, _vertex->getId());
	glAttachShader(_id, _fragment->getId());

	glLinkProgram(_id);

	GLint result;
	glGetProgramiv(_id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		GLint logLength;
		glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &logLength);

		vector<char> log(logLength);
		glGetProgramInfoLog(_id, logLength, 0, &log[0]);

		Log::error("Could not link shader program: %s", &log[0]);

		_id = -1;
		_ok = false;
	}
	else
	{
		_ok = true;
	}
}

ShaderProgram::~ShaderProgram()
{
}

void ShaderProgram::use()
{
	Log::assert(ok(), "Could not use a shader program that was not initialized successfully.");
	glUseProgram(_id);
}

bool ShaderProgram::ok()
{
	return (bool)_ok;
}
