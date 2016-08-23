#include "Shader.h"
#include "Log.h"
#include "File.h"
#include <vector>

using namespace std;

Shader::Shader(const std::string & name, ShaderType type)
{
	Log::assert(type > _kShaderTypeStart && type < _kShaderTypeEnd, "Invalid shader type: %d", type);

	_ready = false;
	_id = -1;
	_name = name;
	_type = type;
}

bool Shader::loadFromString(const std::string & content)
{
	GLenum shaderType = 0;
	switch (_type)
	{
	case kShaderTypeVertex:
		shaderType = GL_VERTEX_SHADER;
		break;

	case kShaderTypeFragment:
		shaderType = GL_FRAGMENT_SHADER;
		break;
            
    default:
        break;
	}

	_id = glCreateShader(shaderType);

	const GLchar *source[] = { content.c_str() };
	const GLint lengths[] = { static_cast<GLint>(content.size()) };
	glShaderSource(_id, 1, source, lengths);

	glCompileShader(_id);

	GLint result;
	glGetShaderiv(_id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		GLint logLength;
		glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &logLength);

		vector<char> log(logLength);
		glGetShaderInfoLog(_id, logLength, 0, &log[0]);

		Log::error("Could not compile shader '%s'", _name.c_str());
		Log::error(&log[0]);

		_id = -1;
		_ready = false;

		return false;
	}

	_ready = true;

	return true;
}

bool Shader::ready()
{
	return _ready;
}

int Shader::getId()
{
	return _id;
}

std::string Shader::getName()
{
	return _name;
}

Shader::~Shader()
{
}
