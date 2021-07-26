#include "FeatherBlue.h"
#include "ManagedPool.h"
#include "GameObjectMan.h"

FeatherBlue::FeatherBlue(ManagedPool* pool)
	: pPool(pool),
	speedx(0.0f),
	speedy(0.0f),
	GameObject2D(
		GameObjectName::Name::FeatherBlue,
		new GraphicsObject_Sprite(ImageName::Name::FeatherBlue, Rect(0, 0, 15, 45))
	)
{

	this->ManagedNoDelete = true;

	ScaleFactor = .97f;
	this->speedang = .1f;
	this->speedMag = .51f;
}

FeatherBlue::~FeatherBlue()
{

}

void FeatherBlue::Update(float t)
{
	this->posX += speedx;
	this->posY += speedy;
	this->currAngle += speedang;
	this->scaleX *= ScaleFactor;
	this->scaleY *= ScaleFactor;

	if (this->scaleX <= .1f)
	{
		this->MarkForDelete();
	}

	GameObject2D::Update(t);
}

void FeatherBlue::SetPosAng(float pixx, float pixy)
{
	this->SetPos(pixx, pixy);

	// randomize direction
	float ang = (rand() % 360) * MATH_PI_180;
	Matrix Rot(ROT_Z, ang);
	Vect dir = speedMag * Vect(1,0,0) * Rot;

	// Note: Non-physical movement!  Much cheaper!
	this->SetCurrentAngle(ang);
	this->speedx = dir[x];
	this->speedy = dir[y];

	this->scaleX = 1;
	this->scaleY = 1;
}


void FeatherBlue::ManagedSceneExit()
{
	pPool->Recycle(this);
}
