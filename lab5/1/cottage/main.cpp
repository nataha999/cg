#include "pch.h"
#include "GLFWInitializer.h"
#include "CGdiplusInitializer.h"
#include "Window.h"

int main()
{
	GLFWInitializer initializer;
	CGdiplusInitializer gdiInitializer;

	Window window{ 800, 600, "Cottage" };
	window.Run();
}
