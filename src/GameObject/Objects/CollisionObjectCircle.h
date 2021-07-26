#ifndef COLLISION_OBJECT_CIRCLE_H
#define COLLISION_OBJECT_CIRCLE_H

#include "GameObject2D.h"

class CollisionObjectCircle : public GameObject2D
{
public:
	CollisionObjectCircle() = delete;
	CollisionObjectCircle(const CollisionObjectCircle&) = delete;
	const CollisionObjectCircle& operator = (const CollisionObjectCircle&) = delete;
	~CollisionObjectCircle();
	CollisionObjectCircle(GameObjectName::Name name, GraphicsObject_Circle* graphicsObject_Cirlce);

};

#endif COLLISION_OBJECT_CIRCLE_H