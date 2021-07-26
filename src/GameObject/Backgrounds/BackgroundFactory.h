#ifndef BACKGROUND_FACTORY_H
#define BACKGROUND_FACTORY_H

#include "GraphicsObject_Sprite.h"

class BackgroundFactory
{
public:
	BackgroundFactory(const BackgroundFactory&) = delete;
	const BackgroundFactory& operator = (const BackgroundFactory&) = delete;
	~BackgroundFactory();

	//----------------- PUBLIC STATIC FUNCTIONS-----------//
	// Create a sort bucket.
	static GameObject2D* CreateBackgroundBucket();
	// Create background
	static GameObject2D* CreateBackground(GameObjectName::Name newName,
		Rect newRect);


private:
	BackgroundFactory();
	static BackgroundFactory* privGetInstance();
};


#endif BACKGROUND_FACTORY_H 