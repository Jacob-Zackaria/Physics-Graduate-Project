#include "Projector.h"
#include "ManagedPool.h"
#include "GameObjectMan.h"

Projector::Projector(ManagedPool* pool)
	: pPool(pool),
	GameObject2D(
		GameObjectName::Name::Projector,
		new GraphicsObject_Sprite(ImageName::Name::Projector, Rect(0, 0, 10, 10))
	)
{
	this->ManagedNoDelete = true;
}

Projector::~Projector()
{

}

void Projector::SetPosAng(float pixx, float pixy, float ang)
{
	this->SetPos(pixx, pixy);
	this->SetCurrentAngle(ang);
}


void Projector::ManagedSceneExit()
{
	pPool->Recycle(this);
}
