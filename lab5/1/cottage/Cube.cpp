#include "pch.h"
#include "Cube.h"

Cube::Cube(float size)
	: m_size(size)
{
}

void Cube::Draw() const
{
	glEnable(GL_COLOR_MATERIAL);
	// ÷вет вершины будет управл€ть диффузным и фоновым цветом материала
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(m_specularColor));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

	glBegin(GL_QUADS);
	{
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, 0.5f * m_size);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, -0.5f * m_size);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, 0.5f * m_size);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, -0.5f * m_size);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f * m_size, 0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f * m_size, 0.5f * m_size, -0.5f * m_size);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, -0.5f * m_size);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f * m_size, -0.5f * m_size, 0.5f * m_size);
	}
	glEnd();
}

void Cube::SetSpecularColor(glm::vec4 color)
{
	m_specularColor = color;
}

void Cube::SetShininess(float shininess)
{
	m_shininess = shininess;
}
