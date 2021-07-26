#ifndef BOMB_H
#define BOMB_H

#include "Bird.h"

class Bomb : public Bird
{
public:
	Bomb() = delete;
	Bomb(const Bomb&) = delete;
	const Bomb& operator = (const Bomb&) = delete;
	virtual ~Bomb();
	Bomb(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);
};

#endif BOMB_H