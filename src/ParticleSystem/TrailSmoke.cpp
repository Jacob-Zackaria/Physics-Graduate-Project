#include "TrailSmoke.h"
#include "ManagedPool.h"
#include "GameObjectMan.h"

TrailSmoke::TrailSmoke(ManagedPool* pool)
	: pPool(pool),
	GameObject2D(
		GameObjectName::Name::Trail,
		new GraphicsObject_Sprite(ImageName::Name::Trail, Rect(0, 0, 15, 15))
	)
{
	this->ManagedNoDelete = true;
}

TrailSmoke::~TrailSmoke()
{

}

void TrailSmoke::SetPosAng(float pixx, float pixy, float ang)
{
	this->SetPos(pixx, pixy);
	this->SetCurrentAngle(ang);
}


void TrailSmoke::ManagedSceneExit()
{
	pPool->Recycle(this);
}
