#include "GameObjectMan.h"
#include "BackgroundFactory.h"
#include "Background.h"

BackgroundFactory::BackgroundFactory()
{
}

BackgroundFactory::~BackgroundFactory()
{

}

GameObject2D* BackgroundFactory::CreateBackgroundBucket()
{
	GameSortBucket* pSortBucket = new GameSortBucket(GameObjectName::Name::BGBucket);
	// add to game manager
	GameObjectMan::Add(pSortBucket);
	pSortBucket->setName("BackgroundBucket");

	return pSortBucket;
}


GameObject2D* BackgroundFactory::CreateBackground(GameObjectName::Name newName, Rect newRect)
{
	// GameObject2D 
	GameObject2D* pNewObj = nullptr;
	// Graphics Sprite
	GraphicsObject_Sprite* pGraphics_Sprite = nullptr;


	switch (newName)
	{
	case GameObjectName::Name::Background:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Background, newRect);
		pNewObj = new Background(newName, pGraphics_Sprite);
		pNewObj->setName("Background");
		break;
	case GameObjectName::Name::Space:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Space, newRect);
		pNewObj = new Background(newName, pGraphics_Sprite);
		pNewObj->setName("Space");
		break;
	case GameObjectName::Name::Space2:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Space2, newRect);
		pNewObj = new Background(newName, pGraphics_Sprite);
		pNewObj->setName("Space2");
		break;
	case GameObjectName::Name::Space3:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Space3, newRect);
		pNewObj = new Background(newName, pGraphics_Sprite);
		pNewObj->setName("Space3");
		break;
	case GameObjectName::Name::Space4:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Space4, newRect);
		pNewObj = new Background(newName, pGraphics_Sprite);
		pNewObj->setName("Space4");
		break;
	default:
		assert(false);
		break;
	}

	// add sort bucketName
	pNewObj->SetBucketName(GameObjectName::Name::BGBucket);
	// add to game object manager.
	GameObjectMan::Add(pNewObj, GameObjectName::Name::BGBucket);

	// return instance
	return pNewObj;
}



BackgroundFactory* BackgroundFactory::privGetInstance()
{
	static BackgroundFactory pInstance;
	return &pInstance;;
}
