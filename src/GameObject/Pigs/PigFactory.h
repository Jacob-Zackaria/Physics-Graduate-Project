#ifndef PIG_FACTORY_H
#define PIG_FACTORY_H

#include "GraphicsObject_Sprite.h"
#include "PhysicsManager.h"

class PigFactory
{
public:
	PigFactory(const PigFactory&) = delete;
	const PigFactory& operator = (const PigFactory&) = delete;
	~PigFactory();

	//----------------- PUBLIC STATIC FUNCTIONS-----------//
	// Create a sort bucket.
	static void CreatePigBucket();
	// Create pigs
	static GameObject2D* CreatePig(GameObjectName::Name newName,
		Rect newRect, Rect debugRect = Rect(0.0f, 0.0f, 0.0f, 0.0f), bool phyObject = false);


private:
	PigFactory();
	static PigFactory* privGetInstance();
};


#endif PIG_FACTORY_H 