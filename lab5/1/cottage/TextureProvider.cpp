#include "pch.h"
#include "TextureProvider.h"
#include "CTextureLoader.h"
#include "TextureResourceName.h"
#include <functional>
#include <map>

CTexture2D* TextureProvider::GetTexture(const std::wstring& textureName) const
{
	if (textureName == texture::name::WOOD_TEXTURE)
	{
		InitTextureIfNeed(texture::name::WOOD_TEXTURE, m_woodTexture);
		return &m_woodTexture;
	}
	else if (textureName == texture::name::STONES_TEXTURE)
	{
		InitTextureIfNeed(texture::name::STONES_TEXTURE, m_stoneTexture);
		return &(m_stoneTexture);
	}
	else if (textureName == texture::name::LAND_TEXTURE)
	{
		InitTextureIfNeed(texture::name::LAND_TEXTURE, m_landTexture);
		return &(m_landTexture);
	}
	else if (textureName == texture::name::GLASS_TEXTURE)
	{
		InitTextureIfNeed(texture::name::GLASS_TEXTURE, m_glassTexture);
		return &(m_glassTexture);
	}
	else if (textureName == texture::name::DOOR_TEXTURE)
	{
		InitTextureIfNeed(texture::name::DOOR_TEXTURE, m_doorTexture);
		return &(m_doorTexture);
	}
	else if (textureName == texture::name::STEEL_TEXTURE)
	{
		InitTextureIfNeed(texture::name::STEEL_TEXTURE, m_steelTexture);
		return &(m_steelTexture);
	}
	else if (textureName == texture::name::GRASS_TEXTURE)
	{
		InitTextureIfNeed(texture::name::GRASS_TEXTURE, m_grassTexture);
		return &(m_grassTexture);
	}
	throw std::exception("There are no texture for this name");
}

void TextureProvider::InitTextureIfNeed(const std::wstring& textureName, CTexture2D& texture) const
{
	if (!texture)
	{
		CTextureLoader loader;
		loader.SetWrapMode(GL_REPEAT, GL_REPEAT);
		texture.Attach(loader.LoadTexture2D(textureName));
	}
}
