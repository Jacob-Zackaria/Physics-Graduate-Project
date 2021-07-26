#ifndef COLLISION_OBJECT_TRI_H
#define COLLISION_OBJECT_TRI_H

#include "GameObject2D.h"

class CollisionObjectTri : public GameObject2D
{
public:
	CollisionObjectTri() = delete;
	CollisionObjectTri(const CollisionObjectTri&) = delete;
	const CollisionObjectTri& operator = (const CollisionObjectTri&) = delete;
	~CollisionObjectTri();
	CollisionObjectTri(GameObjectName::Name name, GraphicsObject_Tri* graphicsObject_Tri);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	//virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) override;
};

#endif COLLISION_OBJECT_TRI_H