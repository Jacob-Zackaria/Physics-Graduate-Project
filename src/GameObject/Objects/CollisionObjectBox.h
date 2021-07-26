#ifndef COLLISION_OBJECT_BOX_H
#define COLLISION_OBJECT_BOX_H

#include "GameObject2D.h"

class CollisionObjectBox : public GameObject2D
{
public:
	CollisionObjectBox() = delete;
	CollisionObjectBox(const CollisionObjectBox&) = delete;
	const CollisionObjectBox& operator = (const CollisionObjectBox&) = delete;
	~CollisionObjectBox();
	CollisionObjectBox(GameObjectName::Name name, GraphicsObject_Box* graphicsObject_Box);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	//virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) override;
};

#endif COLLISION_OBJECT_BOX_H