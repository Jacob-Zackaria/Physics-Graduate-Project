#ifndef GRAPHICS_OBJECT_SPRITE_H
#define GRAPHICS_OBJECT_SPRITE_H

#include <sb6.h>
#include "GraphicsObject.h"
#include "Texture.h"
#include "Image.h"

class GraphicsObject_Sprite : public GraphicsObject
{
public:
	GraphicsObject_Sprite(ImageName::Name name, Rect rect);
	~GraphicsObject_Sprite();

	// Rendermaterial contract
	virtual void SetState() override;
	virtual void SetDataGPU() override;	
	virtual void Draw() override;
	virtual void RestoreState() override;

	const Rect GetRect() const;

private:
	Image	*pImage;
	Matrix	*pMatrix_uv;
	Matrix  *pMatrix_orig;

public:
	float origWidth; 
	float origHeight; 

	float origPosX;
	float origPosY;
};
#endif