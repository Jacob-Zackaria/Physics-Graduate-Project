#include "BlueBird.h"

BlueBird::~BlueBird()
{
}

BlueBird::BlueBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle)
{
}
