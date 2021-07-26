#include "GameObjectMan.h"
#include "TowerFactory.h"
#include "Wood.h"
#include "Glass.h"
#include "Stone.h"
#include "KingPig.h"
#include "CorporalPig.h"
#include "MinionPig.h"
#include "ForemanPig.h"
#include "CollisionObjectBox.h"
#include "CollisionObjectCircle.h"

TowerFactory::TowerFactory()
{
}

TowerFactory::~TowerFactory()
{

}

void TowerFactory::CreateTowerBucket()
{
	GameSortBucket* pSortBucket = new GameSortBucket(GameObjectName::Name::TowerBucket);
	// add to game manager
	GameObjectMan::Add(pSortBucket);
	pSortBucket->setName("TowerBucket");
}


GameObject2D* TowerFactory::CreateTowerElement(GameObjectName::Name newName, Rect newRect, Rect debugRect, bool phyObject)
{
	// GameObject2D 
	GameObject2D* pNewObj = nullptr;
	// Graphics Sprite
	GraphicsObject_Sprite* pGraphics_Sprite = nullptr;

	// take debug sprite from sprite size if not mentioned.
	debugRect == Rect(0.0f, 0.0f, 0.0f, 0.0f) ? debugRect = newRect : debugRect;

	switch (newName)
	{
	case GameObjectName::Name::TowerPlatform:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::TowerPlatform, newRect);
		pNewObj = new GameObject2D(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("TowerPlatform");
		break;
	case GameObjectName::Name::WoodPlatform0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodPlatform0, newRect);
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("WoodPlatform0");
		break;
	case GameObjectName::Name::WoodPlatform1:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodPlatform1, newRect);
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("WoodPlatform1");
		break;
	case GameObjectName::Name::WoodPlatform2:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodPlatform2, newRect);
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("WoodPlatform2");
		break;
	case GameObjectName::Name::WoodPlatform3:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodPlatform3, newRect);
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("WoodPlatform3");
		break;
	case GameObjectName::Name::WoodEquiTriangle0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodEquiTriangle0, newRect);
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("WoodEquiTriangle0");
		break;
	case GameObjectName::Name::WoodSquare0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodSquare0, newRect);
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("WoodSquare0");
		break;
	case GameObjectName::Name::StonePlatform0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::StonePlatform0, newRect);
		pNewObj = new Stone(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("StonePlatform0");
		break;
	case GameObjectName::Name::StonePlatform1:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::StonePlatform1, newRect);
		pNewObj = new Stone(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("StonePlatform1");
		break;
	case GameObjectName::Name::StonePlatform2:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::StonePlatform2, newRect);
		pNewObj = new Stone(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("StonePlatform2");
		break;
	case GameObjectName::Name::StonePlatform3:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::StonePlatform3, newRect);
		pNewObj = new Stone(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("StonePlatform3");
		break;
	case GameObjectName::Name::StoneCircle0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::StoneCircle0, newRect);
		pNewObj = new Stone(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("StoneCircle0");
		break;
	case GameObjectName::Name::GlassPlatform0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::GlassPlatform0, newRect);
		pNewObj = new Glass(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("GlassPlatform0");
		break;
	case GameObjectName::Name::GlassPlatform1:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::GlassPlatform1, newRect);
		pNewObj = new Glass(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("GlassPlatform1");
		break;
	case GameObjectName::Name::GlassPlatform2:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::GlassPlatform2, newRect);
		pNewObj = new Glass(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("GlassPlatform2");
		break;
	case GameObjectName::Name::GlassPlatform3:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::GlassPlatform3, newRect);
		pNewObj = new Glass(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("GlassPlatform3");
		break;
	case GameObjectName::Name::GlassCircle0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::GlassCircle0, newRect);
		pNewObj = new Glass(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("GlassCircle0");
		break;
	case GameObjectName::Name::CollisionObjectBox:
		pNewObj = new CollisionObjectBox(newName, new GraphicsObject_Box(debugRect));
		pNewObj->setName("CollisionObjectBox");
		break;
	case GameObjectName::Name::CollisionObjectCircle:
		pNewObj = new CollisionObjectCircle(newName, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("CollisionObjectCircle");
		break;
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
	pNewObj->SetBucketName(GameObjectName::Name::TowerBucket);
	// add to game object manager.
	GameObjectMan::Add(pNewObj, GameObjectName::Name::TowerBucket);

	// return instance
	return pNewObj;
}

TowerFactory* TowerFactory::privGetInstance()
{
	static TowerFactory pInstance;
	return &pInstance;;
}
