#include "CollisionObjectTri.h"

CollisionObjectTri::~CollisionObjectTri()
{
}

CollisionObjectTri::CollisionObjectTri(GameObjectName::Name name, GraphicsObject_Tri* graphicsObject_Tri)
	:
	GameObject2D(name, nullptr, graphicsObject_Tri)
{
}

void CollisionObjectTri::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

//void CollisionObjectBox::CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*)
//{
//}


