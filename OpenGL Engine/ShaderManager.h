#pragma once

#include <iostream>
#include <map>
#include "Shader.h"

class ShaderManager
{
private:

	ShaderManager();
	~ShaderManager();

		std::map<std::string, Shader*> _shaders;

public:

	static ShaderManager *instance();

	Shader *loadFromFile(const std::string& name, ShaderType type, const std::string& path);
	Shader *loadFromString(const std::string& name, ShaderType type, const std::string& content);

	Shader *findShader(const std::string &name);
};

