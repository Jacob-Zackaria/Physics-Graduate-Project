#include "Gear.h"
#include "ContactAction.h"
Gear::~Gear()
{
}

Gear::Gear(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle)
{
}

void Gear::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void Gear::CollideVisit(Egg& pEgg, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(pEgg, *this, pContact, pImpulse);
}

void Gear::CollideVisit(SensorBox& pSens, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(pSens, *this, pContact, pImpulse);
}

