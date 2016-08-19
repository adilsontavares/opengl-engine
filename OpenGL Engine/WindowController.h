#pragma once

#include <GL/glew.h>

class WindowController
{
public:

	WindowController();
	~WindowController();

	virtual void windowDidLoad();
	virtual void onWindowResize(int width, int height);

	virtual void update(float dt);
	virtual void render();
};

