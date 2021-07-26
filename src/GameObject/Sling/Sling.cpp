#include "Sling.h"

Sling::~Sling()
{
}

Sling::Sling(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle)
{
}



