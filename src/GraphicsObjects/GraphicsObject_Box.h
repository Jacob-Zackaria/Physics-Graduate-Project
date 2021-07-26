#ifndef GRAPHICS_OBJECT_BOX_H
#define GRAPHICS_OBJECT_BOX_H

#include <sb6.h>
#include "GraphicsObject.h"
#include "Rect.h"
#include "Color.h"

class GraphicsObject_Box : public GraphicsObject
{
public:
	GraphicsObject_Box(  Rect rect);
	~GraphicsObject_Box();

	// Rendermaterial contract
	virtual void SetState() override;
	virtual void SetDataGPU() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

private:
	// data:  place uniform instancing here
	Matrix  *pMatrix_orig;

public:
	float origWidth;
	float origHeight;
	Color::Type color;

	float origPosX;
	float origPosY;
};
#endif