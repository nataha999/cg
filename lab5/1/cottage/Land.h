#pragma once
#include "Cube.h"
#include "TextureProvider.h"

class Land
{
public:
	Land() = delete;

	void static Draw(const std::shared_ptr<Cube>& cube, const TextureProvider& textureProvider);
};
