#include "GameObjectMan.h"
#include "ObjectFactory.h"
#include "Wood.h"
#include "Glass.h"
#include "Stone.h"
#include "Sling.h"
#include "Gear.h"
#include "Egg.h"
#include "SensorBox.h"
#include "CollisionObjectBox.h"
#include "CollisionObjectCircle.h"
#include "CollisionObjectTri.h"

ObjectFactory::ObjectFactory()
{
}

ObjectFactory::~ObjectFactory()
{

}

void ObjectFactory::CreateObjectBucket()
{
	GameSortBucket* pSortBucket = new GameSortBucket(GameObjectName::Name::ObjectsBucket);
	// add to game manager
	GameObjectMan::Add(pSortBucket);
	pSortBucket->setName("ObjectsBucket");
}


GameObject2D* ObjectFactory::CreateObject(GameObjectName::Name newName, Rect newRect, Rect debugRect, bool phyObject)
{
	// GameObject2D 
	GameObject2D* pNewObj = nullptr;
	// Graphics Sprite
	GraphicsObject_Sprite* pGraphics_Sprite = nullptr;

	// tri --------------
	float halfSpriteWidth = 0.0f;
	Vect2D* pixelVertices = nullptr;
	//-------------------
	
	// take debug sprite from sprite size if not mentioned.
	debugRect == Rect(0.0f, 0.0f, 0.0f, 0.0f) ? debugRect = newRect : debugRect;

	switch (newName)
	{
	case GameObjectName::Name::TowerPlatform:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::TowerPlatform, newRect);
		pNewObj = new GameObject2D(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("TowerPlatform");
		break;
	case GameObjectName::Name::Egg:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Egg, newRect);
		pNewObj = new Egg(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("TowerPlatform");
		break;
	case GameObjectName::Name::WoodPlatform0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodPlatform0, newRect);
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("WoodPlatform0");
		break;
	/*case GameObjectName::Name::WoodEquiTriangle0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodEquiTriangle0, newRect);
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Tri(Vect2D(debugRect.x, debugRect.y), xx));
		pNewObj->setName("WoodEquiTriangle0");
		break;*/
	case GameObjectName::Name::WoodIsoTriangle0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::WoodIsoTriangle0, newRect);
		pixelVertices = new Vect2D[3];
		halfSpriteWidth = newRect.width * 0.5f;
		// supply vertices (as offsets from the center) in a counter clockwise fashion
		pixelVertices[0] = Vect2D(-halfSpriteWidth, -halfSpriteWidth);	// bottom left corner
		pixelVertices[1] = Vect2D(+halfSpriteWidth, -halfSpriteWidth);	// bottom right corner
		pixelVertices[2] = Vect2D(-halfSpriteWidth, +halfSpriteWidth);	// top left corner
		pNewObj = new Wood(newName, pGraphics_Sprite, new GraphicsObject_Tri(Vect2D(0.0f, 0.0f), pixelVertices));
		pNewObj->setName("WoodIsoTriangle0");
		delete[] pixelVertices;
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
	case GameObjectName::Name::StoneSmallSquare0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::StoneSmallSquare0, newRect);
		pNewObj = new Stone(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("StoneSmallSquare0");
		break;
	case GameObjectName::Name::GlassPlatform0:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::GlassPlatform0, newRect);
		pNewObj = new Glass(newName, pGraphics_Sprite, new GraphicsObject_Box(debugRect));
		pNewObj->setName("GlassPlatform0");
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
	case GameObjectName::Name::SensorBox:
		pNewObj = new SensorBox(newName, new GraphicsObject_Box(debugRect));
		pNewObj->setName("SensorBox");
		break;
	case GameObjectName::Name::CollisionObjectCircle:
		pNewObj = new CollisionObjectCircle(newName, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("CollisionObjectCircle");
		break;
	/*case GameObjectName::Name::CollisionObjectTri:
		pNewObj = new CollisionObjectTri(newName, new GraphicsObject_Tri(Vect2D(debugRect.x, debugRect.y), ));
		pNewObj->setName("CollisionObjectTri");
		break;*/
	case GameObjectName::Name::Gear1:
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Name::Gear1, newRect);
		pNewObj = new Gear(newName, pGraphics_Sprite, new GraphicsObject_Circle(debugRect));
		pNewObj->setName("Gear1");
		break;
	/*case GameObjectName::Name::CollisionObjectEdge:
		pNewObj = new CollisionObjectCircle(newName, new GraphicsObject_Edge(debugRect));
		pNewObj->setName("CollisionObjectCircle");
		break;*/
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
	pNewObj->SetBucketName(GameObjectName::Name::ObjectsBucket);
	// add to game object manager.
	GameObjectMan::Add(pNewObj, GameObjectName::Name::ObjectsBucket);

	// return instance
	return pNewObj;
}

ObjectFactory* ObjectFactory::privGetInstance()
{
	static ObjectFactory pInstance;
	return &pInstance;;
}
