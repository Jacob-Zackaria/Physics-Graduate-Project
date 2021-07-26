#include "BigBird.h"

BigBird::BigBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle)
{
}

BigBird::BigBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Box)
	:
	Bird(name, graphicsObject, graphicsObject_Box)
{
}

BigBird::~BigBird()
{
}
