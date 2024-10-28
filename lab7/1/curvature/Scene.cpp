#include "pch.h"
#include "Scene.h"

void Scene::Draw()
{
	auto y = 0.005f;
	auto z = 1.0f;
	glPointSize(1.0f);
	glBegin(GL_LINES);
	auto step = M_PI / 10000;

	for (float x = 0; x < 2 * M_PI; x += step)
	{
		glVertex3f(x + step, y, z);
		glVertex3f(x, y, z);
	}
	glEnd();
}