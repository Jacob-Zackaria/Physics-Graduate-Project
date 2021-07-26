#include "MinionPig.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
#include "PhysicsManager.h"
MinionPig::~MinionPig()
{
	delete this->newAnim;
}

MinionPig::MinionPig(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle), impact(false)
{
	this->health = 50.0f;
	
	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::MinionPig4, 30.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::MinionPig6, 20.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::MinionPig8, 10.0f, graphicsObject->GetRect());
}

void MinionPig::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void MinionPig::CollideVisit(RedBird& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void MinionPig::CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void MinionPig::CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void MinionPig::CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void MinionPig::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void MinionPig::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void MinionPig::ReduceHealth(const float newVal)
{
	if (!this->impact)
	{
		b2JointEdge* newJointEdge = this->GetBody()->GetJointList();
		if (newJointEdge)
		{
			PhysicsManager::AddToDeleteJoint(newJointEdge->joint);
		}
		this->impact = true;
	}

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

