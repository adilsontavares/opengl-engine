#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec2 vertexUV;

out vec2 uv;
out vec3 fragmentColor;

void main()
{
	gl_Position.xyz = pos;
	gl_Position.w = 1;

	fragmentColor = vertexColor;
	uv = vertexUV;
}