#ifndef GRAPHICS_OBJECT_TRI_H
#define GRAPHICS_OBJECT_TRI_H

#include <sb6.h>
#include "GraphicsObject.h"
#include "Rect.h"
#include "Vect2D.h"
#include "Color.h"

class GraphicsObject_Tri : public GraphicsObject
{
public:

	GraphicsObject_Tri( Vect2D originPoint, Vect2D *vertList);
	~GraphicsObject_Tri();

	// Rendermaterial contract
	virtual void SetState() override;
	virtual void SetDataGPU() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

	// data:  place uniform instancing here
	Matrix  *pMatrix_orig;
	
	float origWidth;
	float origHeight;
	Color::Type color;

	Vect2D originPt;
	Vect2D originVerts[3];
};
#endif