#include "pch.h"
#include "Pyramid.h"

Pyramid::Pyramid(PyramidSideSize&& size, float height)
	: m_size(std::move(size))
	, m_height(height)
{
}

void Pyramid::Draw() const
{
	glEnable(GL_COLOR_MATERIAL);
	//÷вет вершины будет управл€ть диффузным и фоновым цветом материала
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(m_specularColor));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

	glBegin(GL_TRIANGLES);
	{
		glNormal3f(0.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(1.0f, 0.5f);
		glVertex3f(0.0f, 1.5f * m_height, 0.0f);

		glNormal3f(-1.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.5f);
		glVertex3f(0.0f, 1.5f * m_height, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);

		glNormal3f(0.0f, 1.0f, -2.0f);
		glTexCoord2f(1.0f, 0.5f);
		glVertex3f(0.0f, 1.5f * m_height, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, -0.5f);

		glNormal3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.5f);
		glVertex3f(0.0f, 1.5f * m_height, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, -0.5f);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
	}
	glEnd();
}

void Pyramid::SetSpecularColor(glm::vec4 color)
{
	m_specularColor = color;
}

void Pyramid::SetShininess(float shininess)
{
	m_shininess = shininess;
}
