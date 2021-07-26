#include "KingPig.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
KingPig::~KingPig()
{
	delete this->newAnim;
}

KingPig::KingPig(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle)
{
	this->health = 150.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::KingPig4, 120.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::KingPig6, 60.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::KingPig8, 30.0f, graphicsObject->GetRect());
}

void KingPig::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void KingPig::CollideVisit(RedBird& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void KingPig::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void KingPig::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void KingPig::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void KingPig::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void KingPig::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void KingPig::ReduceHealth(const float newVal)
{
	if (this->damagable && !this->markedDead)
	{
		this->health -= newVal;
		if (this->health <= 0.0f)
		{
			this->health = 0.0f;
			TimerMan::AddEvent(0.1f, new BirdDeath(this));

			this->markedDead = true;

		}
		else if (this->newAnim->GetLink())
		{
			if (this->health < this->newAnim->GetHealthVal())
			{
				this->SwapImage(this->newAnim->GetSprite());
				this->newAnim->SetNextLink();
			}
		}
	}
}



