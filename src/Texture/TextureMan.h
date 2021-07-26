#ifndef TEXTURE_MAN_H
#define TEXTURE_MAN_H

#include "sb6.h"
#include "Texture.h"
#include "TextureNode.h"
#include "TextureName.h"

// Singleton
class TextureMan
{
public:
	static void addTexture( const char * const _assetName, const TextName::Name _name);
	static void Terminate();
	static GLuint find( const TextName::Name _name);
	static Texture *findTexture(const TextName::Name _name);
	

private:  // methods

	static TextureMan *privGetInstance();
	TextureMan();
	~TextureMan();
	                  
	// helper private methods
	void privLoadTexture( const char * const _assetName, GLuint *&textureID, int &width, int &height );
	bool privLoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode, int &width, int &height);
	void privAddToFront(TextureNodeLink *node, TextureNodeLink *&head);

private:  // add
	TextureNodeLink *active;
};

#endif