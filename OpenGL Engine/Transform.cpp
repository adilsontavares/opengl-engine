#include "Transform.h"

Transform::Transform()
{
	loadIdentity();
}

void Transform::loadIdentity()
{
	_matrix = glm::mat4(1.0);
}

void Transform::translate(GLfloat x, GLfloat y, GLfloat z)
{
}

void Transform::translateX(GLfloat delta)
{
}

void Transform::translateY(GLfloat delta)
{
}

void Transform::translateZ(GLfloat delta)
{
}

void Transform::rotate(GLfloat x, GLfloat y, GLfloat z)
{
}

void Transform::rotateX(GLfloat delta)
{
}

void Transform::rotateY(GLfloat delta)
{
}

void Transform::rotateZ(GLfloat delta)
{
}

void Transform::scale(GLfloat x, GLfloat y, GLfloat z)
{
}

void Transform::scaleX(GLfloat delta)
{
}

void Transform::scaleY(GLfloat delta)
{
}

void Transform::scaleZ(GLfloat delta)
{
}
