#include "Ejik.h"
#include <glut.h>
#include <math.h>
#include <numbers>

namespace
{
void FillEllipse(float xCenter, float yCenter, float rx, float ry, int points)
{
	const float step = 2 * std::numbers::pi / points;

	glBegin(GL_TRIANGLE_FAN);

	glVertex2d(xCenter, yCenter);

	for (float angle = 0; angle <= 2 * std::numbers::pi; angle += step)
	{
		float a = (fabsf(angle - 2 * std::numbers::pi) < 1e-5) ? 0 : angle;
		const float dx = rx * cosf(a);
		const float dy = ry * sinf(a);
	
		glVertex2f(dx + xCenter, dy + yCenter);
	}

	glEnd();
}

void DrawEars(float x, float y)
{
	glColor3f(0.81, 0.14, 0.58);

	FillEllipse(125 + x, 250 + y, 5, 8, 360);
	FillEllipse(275 + x, 250 + y, 5, 8, 360);
}

void DrawEyebrows(float x, float y)
{
	glColor3f(0.56, 0.10, 0.41);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2d(180 + x, 280 + y);
		glVertex2d(170 + x, 270 + y);
		glVertex2d(169 + x, 278 + y);
		glVertex2d(179 + x, 287 + y);
		glVertex2d(192 + x, 293 + y);
		glVertex2d(190 + x, 284 + y);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glVertex2d(220 + x, 280 + y);
		glVertex2d(230 + x, 270 + y);
		glVertex2d(231 + x, 278 + y);
		glVertex2d(221 + x, 287 + y);
		glVertex2d(208 + x, 293 + y);
		glVertex2d(210 + x, 284 + y);
	glEnd();
}

void DrawNoseAndMouth(float x, float y)
{
	glColor3f(0.56, 0.10, 0.41);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(190 + x, 200 + y);
		glVertex2d(210 + x, 200 + y);
		glVertex2d(200 + x, 190 + y);
	glEnd();

	glBegin(GL_LINES);
		glVertex2d(200 + x, 190 + y);
		glVertex2d(200 + x, 180 + y);
	glEnd();
	glColor3f(0.22, 0.04, 0.16);
	
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(190 + x, 185 + y);
		glVertex2d(200 + x, 180 + y);
		glVertex2d(200 + x, 170 + y);
		glVertex2d(210 + x, 185 + y);
	glEnd();
}

void DrawBody(float x, float y)
{
	glColor3f(0.81, 0.14, 0.58);

	FillEllipse(200 + x, 200 + y, 80, 120, 360);

	DrawEars(x, y);
	
	DrawEyebrows(x, y);
	DrawNoseAndMouth(x, y);
}

void DrawEyes(float x, float y)
{
	glColor3f(0.188, 0.153, 0.274);

	FillEllipse(170 + x, 220 + y, 30, 50, 360);
	FillEllipse(230 + x, 220 + y, 30, 50, 360);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(250 + x, 230 + y);
		glVertex2d(275 + x, 260 + y);
		glVertex2d(255 + x, 225 + y);
		glVertex2d(275 + x, 235 + y);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(150 + x, 230 + y);
		glVertex2d(125 + x, 260 + y);
		glVertex2d(145 + x, 225 + y);
		glVertex2d(125 + x, 235 + y);
	glEnd();
	
	glColor3f(255, 255, 255);

	FillEllipse(170 + x, 220 + y, 21, 35, 360);
	FillEllipse(230 + x, 220 + y, 21, 35, 360);

	
	glColor3f(0, 0, 0);

	FillEllipse(180 + x, 215 + y, 10, 20, 360);
	FillEllipse(220 + x, 215 + y, 10, 20, 360);
}

void DrawHead(float x, float y)
{
	glColor3f(0.28, 0.18, 0.53);
		
	glBegin(GL_TRIANGLE_FAN);
		glVertex2d(200 + x, 100 + y);

		glVertex2d(90 + x, 260 + y);
		glVertex2d(120 + x, 280 + y);
		glVertex2d(122 + x, 337 + y);
		glVertex2d(150 + x, 320 + y);
		glVertex2d(170 + x, 370 + y);
		glVertex2d(190 + x, 340 + y);
		glVertex2d(208 + x, 380 + y);
		glVertex2d(220 + x, 334 + y);
		glVertex2d(253 + x, 361 + y);
		glVertex2d(248 + x, 312 + y);
		glVertex2d(287 + x, 323 + y);
		glVertex2d(275 + x, 280 + y);
		glVertex2d(310 + x, 260 + y);
	glEnd();
}

void DrawHands(float x, float y)
{
	glColor3f(0.81, 0.14, 0.58);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(275 + x, 175 + y);
		glVertex2d(290 + x, 175 + y);
		glVertex2d(275 + x, 185 + y);

		glVertex2d(290 + x, 185 + y);
		glVertex2d(285 + x, 185 + y);
		glVertex2d(290 + x, 150 + y);
		glVertex2d(285 + x, 150 + y);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(125 + x, 175 + y);
		glVertex2d(110 + x, 175 + y);
		glVertex2d(125 + x, 185 + y);

		glVertex2d(110 + x, 185 + y);
		glVertex2d(115 + x, 185 + y);
		glVertex2d(110 + x, 150 + y);
		glVertex2d(115 + x, 150 + y);
	glEnd();
}

void DrawLegs(float x, float y)
{
	glColor3f(0.81, 0.14, 0.58);

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(220 + x, 100 + y);
		glVertex2d(230 + x, 100 + y);
		glVertex2d(220 + x, 40 + y);

		glVertex2d(230 + x, 40 + y);
		glVertex2d(230 + x, 60 + y);
		glVertex2d(240 + x, 40 + y);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2d(180 + x, 100 + y);
		glVertex2d(170 + x, 100 + y);
		glVertex2d(180 + x, 40 + y);

		glVertex2d(170 + x, 40 + y);
		glVertex2d(170 + x, 60 + y);
		glVertex2d(160 + x, 40 + y);
	glEnd();
}

}

Ejik::Ejik()
{
}

void Ejik::Draw(float x, float y) const
{
	// ����������� ����� ��������� (�������) �������������
	glPointSize(2.0);

	DrawHead(x, y);
	DrawBody(x, y);
	DrawEyes(x, y);
	DrawHands(x, y);
	DrawLegs(x, y);
	
	glFlush();
}
