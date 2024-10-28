#pragma once
#include <functional>
#include <memory>
#include "Pyramid.h"
#include "Cube.h"
#include "TextureProvider.h"

using CreatePyramidHandler = std::function<std::shared_ptr<Pyramid>(Pyramid::PyramidSideSize&& size, float height)>;
using CreateCubeHandler = std::function<std::shared_ptr<Cube>(float size)>;

class House
{
public:
	House() = delete;
	void static Draw(CreatePyramidHandler pyramidHandler, CreateCubeHandler cubeHandler, const TextureProvider& textureProvider);
};
