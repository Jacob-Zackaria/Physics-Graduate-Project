#ifndef EFFECT_H
#define EFFECT_H

#include "GameObject2D.h"

class Effect : public GameObject2D
{
public:
	Effect() = delete;
	Effect(const Effect&) = delete;
	const Effect& operator = (const Effect&) = delete;
	~Effect();
	Effect(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle);
	Effect(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

};

#endif EFFECT_H