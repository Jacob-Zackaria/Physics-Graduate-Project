#include "GameObjectMan.h"
#include "EffectFactory.h"
#include "Effect.h"

EffectFactory::EffectFactory()
{
}

EffectFactory::~EffectFactory()
{

}

void EffectFactory::CreateEffectBucket()
{
	GameSortBucket* pSortBucket = new GameSortBucket(GameObjectName::Name::EffectsBucket);
	// add to game manager
	GameObjectMan::Add(pSortBucket);
	pSortBucket->setName("EffectsBucket");
}


GameObject2D* EffectFactory::CreateEffect(GameObjectName::Name newName, Rect newRect, Rect debugRect, bool phyObject)
{
	// GameObject2D 
	GameObject2D* pNewObj = nullptr;
	// Graphics Sprite
	GraphicsObject_Sprite* pGraphics_Sprite = nullptr;

	// take debug sprite from sprite size if not mentioned.
	debugRect == Rect(0.0f, 0.0f, 0.0f, 0.0f) ? debugRect = newRect : debugRect;


	switch (newName)
	{
	case GameObjectName::Name::Bang:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Bang, newRect);
		pNewObj = new Effect(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("Bang");
		break;
	case GameObjectName::Name::Smoke:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Smoke, newRect);
		pNewObj = new Effect(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("Smoke");
		break;
	case GameObjectName::Name::Flame:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Flame, newRect);
		pNewObj = new Effect(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("Flame");
		break;
	default:
		assert(false);
		break;
	}

	// Create associated Physics Object
	if (phyObject)
	{
		PhysicsObject* pPhyObj = PhysicsManager::CreatePhysicsObject(pNewObj, b2BodyType::b2_staticBody);
		pNewObj->SetPhysicsObject(pPhyObj);
	}

	// add sort bucketName
	pNewObj->SetBucketName(GameObjectName::Name::EffectsBucket);
	// add to game object manager.
	GameObjectMan::Add(pNewObj, GameObjectName::Name::EffectsBucket);

	// return instance
	return pNewObj;
}


EffectFactory* EffectFactory::privGetInstance()
{
	static EffectFactory pInstance;
	return &pInstance;;
}
