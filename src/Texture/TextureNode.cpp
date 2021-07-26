#include <string.h>
#include <sb6.h>


#include "TextureNode.h"

TextureNode::TextureNode()
{
	pText = new Texture();
};

TextureNode::~TextureNode()
{
	delete pText;
}

void TextureNode::SetText(const char * const _assetName,
	TextName::Name _name,
	GLuint _TextureID,
	GLenum _minFilter,
	GLenum _magFilter,
	GLenum _wrapMode,
	int _width,
	int _height)
{
	pText->set(_assetName, _name, _TextureID, _minFilter, _magFilter, _wrapMode, _width, _height);
}

GLuint TextureNode::GetTextID() const
{
	return pText->textureID;
}

TextName::Name TextureNode::GetTextName() const
{
	return pText->name;
}

Texture *TextureNode::GetTexture()
{
	return pText;
}