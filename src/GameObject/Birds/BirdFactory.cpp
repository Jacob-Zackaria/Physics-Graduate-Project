#include "GameObjectMan.h"
#include "BirdFactory.h"
#include "RedBird.h"
#include "YellowBird.h"
#include "BlueBird.h"
#include "Bomb.h"
#include "BigBird.h"
#include "WhiteBird.h"
#include "GreenBird.h"

BirdFactory::BirdFactory()
{
}

BirdFactory::~BirdFactory()
{
	
}

GameObject2D* BirdFactory::CreateBirdBucket()
{
	GameSortBucket* pSortBucket = new GameSortBucket(GameObjectName::Name::BirdsBucket);
	// add to game manager
	GameObjectMan::Add(pSortBucket);
	pSortBucket->setName("BirdSortBucket");

	return pSortBucket;
}


GameObject2D* BirdFactory::CreateBird(GameObjectName::Name newName, Rect newRect, Rect debugRect, bool phyObject)
{
	// GameObject2D 
	GameObject2D* pNewObj = nullptr;
	// Graphics Sprite
	GraphicsObject_Sprite* pGraphics_Sprite = nullptr;

	// take debug sprite from sprite size if not mentioned.
	debugRect == Rect(0.0f, 0.0f, 0.0f, 0.0f) ? debugRect = newRect : debugRect;
	

	switch (newName)
	{
	case GameObjectName::Name::RedBird0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::RedBird0, newRect);
		pNewObj = new RedBird(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("RedBird0");
		break;
	case GameObjectName::Name::GreenBird0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::GreenBird0, newRect);
		pNewObj = new GreenBird(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("GreenBird0");
		break;
	case GameObjectName::Name::YellowBird0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::YellowBird0, newRect);
		pNewObj = new YellowBird(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("YellowBird0");
		break;
	case GameObjectName::Name::BlueBird0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::BlueBird0, newRect);
		pNewObj = new BlueBird(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("BlueBird0");
		break;
	case GameObjectName::Name::BombBird0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::BombBird0, newRect);
		pNewObj = new Bomb(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("BombBird0");
		break;
	case GameObjectName::Name::BigBird0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::BigBird0, newRect);
		pNewObj = new BigBird(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("BigBird0");
		break;
	case GameObjectName::Name::WhiteBird0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WhiteBird0, newRect);
		pNewObj = new WhiteBird(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("WhiteBird0");
		break;
	default:
		assert(false);
		break;
	}

	// Create associated Physics Object
	if (phyObject)
	{
		PhysicsObject* pPhyObj = PhysicsManager::CreatePhysicsObject(pNewObj, b2BodyType::b2_dynamicBody);
		pPhyObj->GetBody()->GetFixtureList()->SetRestitution(0.5f);
		pPhyObj->GetBody()->GetFixtureList()->SetFriction(0.5f);
		pNewObj->SetPhysicsObject(pPhyObj);
	}

	// add sort bucketName
	pNewObj->SetBucketName(GameObjectName::Name::BirdsBucket);

	// add to game object manager.
	GameObjectMan::Add(pNewObj, GameObjectName::Name::BirdsBucket);

	// return instance
	return pNewObj;
}



BirdFactory* BirdFactory::privGetInstance()
{
	static BirdFactory pInstance;
	return &pInstance;;
}
