#ifndef BIRD_FACTORY_H
#define BIRD_FACTORY_H

#include "GraphicsObject_Sprite.h"
#include "PhysicsManager.h"

class BirdFactory
{
public:
	BirdFactory(const BirdFactory&) = delete;
	const BirdFactory& operator = (const BirdFactory&) = delete;
	~BirdFactory();

	//----------------- PUBLIC STATIC FUNCTIONS-----------//
	// Create a sort bucket.
	static GameObject2D* CreateBirdBucket();
	// Create birds
	static GameObject2D* CreateBird(GameObjectName::Name newName,
		Rect newRect, Rect debugRect = Rect(0.0f, 0.0f, 0.0f, 0.0f), bool phyObject = false);

	
private:
	BirdFactory();
	static BirdFactory* privGetInstance();

};


#endif BIRD_FACTORY_H