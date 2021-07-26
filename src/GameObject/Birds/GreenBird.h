#ifndef GREEN_BIRD_H
#define GREEN_BIRD_H

#include "Bird.h"

class GreenBird : public Bird
{
public:
	GreenBird() = delete;
	GreenBird(const GreenBird&) = delete;
	const GreenBird& operator = (const GreenBird&) = delete;
	virtual ~GreenBird();
	GreenBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);
};

#endif GREEN_BIRD_H