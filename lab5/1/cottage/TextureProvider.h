#pragma once
#include "Texture.h"


class TextureProvider
{
public:
	TextureProvider() = default;

	CTexture2D* GetTexture(const std::wstring& textureName) const;

	~TextureProvider() = default;

private:
	void InitTextureIfNeed(const std::wstring& textureName, CTexture2D& texture) const;

	mutable CTexture2D m_woodTexture;
	mutable CTexture2D m_stoneTexture;
	mutable CTexture2D m_landTexture;
	mutable CTexture2D m_glassTexture;
	mutable CTexture2D m_doorTexture;
	mutable CTexture2D m_steelTexture;
	mutable CTexture2D m_grassTexture;
};
