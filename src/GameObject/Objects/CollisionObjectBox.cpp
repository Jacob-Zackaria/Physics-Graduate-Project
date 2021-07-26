#include "CollisionObjectBox.h"

CollisionObjectBox::~CollisionObjectBox()
{
}

CollisionObjectBox::CollisionObjectBox(GameObjectName::Name name, GraphicsObject_Box* graphicsObject_Box)
	:
	GameObject2D(name, nullptr, graphicsObject_Box)
{
}

void CollisionObjectBox::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

//void CollisionObjectBox::CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*)
//{
//}


