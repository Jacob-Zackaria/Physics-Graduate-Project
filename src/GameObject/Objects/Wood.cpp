#include "Wood.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
#include "SceneManager.h"
#include "SmokeDeletion.h"
#include "EffectFactory.h"
Wood::~Wood()
{
	delete this->newAnim;
}

Wood::Wood(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle)
{
	this->health = 250.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::WoodPlatform1, 200.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::WoodPlatform2, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::WoodPlatform3, 50.0f, graphicsObject->GetRect());
}

Wood::Wood(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Tri* graphicsObject_Tri)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Tri)
{
	this->health = 250.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::WoodPlatform1, 200.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::WoodPlatform2, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::WoodPlatform3, 50.0f, graphicsObject->GetRect());
}

void Wood::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	 other.CollideVisit(*this, contact, pimpulse); 
}

void Wood::CollideVisit(RedBird& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void Wood::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void Wood::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void Wood::ReduceHealth(const float newVal)
{
	if (this->damagable && !this->markedDead)
	{
		this->health -= newVal;
		if (this->health <= 0.0f)
		{
			this->health = 0.0f;

			Rect rect = Rect(this->GetPosX(), this->GetPosY(), 35.0f, 35.0f);
			SmokeDeletion* newEvent = new SmokeDeletion(EffectFactory::CreateEffect(GameObjectName::Name::Smoke, rect));
			TimerMan::AddEvent(0.1f, newEvent);
			SceneManager::DeleteSceneObject(SceneManager::GetCurrentScene(), this);

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


