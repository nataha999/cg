#include "pch.h"
#include "CMyApplication.h"

int main(int argc, char* argv[])
{
	CMyApplication application("curvature", 800, 600, argc, argv);
	try
	{
		if (glewInit() != GLEW_OK)
		{
			throw std::runtime_error("Failed to initialize GLEW");
		}
		application.MainLoop();
	}
	catch (std::exception const& e)
	{
		std::cout << e.what();
	}
	return 0;
}