#include "Application.h"
#include "Log.h"
#include "ShaderManager.h"
#include "ShaderProgram.h"
#include <GL/glew.h>
#include <GL/freeglut.h>

ShaderProgram *Application::_defaultProgram = 0;
ApplicationController *Application::_controller = 0;

Application::Application(const std::string & windowTitle)
{
	const int winWidth = 800;
	const int winHeight = 600;

	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - winWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - winHeight) / 2);
	
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(windowTitle.c_str());

	glutDisplayFunc(Application::loop);
	glutReshapeFunc(Application::reshape);

	GLint err = glewInit();
	if (err != GLEW_OK)
		Log::fatalError("Could not initialize GLEW: %s", glewGetErrorString(err));

	init();
}

void Application::reshape(int width, int height)
{
	Log::log("Resize viewport to %dx%d", width, height);

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

	if (_controller)
		_controller->onWindowResize(width, height);
}

void Application::preloadShaders()
{
	Log::log("Preloading shaders...");

	Shader *vertex = ShaderManager::instance()->loadFromFile("Vertex", kShaderTypeVertex, "simple.vs");
	Shader *fragment = ShaderManager::instance()->loadFromFile("Fragment", kShaderTypeFragment, "simple.fs");
	_defaultProgram = new ShaderProgram(vertex, fragment);
}

void Application::init()
{
	Log::log("Initializing default OpenGL config...");

	glClearColor(0, 0, 0, 1);

	preloadShaders();
}

void Application::loop()
{
	update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	_defaultProgram->use();
	display();

	glutSwapBuffers();
	glutPostRedisplay();
}

void Application::update()
{
	if (_controller)
		_controller->update(0);
}

void Application::display()
{
	if (_controller)
		_controller->render();
}

Application::~Application()
{
}

Application * Application::mainApp()
{
	static Application *app;
	if (!app)
		app = new Application("OpenGL Application");
	return app;
}

void Application::useController(ApplicationController * controller)
{
	_controller = controller;
}

int Application::mainLoop()
{
	if (_controller)
		_controller->onApplicationStart();

	Log::log("Application started!");
	glutMainLoop();

	if (_controller)
		_controller->onApplicationEnd();

	return 0;
}
