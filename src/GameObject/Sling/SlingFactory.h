#ifndef SLING_FACTORY_H
#define SLING_FACTORY_H


#include "GraphicsObject_Sprite.h"
#include "PhysicsManager.h"

class SlingFactory
{
public:
	SlingFactory(const SlingFactory&) = delete;
	const SlingFactory& operator = (const SlingFactory&) = delete;
	~SlingFactory();

	//----------------- PUBLIC STATIC FUNCTIONS-----------//
	// Create a sort bucket.
	static void CreateSlingBucket1();
	static void CreateSlingBucket2();
	// Create objects
	static GameObject2D* CreateObject(GameObjectName::Name newName,
		Rect newRect, Rect debugRect = Rect(0.0f, 0.0f, 0.0f, 0.0f));


private:
	SlingFactory();
	static SlingFactory* privGetInstance();
};


#endif SLING_FACTORY_H 