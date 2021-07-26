#include "Egg.h"
#include "ContactAction.h"


Egg::~Egg()
{
}

Egg::Egg(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle), nextLevel(false)
{
}


void Egg::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	 other.CollideVisit(*this, contact, pimpulse); 
}

void Egg::CollideVisit(Gear& pGear, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, pGear, pContact, pImpulse);
}


void Egg::NextLevel()
{
	this->nextLevel = true;
}




