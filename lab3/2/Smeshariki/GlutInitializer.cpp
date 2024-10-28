#include "GlutInitializer.h"
#include <glut.h>

namespace
{

void myInit(void)
{
	glClearColor(1.0, 0.5, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void onResizeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	const auto aspectRatio = static_cast<float>(width) / static_cast<float>(height) * 0.7;
	gluOrtho2D(-aspectRatio, aspectRatio, -1.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
}

}

GlutInitializer::GlutInitializer(int argc, char** argv, void (*func)(void))
{
	glutInit(&argc, argv);

	glutInitDisplayMode(
		GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(1900, 740);

	glutInitWindowPosition(0, 0);

	glutCreateWindow("Ejik");
	glutDisplayFunc(func);
	glutReshapeFunc(onResizeWindow);
	myInit();

	glutMainLoop();
}
