#pragma once
#include "BaseWindow.h"
#include "Scene.h"

class Window : public BaseWindow
{
public:
	Window(int w, int h, const char* title);

private:
	void OnMouseButton(int button, int action, [[maybe_unused]] int mods) override;
	void OnMouseMove(double x, double y) override;
	void RotateCamera(double xAngleRadians, double yAngleRadians);
	void OnResize(int width, int height) override;
	void OnScroll(double x, double y) override;
	void OnKey(int key, int scancode, int action, int mods) override;
	void OnRunStart() override;
	void Draw(int width, int height) override;
	void SetupCameraMatrix();
	void SetupFog();

	Scene m_scene;
	
	int m_destance_to_origin = 4;

	bool m_leftButtonPressed = false;
	bool m_isFogEnabled = true;
	float m_zoomValue = 45.0f;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 7.0, 5.0, m_destance_to_origin },
		glm::dvec3{ 0.0, 0.0, 0.0 },
		glm::dvec3{ 0.0, 1.0, 0.0 });
};
