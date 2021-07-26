#include "CircleParticles.h"
#include "ManagedPool.h"
#include "GameObjectMan.h"

CircleParticles::CircleParticles(ManagedPool* pool)
	: pPool(pool),
	GameObject2D(
		GameObjectName::Name::GlassCircle0,
		new GraphicsObject_Sprite(ImageName::Name::GlassCircle0, Rect(0, 0, 5, 5)), DEBUG_SHAPE::Circle
	)
{
	this->ManagedNoDelete = true;
}

CircleParticles::~CircleParticles()
{

}

void CircleParticles::SetPosAng(float pixx, float pixy, float ang)
{
	this->SetPos(pixx, pixy);
	this->SetCurrentAngle(ang);
}


void CircleParticles::ManagedSceneExit()
{
	pPool->Recycle(this);
}
