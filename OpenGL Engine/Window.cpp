#include "Window.h"
#include "ShaderManager.h"
#include "Log.h"
#include <GLFW\glfw3.h>

static Window *MainWindow = 0;

void onWindowResize(GLFWwindow *window, int width, int height)
{
	MainWindow->onResize(width, height);
}

Window::Window(const char * title, int width, int height, WindowController * controller)
{
	MainWindow = this;

	_window = glfwCreateWindow(width, height, title, 0, 0);
	Log::assert(_window != 0, "Could not create window %dx%d with title '%s'", width, height, title);

	_controller = controller;
	glfwMakeContextCurrent(_window);
}

void Window::start()
{
	init();

	Log::log("Loading window controller...");
	_controller->windowDidLoad();
}

void Window::init()
{
	Log::log("Preloading shaders...");

	Shader *vert = ShaderManager::instance()->loadFromFile("Vertex", kShaderTypeVertex, "simple.vs");
	Shader *frag = ShaderManager::instance()->loadFromFile("Fragment", kShaderTypeFragment, "simple.fs");
	_defaultProgram = new ShaderProgram(vert, frag);

	glfwSetFramebufferSizeCallback(_window, onWindowResize);
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(_window) != 0;
}

void Window::setBackgroundColor(GLfloat r, GLfloat g, GLfloat b)
{
	setBackgroundColor(r, g, b, 1);
}

void Window::setBackgroundColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}

void Window::update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	_defaultProgram->use();

	double time = glfwGetTime();

	_controller->update((float)(time - _time));
	_controller->render();

	_time = time;

	glfwSwapBuffers(_window);
	glfwPollEvents();
}

void Window::onResize(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1, 1, -1, 1, -1, 1);

	Log::log("Window resized to %dx%d", width, height);

	_controller->onWindowResize(width, height);

	update();
}

Window::~Window()
{
}

void Window::setController(WindowController * controller)
{
	Log::assert(controller != 0, "Window controller must not be null.");
	_controller = controller;
}

void Window::mainLoop()
{
	while (!shouldClose())
		update();
}
