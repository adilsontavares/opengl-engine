#pragma once

#include <GL/glew.h>

class Texture
{
private:

	GLuint _width;
	GLuint _height;
	GLbyte *_data;

public:

	Texture(int width, int height, GLbyte *data);

	int getWidth();
	int getHeight();

	bool validatePixel(GLuint x, GLuint y);

	bool getPixelAt(GLuint x, GLuint y, GLbyte *r, GLbyte *g, GLbyte *b);
	bool getPixelAt(GLuint x, GLuint y, GLbyte *bytes);

	GLbyte *getData();
};

