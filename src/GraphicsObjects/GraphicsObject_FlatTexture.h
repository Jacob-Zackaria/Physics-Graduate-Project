#ifndef GRAPHICS_OBJECT_TEXTURE_H
#define GRAPHICS_OBJECT_TEXTURE_H

#include <sb6.h>
#include "GraphicsObject.h"
#include "Texture.h"

class GraphicsObject_FlatTexture : public GraphicsObject
{
public:
	GraphicsObject_FlatTexture(Model *model, Shader *pShaderObj, TextName::Name name);

	// Rendermaterial contract
	virtual void SetState() override;
	virtual void SetDataGPU() override;	
	virtual void Draw() override;
	virtual void RestoreState() override;

// data:  place uniform instancing here
	
	//GLuint textureID;
	TextName::Name textName;


};
#endif