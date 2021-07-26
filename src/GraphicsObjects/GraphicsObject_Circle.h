#ifndef GRAPHICS_OBJECT_CIRCLE_H
#define GRAPHICS_OBJECT_CIRCLE_H

#include <sb6.h>
#include "GraphicsObject.h"
#include "Texture.h"
#include "Image.h"
#include "Color.h"

class GraphicsObject_Circle : public GraphicsObject
{
public:
	GraphicsObject_Circle(Rect rect);
	~GraphicsObject_Circle();

	// Rendermaterial contract
	virtual void SetState() override;
	virtual void SetDataGPU() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

private:
	// data:  place uniform instancing here
	Matrix * pMatrix_orig;

public:
	float origWidth;
	float origHeight;
	Color::Type color;

	float origPosX;
	float origPosY;
};
#endif