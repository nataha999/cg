#pragma once

class Pyramid
{
public:
	struct PyramidSideSize
	{
		float negativeX = 1;
		float positiveX = 1;
		float negativeZ = 1;
		float positiveZ = 1;
	};

	explicit Pyramid(PyramidSideSize&& size, float height = 1);
	void Draw() const;

	void SetSpecularColor(glm::vec4 color);
	void SetShininess(float shininess);

private:
	PyramidSideSize m_size;
	float m_height;
	glm::vec4 m_specularColor = { 0, 0, 0, 1 };
	float m_shininess = 1;
};
