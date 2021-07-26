#ifndef BIG_BIRD_H
#define BIG_BIRD_H

#include "Bird.h"

class BigBird : public Bird
{
public:
	BigBird() = delete;
	BigBird(const BigBird&) = delete;
	const BigBird& operator = (const BigBird&) = delete;
	virtual ~BigBird();
	BigBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);
	BigBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Box);
};

#endif BIG_BIRD_H