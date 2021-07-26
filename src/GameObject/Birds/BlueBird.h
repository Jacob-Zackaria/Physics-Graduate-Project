#ifndef BLUE_BIRD_H
#define BLUE_BIRD_H

#include "Bird.h"

class BlueBird : public Bird
{
public:
	BlueBird() = delete;
	BlueBird(const BlueBird&) = delete;
	const BlueBird& operator = (const BlueBird&) = delete;
	virtual ~BlueBird();
	BlueBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);
};

#endif BLUE_BIRD_H