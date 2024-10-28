#include "pch.h"
#include "Scene.h"
#include "CTextureLoader.h"
#include "Cube.h"
#include "House.h"
#include "Land.h"
#include "Pyramid.h"
#include "TextureResourceName.h"

namespace
{
std::shared_ptr<Cube> CreateCube(float size)
{
	auto cube = std::make_shared<Cube>(size);
	cube->SetSpecularColor({ 1, 1, 1, 1 });
	cube->SetShininess(4.0f);

	return cube;
}

std::shared_ptr<Pyramid> CreatePyramid(Pyramid::PyramidSideSize&& size, float height)
{
	auto pyramid = std::make_shared<Pyramid>(std::move(size), height);
	pyramid->SetSpecularColor({ 1, 1, 1, 1 });
	pyramid->SetShininess(4.0f);

	return pyramid;
}
} // namespace

void Scene::Draw() const
{
	Land::Draw(CreateCube(1), textureProvider);
	House::Draw(CreatePyramid, CreateCube, textureProvider);
}