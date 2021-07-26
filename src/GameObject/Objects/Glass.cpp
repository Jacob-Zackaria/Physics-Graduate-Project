#include "Glass.h"
#include "ContactAction.h"
#include "BirdDeath.h"
#include "TimerMan.h"
#include "SceneManager.h"
#include "SmokeDeletion.h"
#include "EffectFactory.h"
Glass::~Glass()
{
	delete this->newAnim;
}

Glass::Glass(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle)
{
	this->health = 150.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::GlassPlatform1, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::GlassPlatform2, 50.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::GlassPlatform3, 20.0f, graphicsObject->GetRect());
}

Glass::Glass(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle)
{
	this->health = 150.0f;

	this->newAnim = new Animation();
	this->newAnim->Add(ImageName::Name::GlassPlatform1, 100.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::GlassPlatform2, 50.0f, graphicsObject->GetRect());
	this->newAnim->Add(ImageName::Name::GlassPlatform3, 20.0f, graphicsObject->GetRect());
}

void Glass::CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse)
{
	other.CollideVisit(*this, contact, pimpulse);
}

void Glass::CollideVisit(RedBird& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void Glass::CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void Glass::CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void Glass::CollideVisit(SensorBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void Glass::ReduceHealth(const float newVal)
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


