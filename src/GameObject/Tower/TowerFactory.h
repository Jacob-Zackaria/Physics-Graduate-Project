#ifndef TOWER_FACTORY_H
#define TOWER_FACTORY_H

#include "GraphicsObject_Sprite.h"
#include "PhysicsManager.h"

class TowerFactory
{
public:
	TowerFactory(const TowerFactory&) = delete;
	const TowerFactory& operator = (const TowerFactory&) = delete;
	~TowerFactory();

	//----------------- PUBLIC STATIC FUNCTIONS-----------//
	// Create a sort bucket.
	static void CreateTowerBucket();
	// Create objects
	static GameObject2D* CreateTowerElement(GameObjectName::Name newName,
		Rect newRect, Rect debugRect = Rect(0.0f, 0.0f, 0.0f, 0.0f), bool phyObject = false);


private:
	TowerFactory();
	static TowerFactory* privGetInstance();
};


#endif TOWER_FACTORY_H 