#ifndef TEXTURE_H
#define TEXTURE_H

#define TEXTURE_ASSET_NAME_SIZE 64

#include "sb6.h"
#include "TextureName.h"

class Texture
{
public:
	Texture();
	void set(const char * const _assetName,
		TextName::Name _name,
		GLuint _TextureID,
		GLenum minFilter,
		GLenum magFilter,
		GLenum wrapMode,
		int width,
		int height);

private:
	char assetName[TEXTURE_ASSET_NAME_SIZE];

public:
	TextName::Name name;
	GLuint textureID;
	GLenum minFilter;
	GLenum magFilter;
	GLenum wrapMode;
	int width;
	int height;
};


#endif