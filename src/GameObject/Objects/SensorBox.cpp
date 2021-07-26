#include "SensorBox.h"
#include "ContactAction.h"
SensorBox::~SensorBox()
{
}

SensorBox::SensorBox(GameObjectName::Name name, GraphicsObject_Box* graphicsObject_Box)
	:
	GameObject2D(name, nullptr, graphicsObject_Box)
{
}

void SensorBox::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void SensorBox::CollideVisit(Gear& pGear, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, pGear, pContact, pImpulse);
}

void SensorBox::CollideVisit(Glass& pGlass, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, pGlass, pContact, pImpulse);
}

//void CollisionObjectBox::CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*)
//{
//}


