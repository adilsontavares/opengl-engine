#include "TextureLoader.h"
#include "Log.h"
#include <vector>
#include <lodepng.h>

using namespace std;

TextureLoader::TextureLoader()
{
}

Texture * TextureLoader::loadPNG(const std::string file)
{
	vector<unsigned char> png;
	vector<unsigned char> pixels;
	unsigned int width = 0, height = 0;
	
	if (lodepng::load_file(png, file) == 0)
	{
		unsigned error = lodepng::decode(pixels, width, height, png);
		if (error != 0)
		{
			Log::error("Could not load PNG image at path %s: %s", file.c_str(), lodepng_error_text(error));
			return 0;
		}
	}

	GLbyte *bytes = new GLbyte[pixels.size()];
	for (int i = 0; i < pixels.size(); ++i)
		bytes[i] = pixels[i];

	return new Texture(width, height, bytes);
}