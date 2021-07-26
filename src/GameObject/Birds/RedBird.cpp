#include "RedBird.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
RedBird::~RedBird()
{
	delete this->newAnim;
}

RedBird::RedBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle)
{
	this->health = 300.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::RedBird1, 200.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::RedBird2, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::RedBird3, 50.0f, graphicsObject->GetRect());
}

void RedBird::Update(float t)
{
	if(!this->GetBody()->IsAwake() && !this->markedDead)
	{
		// if impact and body is not awake, kill bird after 3 sec.
		TimerMan::AddEvent(3.0f, new BirdDeath(this));
		this->markedDead = true;
	}

	// call update on base bird
	Bird::Update(t);
}

void RedBird::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void RedBird::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void RedBird::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void RedBird::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void RedBird::CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	pContact;
	pImpulse;
	other;
}

void RedBird::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void RedBird::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void RedBird::ReduceHealth(const float newVal)
{
	if (this->damagable && !this->markedDead)
	{
		this->health -= newVal;
		if (this->health <= 0.0f)
		{
			this->health = 0.0f;
			TimerMan::AddEvent(3.0f, new BirdDeath(this));

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



