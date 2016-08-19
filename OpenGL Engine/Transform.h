#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Transform
{
private:

	glm::mat4 _matrix;

public:

	Transform();

	void loadIdentity();

	void translate(GLfloat x, GLfloat y, GLfloat z);
	void translateX(GLfloat delta);
	void translateY(GLfloat delta);
	void translateZ(GLfloat delta);

	void rotate(GLfloat x, GLfloat y, GLfloat z);
	void rotateX(GLfloat delta);
	void rotateY(GLfloat delta);
	void rotateZ(GLfloat delta);

	void scale(GLfloat x, GLfloat y, GLfloat z);
	void scaleX(GLfloat delta);
	void scaleY(GLfloat delta);
	void scaleZ(GLfloat delta);
};

