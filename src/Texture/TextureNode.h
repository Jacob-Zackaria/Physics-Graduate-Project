#ifndef TEXTURE_NODE_H
#define TEXTURE_NODE_H

#include "sb6.h"
#include "Texture.h"

class TextureNodeLink
{
public:
	TextureNodeLink()
	{
		this->next = 0;
		this->prev = 0;
	}
	~TextureNodeLink()
	{
	}
	TextureNodeLink *next;
	TextureNodeLink *prev;
};


class TextureNode : public TextureNodeLink
{
public:
	TextureNode();
	~TextureNode();

	void SetText(const char * const _assetName,
		TextName::Name _name,
		GLuint _TextureID,
		GLenum _minFilter,
		GLenum _magFilter,
		GLenum _wrapMode,
		int _width,
		int _height);

	GLuint GetTextID() const;
	TextName::Name GetTextName() const;
	Texture *GetTexture();

private:
	Texture *pText;
};


#endif