#include "YellowBird.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
#include "InputManager.h"
YellowBird::~YellowBird()
{
	delete this->newAnim;
}

YellowBird::YellowBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	Bird(name, graphicsObject, graphicsObject_Circle), punchMode(false)
{
	this->health = 300.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::YellowBird1, 200.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::YellowBird3, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::YellowBird5, 50.0f, graphicsObject->GetRect());
}

void YellowBird::Update(float t)
{
	if (!this->GetBody()->IsAwake() && !this->markedDead)
	{
		// if impact and body is not awake, kill bird after 3 sec.
		TimerMan::AddEvent(3.0f, new BirdDeath(this));
		this->markedDead = true;
	}

	// Punch through effect
	if ((this->bState == BirdState::FLYING) && (!this->punchMode) && (InputManager::GetMouseState() == InputManager::MouseState::LEFT))
	{
		this->punchMode = true;
		b2Vec2 imp = 15.0f * this->GetBody()->GetLinearVelocity();
		Rect newRect = ((GraphicsObject_Sprite*)this->getGraphicsObject())->GetRect();
		newRect.width += 10.0f;
		this->SwapImage(new GraphicsObject_Sprite(ImageName::Name::YellowBird4, newRect));
		this->GetBody()->ApplyLinearImpulse(imp, this->GetBody()->GetWorldCenter(), true);
	}


	// call update on base bird
	Bird::Update(t);
}

void YellowBird::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void YellowBird::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void YellowBird::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void YellowBird::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void YellowBird::CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	pContact;
	pImpulse;
	other;
}

void YellowBird::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void YellowBird::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	this->bState = BirdState::IMPACT;
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void YellowBird::ReduceHealth(const float newVal)
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
