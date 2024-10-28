#include "pch.h"
#include "BaseWindow.h"

BaseWindow::BaseWindow(int width, int height, const std::string& title)
	: m_window{ MakeWindow(width, height, title.c_str()) }
{
	if (!m_window)
	{
		throw std::runtime_error("Failed to create window");
	}

	glfwSetWindowUserPointer(m_window, this);

	glfwSetWindowSizeCallback(m_window,
		[](GLFWwindow* window, int width, int height) {
			GetBaseWindow(window)->OnResize(width, height);
		});

	glfwSetMouseButtonCallback(m_window,
		[](GLFWwindow* window, int button, int action, int mods) {
			GetBaseWindow(window)->OnMouseButton(button, action, mods);
		});

	glfwSetCursorPosCallback(m_window,
		[](GLFWwindow* window, double x, double y) {
			GetBaseWindow(window)->OnMouseMove(x, y);
		});
}

BaseWindow::~BaseWindow()
{
	glfwDestroyWindow(m_window);
}

glm::ivec2 BaseWindow::GetFramebufferSize() const
{
	int width, height;
	glfwGetFramebufferSize(m_window, &width, &height);
	return { width, height };
}

void BaseWindow::Run()
{
	glfwMakeContextCurrent(m_window);
	OnRunStart();

	{
		auto size = GetFramebufferSize();
		OnResize(size.x, size.y);
	}

	while (!glfwWindowShouldClose(m_window))
	{
		auto size = GetFramebufferSize();
		Draw(size.x, size.y);
		glFinish();
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	OnRunEnd();
}

glm::dvec2 BaseWindow::GetCursorPos() const
{
	double x, y;
	glfwGetCursorPos(m_window, &x, &y);

	return { x, y };
}

BaseWindow* BaseWindow::GetBaseWindow(GLFWwindow* window)
{
	return reinterpret_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
}

GLFWwindow* BaseWindow::MakeWindow(int width, int height, const char* title)
{
	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	return glfwCreateWindow(width, height, title, nullptr, nullptr);
}
