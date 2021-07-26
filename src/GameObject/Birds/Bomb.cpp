#include "Bomb.h"

Bomb::~Bomb()
{
}

Bomb::Bomb(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle)
{
}
