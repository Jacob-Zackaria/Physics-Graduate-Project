#include "GameObjectMan.h"
#include "SlingFactory.h"
#include "Sling.h"

SlingFactory::SlingFactory()
{
}

SlingFactory::~SlingFactory()
{

}

void SlingFactory::CreateSlingBucket1()
{
	GameSortBucket* pSortBucket = new GameSortBucket(GameObjectName::Name::SlingBucket1);
	// add to game manager
	GameObjectMan::Add(pSortBucket);
	pSortBucket->setName("SlingBucket1");
}

void SlingFactory::CreateSlingBucket2()
{
	GameSortBucket* pSortBucket = new GameSortBucket(GameObjectName::Name::SlingBucket2);
	// add to game manager
	GameObjectMan::Add(pSortBucket);
	pSortBucket->setName("SlingBucket2");
}


GameObject2D* SlingFactory::CreateObject(GameObjectName::Name newName, Rect newRect, Rect debugRect)
{
	// GameObject2D 
	GameObject2D* pNewObj = nullptr;
	// Graphics Sprite
	GraphicsObject_Sprite* pGraphics_Sprite = nullptr;

	// take debug sprite from sprite size if not mentioned.
	debugRect == Rect(0.0f, 0.0f, 0.0f, 0.0f) ? debugRect = newRect : debugRect;

	switch (newName)
	{
	case GameObjectName::Name::Sling1:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Sling, newRect);
		pNewObj = new Sling(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("Sling1");

		// add sort bucketName
		pNewObj->SetBucketName(GameObjectName::Name::SlingBucket1);
		// add to game object manager.
		GameObjectMan::Add(pNewObj, GameObjectName::Name::SlingBucket1);
		break;
	case GameObjectName::Name::Sling2:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Sling, newRect);
		pNewObj = new Sling(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("Sling2");

		// add sort bucketName
		pNewObj->SetBucketName(GameObjectName::Name::SlingBucket2);
		// add to game object manager.
		GameObjectMan::Add(pNewObj, GameObjectName::Name::SlingBucket2);
		break;
	case GameObjectName::Name::Sling_Stump0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Sling_Stump0, newRect);
		pNewObj = new Sling(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("SlingStump0");

		// add sort bucketName
		pNewObj->SetBucketName(GameObjectName::Name::SlingBucket2);
		// add to game object manager.
		GameObjectMan::Add(pNewObj, GameObjectName::Name::SlingBucket2);
		
		break;
	case GameObjectName::Name::Sling_Stump1:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Sling_Stump1, newRect);
		pNewObj = new Sling(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("Sling_Stump1");

		// add sort bucketName
		pNewObj->SetBucketName(GameObjectName::Name::SlingBucket1);
		// add to game object manager.
		GameObjectMan::Add(pNewObj, GameObjectName::Name::SlingBucket1);
		break;
	default:
		assert(false);
		break;
	}


	

	// return instance
	return pNewObj;
}

SlingFactory* SlingFactory::privGetInstance()
{
	static SlingFactory pInstance;
	return &pInstance;;
}
