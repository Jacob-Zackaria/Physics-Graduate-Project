#ifndef EFFECT_FACTORY_H
#define EFFECT_FACTORY_H

#include "GraphicsObject_Sprite.h"
#include "PhysicsManager.h"

class EffectFactory
{
public:
	EffectFactory(const EffectFactory&) = delete;
	const EffectFactory& operator = (const EffectFactory&) = delete;
	~EffectFactory();

	//----------------- PUBLIC STATIC FUNCTIONS-----------//
	// Create a sort bucket.
	static void CreateEffectBucket();
	// Create effects
	static GameObject2D* CreateEffect(GameObjectName::Name newName,
		Rect newRect, Rect debugRect = Rect(0.0f, 0.0f, 0.0f, 0.0f), bool phyObject = false);


private:
	EffectFactory();
	static EffectFactory* privGetInstance();

};


#endif EFFECT_FACTORY_H 