#include "pch.h"
#include "Land.h"
#include "TextureResourceName.h"

void Land::Draw(const std::shared_ptr<Cube>& cube, const TextureProvider& textureProvider)
{
	auto floor = cube;

	auto landTexture = textureProvider.GetTexture(texture::name::LAND_TEXTURE);
	auto grassTexture = textureProvider.GetTexture(texture::name::GRASS_TEXTURE);
	glEnable(GL_TEXTURE_2D);

	for (auto indexI = -2.0f; indexI <= 2.0f; indexI += 1.0f)
	{
		for (auto indexJ = -2.0f; indexJ <= 2.0f; indexJ += 1.0f)
		{
			if ((int)indexI + (int)indexJ % 2 == 0)
			{
				landTexture->Bind();
			}
			else
			{
				grassTexture->Bind();
			}
			glPushMatrix();
			{
				glScalef(4.0f, 0.1f, 4.0f);
				glTranslatef(indexI, -5.0f, indexJ);
				floor->Draw();
			}
			glPopMatrix();
		}
	}
}
