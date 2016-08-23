#pragma once

#include <iostream>
#include <GL/glew.h>

enum ShaderType
{
	_kShaderTypeStart,
	
	kShaderTypeVertex,
	kShaderTypeFragment,

	_kShaderTypeEnd
};

class Shader
{
private:

	GLboolean _ready;
	GLuint _id;
	std::string _name;
	ShaderType _type;

public:
	
	// Constructors

	Shader(const std::string& name, ShaderType type);

	// Loaders

	bool loadFromString(const std::string & content);

	// Getters

	bool ready();
	int getId();
	std::string getName();

	// Destructors

	~Shader();
};

