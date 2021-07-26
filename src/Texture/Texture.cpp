#include <string.h>
#include <sb6.h>

#include "Texture.h"
#include "TextureName.h"

Texture::Texture()
	: name(TextName::Not_initialized),
	textureID(0),
	minFilter(GL_LINEAR),
	magFilter(GL_LINEAR),
	wrapMode(GL_CLAMP_TO_EDGE),
	width(-1),
	height(-1)
{
	
	memset( this->assetName, 0, TEXTURE_ASSET_NAME_SIZE );
}

void Texture::set(const char * const _assetName,
	TextName::Name _name,
	GLuint _TextureID,
	GLenum _minFilter,
	GLenum _magFilter,
	GLenum _wrapMode,
	int _width,
	int _height)
{
	memcpy(this->assetName, _assetName, TEXTURE_ASSET_NAME_SIZE - 1);
	this->name = _name;
	this->magFilter = _magFilter;
	this->minFilter = _minFilter;
	this->wrapMode = _wrapMode;
	this->textureID = _TextureID;
	this->width = _width;
	this->height = _height;
}