#include "GameObjectMan.h"
#include "PigFactory.h"
#include "MinionPig.h"
#include "KingPig.h"
#include "CorporalPig.h"
#include "ForemanPig.h"

PigFactory::PigFactory()
{
}

PigFactory::~PigFactory()
{

}

void PigFactory::CreatePigBucket()
{
	GameSortBucket* pSortBucket = new GameSortBucket(GameObjectName::Name::PigsBucket);
	// add to game manager
	GameObjectMan::Add(pSortBucket);
	pSortBucket->setName("PigSortBucket");
}


GameObject2D* PigFactory::CreatePig(GameObjectName::Name newName, Rect newRect, Rect debugRect, bool phyObject)
{
	// GameObject2D 
	GameObject2D* pNewObj = nullptr;
	// Graphics Sprite
	GraphicsObject_Sprite* pGraphics_Sprite = nullptr;

	// take debug sprite from sprite size if not mentioned.
	debugRect == Rect(0.0f, 0.0f, 0.0f, 0.0f) ? debugRect = newRect : debugRect;


	switch (newName)
	{
	case GameObjectName::Name::KingPig0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::KingPig0, newRect);
		pNewObj = new KingPig(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("KingPig0");
		break;
	case GameObjectName::Name::ForemanPig0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::ForemanPig0, newRect);
		pNewObj = new ForemanPig(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("ForemanPig0");
		break;
	case GameObjectName::Name::MinionPig0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::MinionPig0, newRect);
		pNewObj = new MinionPig(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("MinionPig0");
		break;
	case GameObjectName::Name::CorporalPig0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::CorporalPig0, newRect);
		pNewObj = new CorporalPig(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("CorporalPig0");
		break;
	default:
		assert(false);
		break;
	}

	// Create associated Physics Object
	if (phyObject)
	{
		PhysicsObject* pPhyObj = PhysicsManager::CreatePhysicsObject(pNewObj, b2BodyType::b2_dynamicBody);
		pNewObj->SetPhysicsObject(pPhyObj);
	}

	// add sort bucketName
	pNewObj->SetBucketName(GameObjectName::Name::PigsBucket);
	// add to game object manager.
	GameObjectMan::Add(pNewObj, GameObjectName::Name::PigsBucket);

	// return instance
	return pNewObj;
}

PigFactory* PigFactory::privGetInstance()
{
	static PigFactory pInstance;
	return &pInstance;;
}
