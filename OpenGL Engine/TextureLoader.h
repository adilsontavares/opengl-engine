#pragma once

#include "Texture.h"
#include <GL/glew.h>
#include <iostream>

class TextureLoader
{
private:
	TextureLoader();

public:

	static Texture *loadPNG(const std::string file);
};

