#pragma once
#include "TextureProvider.h"

class Scene
{
public:
	void Draw() const;

	~Scene() = default;

private:
	TextureProvider textureProvider;
};
