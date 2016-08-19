#include "ShaderManager.h"
#include "Log.h"
#include "File.h"

using namespace std;

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

ShaderManager * ShaderManager::instance()
{
	static ShaderManager *instance;
	if (!instance)
		instance = new ShaderManager();
	return instance;
}

Shader * ShaderManager::loadFromFile(const std::string & name, ShaderType type, const std::string & path)
{
	string content;
	if (!File::readAllContent(path, &content))
	{
		Log::error("Could not load shader '%s' from file '%s': File does not exists or could not be opened.", name.c_str(), path.c_str());
		return 0;
	}

	return loadFromString(name, type, content);
}

Shader * ShaderManager::loadFromString(const std::string & name, ShaderType type, const std::string & content)
{
	if (findShader(name))
	{
		Log::error("Could not load shader with name '%s' because another shader with same name is already loaded.", name.c_str());
		return 0;
	}

	Shader *shader = new Shader(name, type);
	shader->loadFromString(content);

	if (shader->ready())
	{
		_shaders[name] = shader;
		return shader;
	}

	delete shader;

	Log::error("Shader '%s' could not be stored because it failed loading.", name.c_str());

	return 0;
}

Shader *ShaderManager::findShader(const string& name)
{
	auto it = _shaders.find(name);
	if (it == _shaders.end())
		return 0;
	return it->second;
}
