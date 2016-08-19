#include "Texture.h"
#include "Log.h"

Texture::Texture(int width, int height, GLbyte * data)
{
	_width = width;
	_height = height;
	_data = data;
}

int Texture::getWidth()
{
	return _width;
}

int Texture::getHeight()
{
	return _height;
}

bool Texture::validatePixel(GLuint x, GLuint y)
{
	return x >= 0 && x < _width && y >= 0 && y < _height;
}

bool Texture::getPixelAt(GLuint x, GLuint y, GLbyte * r, GLbyte * g, GLbyte * b)
{
	if (!validatePixel(x, y))
		return false;

	GLuint pos = (x + y * _width) * 4;
	*r = _data[pos];
	*g = _data[pos + 1];
	*b = _data[pos + 2];
}

bool Texture::getPixelAt(GLuint x, GLuint y, GLbyte * bytes)
{
	return getPixelAt(x, y, bytes, bytes + 1, bytes + 2);
}

GLbyte * Texture::getData()
{
	return _data;
}
