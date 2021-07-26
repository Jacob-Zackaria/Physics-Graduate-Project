#include <stdlib.h>
#include <sb6.h>
#include <assert.h>

#include "TextureNode.h"
#include "TextureMan.h"
#include "TextureTGA.h"


TextureMan::TextureMan()
{
	this->active = 0;
}

TextureMan * TextureMan::privGetInstance()
{
	// This is where its actually stored (BSS section)
	static TextureMan textMan;
	return &textMan;
}


void TextureMan::addTexture( const char * const _assetName, const TextName::Name _name)
{
	GLuint               textureID;
	GLuint *pTextureID = &textureID;

	// Get the instance to the manager
	TextureMan *pTextMan = TextureMan::privGetInstance();

	// Load the texture and get the textureID
	int width;
	int height;
	pTextMan->privLoadTexture( _assetName, pTextureID, width, height );

	// Create a TextureNode
	TextureNode *pNode = new TextureNode();

	// initialize it
	pNode->SetText( _assetName, _name, textureID, GL_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE, width, height);

	// Now add it to the manager
	pTextMan->privAddToFront( pNode, pTextMan->active );
}

GLuint TextureMan::find( const TextName::Name _name)
{
	// Get the instance to the manager
	TextureMan *pTextMan = TextureMan::privGetInstance();
	TextureNode *pNode = (TextureNode *)pTextMan->active;
	while( pNode != 0 )
	{
		if( pNode->GetTextName() == _name )
		{
			// found it
			break;
		}
		pNode = (TextureNode *)pNode->next;
	}
	return pNode->GetTextID();
}

Texture *TextureMan::findTexture(const TextName::Name _name)
{
	// Get the instance to the manager
	TextureMan *pTextMan = TextureMan::privGetInstance();
	TextureNode *pNode = (TextureNode *)pTextMan->active;
	while (pNode != 0)
	{
		if (pNode->GetTextName() == _name)
		{
			// found it
			break;
		}
		pNode = (TextureNode *)pNode->next;
	}
	return pNode->GetTexture();
}

void TextureMan::Terminate( )
{
	// Get the instance to the manager
	TextureMan *pTextMan = TextureMan::privGetInstance();
	TextureNode *pNode = (TextureNode *)pTextMan->active;
	while( pNode != 0 )
	{
		// bye bye
		//glDeleteTextures(1, &pNode->pText->textureID);
		GLuint textureID = pNode->GetTextID();
		glDeleteTextures(1, &textureID );
		TextureNode* pTmp = pNode;
		// next
		pNode = (TextureNode *)pNode->next;
		
		// NB: should also delete the PCS node
		delete pTmp;
	}
}

void TextureMan::privAddToFront(TextureNodeLink *node, TextureNodeLink *&head)
{
    assert(node != 0);
    if (head == 0)
    {
        head = node;
        node->next = 0;
        node->prev = 0;
    }
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void TextureMan::privLoadTexture( const char * const _assetName, GLuint *&textureID, int &width, int &height)
{    
	// Get an ID, for textures (OpenGL poor man's handle)
	glGenTextures(1, textureID);
	// Bind it.
	glBindTexture(GL_TEXTURE_2D, *textureID);
	// Loat the texture
	this->privLoadTGATexture(_assetName, GL_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE, width, height);
}



// Load a TGA as a 2D Texture. Completely initialize the state
bool TextureMan::privLoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode, int &nWidth, int &nHeight)
{
	GLbyte *pBits;
	//int nWidth, nHeight, 
	int nComponents;
	GLenum eFormat;
	
	// Read the texture bits
	pBits = gltReadTGABits(szFileName, &nWidth, &nHeight, &nComponents, &eFormat);
	if(pBits == NULL) 
		return false;
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (GLint)wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (GLint)wrapMode);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (GLint)minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (GLint)magFilter);
    
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBits);
	
    free(pBits);
    
    if(minFilter == GL_LINEAR_MIPMAP_LINEAR || 
       minFilter == GL_LINEAR_MIPMAP_NEAREST ||
       minFilter == GL_NEAREST_MIPMAP_LINEAR ||
       minFilter == GL_NEAREST_MIPMAP_NEAREST)
        glGenerateMipmap(GL_TEXTURE_2D);
    
	return true;
}

TextureMan::~TextureMan()
{

}



