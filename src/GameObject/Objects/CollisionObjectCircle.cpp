#include "CollisionObjectCircle.h"

CollisionObjectCircle::~CollisionObjectCircle()
{
}

CollisionObjectCircle::CollisionObjectCircle(GameObjectName::Name name, GraphicsObject_Circle* graphicsObject_Circle)
	:
	GameObject2D(name, nullptr, graphicsObject_Circle)
{
}


