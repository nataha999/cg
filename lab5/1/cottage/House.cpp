#include "pch.h"
#include "House.h"
#include "TextureResourceName.h"

namespace
{
void DrawHouseMainPart(CreateCubeHandler cubeHandler, const TextureProvider& textureProvider)
{
	auto cube = cubeHandler(3);
	auto woodTexture = textureProvider.GetTexture(texture::name::WOOD_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	woodTexture->Bind();

	glPushMatrix();
	{
		glScalef(1.0f, 1.0f, 0.7f);
		glTranslatef(1.0f, 1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glScalef(1.0f, 1.0f, 0.7f);
		glTranslatef(-2.0f, 1.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();
}

void DrawHouseAdditionalPart(CreateCubeHandler cubeHandler, const TextureProvider& textureProvider)
{
	auto cube = cubeHandler(2);
	auto woodTexture = textureProvider.GetTexture(texture::name::WOOD_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	woodTexture->Bind();

	glPushMatrix();
	{
		glScalef(1.5f, 1.3f, 0.7f);
		glTranslatef(2.0f, 0.0f, 1.0f);
		cube->Draw();
	}
	glPopMatrix();
}

void DrawWindows(CreateCubeHandler cubeHandler, const TextureProvider& textureProvider)
{
	auto cube = cubeHandler(0.8);
	auto glassTexture = textureProvider.GetTexture(texture::name::GLASS_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	glassTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(1.8f, 1.8f, 1.8f);
		glScalef(1.0f, 1.0f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-2.7f, 1.8f, 1.8f);
		glScalef(1.0f, 1.0f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	cube = cubeHandler(1.5);
	glPushMatrix();
	{
		glTranslatef(-0.4f, 1.7f, 1.8f);
		glScalef(0.85f, 0.6f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();
}

void DrawBalcony(CreateCubeHandler cubeHandler, const TextureProvider& textureProvider)
{
	auto cube = cubeHandler(0.8);
	auto stoneTexture = textureProvider.GetTexture(texture::name::STONES_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	stoneTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(-0.8f, 1.5f, 2.58f);
		glScalef(1.0f, 0.5f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(0.0f, 1.5f, 2.58f);
		glScalef(1.0f, 0.5f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.32f, 1.5f, 2.1f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.5f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-1.12f, 1.5f, 2.1f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.5f, 0.2f);
		cube->Draw();
	}
	glPopMatrix();

	cube = cubeHandler(1.6);
	glPushMatrix();
	{
		glTranslatef(-0.4f, 1.22f, 2.1f);
		glScalef(1.0f, 0.1f, 0.7f);
		cube->Draw();
	}
	glPopMatrix();
}

void DrawDoor(CreateCubeHandler cubeHandler, const TextureProvider& textureProvider)
{
	auto cube = cubeHandler(1.0);
	auto doorTexture = textureProvider.GetTexture(texture::name::DOOR_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	doorTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(-0.4f, 0.0f, 1.75f);
		glScalef(0.6f, 1.1f, 0.05f);
		cube->Draw();
	}
	glPopMatrix();
}

void DrawGarade(CreateCubeHandler cubeHandler, const TextureProvider& textureProvider)
{
	auto cube = cubeHandler(1.8);

	auto steelTexture = textureProvider.GetTexture(texture::name::STEEL_TEXTURE);

	glEnable(GL_TEXTURE_2D);
	steelTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(3.5f, 0.0f, 1.45f);
		glScalef(1.0f, 1.0f, 0.05f);
		cube->Draw();
	}
	glPopMatrix();
}

void DrawRoof(CreatePyramidHandler pyramidHandler, const TextureProvider& textureProvider)
{
	// use transform and scale on texture matrix with model-view matrix
	auto pyramid = pyramidHandler({ 1.0f, 2.0f, 3.0f, 4.0f }, 0.7);
	auto woodTexture = textureProvider.GetTexture(texture::name::WOOD_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	woodTexture->Bind();

	glPushMatrix();
	{
		glTranslatef(-2.5f, 1.5f, 0.7f);
		glScalef(2.0f, 2.0f, 2.5f);
		pyramid->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-0.5f, 1.5f, 0.7f);
		glScalef(2.0f, 2.0f, 2.5f);
		pyramid->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(1.5f, 1.5f, 0.7f);
		glScalef(2.0f, 2.0f, 2.5f);
		pyramid->Draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(3.5f, 0.3f, 0.7f);
		glScalef(2.2f, 2.0f, 2.0f);
		pyramid->Draw();
	}
	glPopMatrix();
}
}

void House::Draw(CreatePyramidHandler pyramidHandler, CreateCubeHandler cubeHandler, const TextureProvider& textureProvider)
{
	// make House state great again
	DrawHouseMainPart(cubeHandler, textureProvider); // TODO: remove invokation functions with same params
	DrawHouseAdditionalPart(cubeHandler, textureProvider);
	DrawWindows(cubeHandler, textureProvider);
	DrawBalcony(cubeHandler, textureProvider);
	DrawDoor(cubeHandler, textureProvider);
	DrawGarade(cubeHandler, textureProvider);
	DrawRoof(pyramidHandler, textureProvider);
}