#include "GreenBird.h"

GreenBird::~GreenBird()
{
}

GreenBird::GreenBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle)
{
}
