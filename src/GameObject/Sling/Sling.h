#ifndef SLING_H
#define SLING_H

#include "GameObject2D.h"

class Sling : public GameObject2D
{
public:
	Sling() = delete;
	Sling(const Sling&) = delete;
	const Sling& operator = (const Sling&) = delete;
	~Sling();
	Sling(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle);
	
};

#endif SLING_H