#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include "GraphicsObject_Sprite.h"
#include "PhysicsManager.h"

class ObjectFactory
{
public:
	ObjectFactory(const ObjectFactory&) = delete;
	const ObjectFactory& operator = (const ObjectFactory&) = delete;
	~ObjectFactory();

	//----------------- PUBLIC STATIC FUNCTIONS-----------//
	// Create a sort bucket.
	static void CreateObjectBucket();
	// Create objects
	static GameObject2D* CreateObject(GameObjectName::Name newName,
		Rect newRect, Rect debugRect = Rect(0.0f, 0.0f, 0.0f, 0.0f), bool phyObject = false);


private:
	ObjectFactory();
	static ObjectFactory* privGetInstance();
};


#endif OBJECT_FACTORY_H 